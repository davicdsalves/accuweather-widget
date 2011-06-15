//<!--includes
#include "..\include\Lib_Clara.h"
#include "..\include\Dir.h"
#include "..\include\cfg_items.h"
#include "standby\standbyDraw.h"
#include "bcfg\conf_loader.h"
#include "bcfg\config_data.h"
#include "mybook.h"
//#include "..\deleaker\mem2.h"
//-->

#define ELF_BCFG_CONFIG_EVENT 994

//<!-- bcfg support
int onBcfgConfig(void* mess,BOOK* b)
{
  FSTAT _fstat;
  wchar_t path[0x256];
  
  if(fstat(GetDir(DIR_ELFS|MEM_INTERNAL),L"BcfgEdit.elf",&_fstat)==0)
  {
    wstrcpy(path,GetDir(DIR_ELFS|MEM_INTERNAL));
  }
  else if(fstat(GetDir(DIR_ELFS|MEM_EXTERNAL),L"BcfgEdit.elf",&_fstat)==0)
  {
    wstrcpy(path,GetDir(DIR_ELFS|MEM_EXTERNAL));
  }
  else
  {
    MessageBox(0x6FFFFFFF, STR("BcfgEdit.elf not found!"), 0, 1 ,5000, 0);
    return (1);
  }
  wstrcat(path,L"/BcfgEdit.elf");
  elfload(path,(void*)successed_config_path,(void*)successed_config_name,0);
  return (1);
}

//-->

//<!--Book Manager Functions


int TerminateElf(void* ,BOOK* book){
  FreeBook(book);
  return(1);
}

typedef struct{
  BOOK* book;
}MSG;

int ShowAuthorInfo(void* mess ,BOOK* book){
  MSG* msg = (MSG*)mess;
  MessageBox(0x6FFFFFFF,STR("GlassUIWidget \n© tRaDuZ"), NOIMAGE, 1, 0,msg->book);
  return(1);
}

const PAGE_MSG BElf_PageEvents[]@ "DYN_PAGE" ={
  SBY_REDRAW_RELEASE_EVENT  , SB_ELF_Killed,
  ELF_TERMINATE_EVENT , TerminateElf,
  ELF_SHOW_INFO_EVENT  , ShowAuthorInfo,
  ELF_RECONFIG_EVENT,      ReconfigElf,
  ELF_BCFG_CONFIG_EVENT,   onBcfgConfig,
  0,0
};

PAGE_DESC base_page ={"HW_BasePage",0,BElf_PageEvents};


void elf_exit(void){
//  trace_done();
  kill_data(&ELF_BEGIN, (void(*)(void*))mfree_adr());
}

//-->

int myFind (BOOK * book) {
  if (!strcmp (book-> xbook-> name, "GlassUIWidget")) return (1);
  return (0);
}

int main (void){
  if (FindBook(myFind)) {
    MessageBox(0x6FFFFFFF,STR("GlassUIWidget is already runing!"), NOIMAGE, 1, 0,0);
    SUBPROC(elf_exit);
  }
  else {
//    trace_init();
    
    InitConfig();
    
    MyBook* BEBook = new MyBook();
    
    CreateBook(BEBook->getBook(),onCloseBEBook,&base_page,"GlassUIWidget",-1,0);
    
    drawWeatherInfo(BEBook);
  }
  return(0);
}
//http://weather.joeearl.co.uk/
