#include "..\..\include\Lib_Clara.h"
#include "..\..\include\Dir.h"
#include "..\..\include\cfg_items.h"
#include "..\bcfg\config_data.h"
#include "..\utils\weather.h"
#include "..\utils\utils.h"
#include "..\mybook.h"
#include "..\debug.h"
#include "id3.h"
#include "MetaDataDll.h"
#include "standbyDraw.h"

MyBook* _mybook;
//ifDrawNoMask(bool contentIf, wchar_t* message, int fontSize, int align, int x, int y, unsigned int color);
//drawOnStby(wchar_t* message, int fontSize, int align, int x, int y, int textColor )
void drawId3(MyBook* mybook) {
  _mybook = mybook;
  wchar_t trackPath[0x256] , fileName[0x256] , songTitle[0x256], songArtist[0x256], songAlbum[0x256], songYear[0x256], songGenre[0x256];
  memset( trackPath, 0, sizeof(wchar_t)*256);   memset( fileName, 0, sizeof(wchar_t)*256);   memset( songTitle, 0, sizeof(wchar_t)*256);
    memset( songArtist, 0, sizeof(wchar_t)*256);   memset( songAlbum, 0, sizeof(wchar_t)*256);   memset( songYear, 0, sizeof(wchar_t)*256);
      memset( songGenre, 0, sizeof(wchar_t)*256);
  int fullTime = 0, frequency = 0, bitRate = 0, songMode = 0;
  dbtf("geting track info");
  METADATA_GetCurrent_Track(_mybook->metadataDll, FindBook(get_IsAudioPlayerBook()) , GetChipID()&CHIPID_MASK, trackPath, fileName);
  METADATA_GetTrack_FullInfo(_mybook->metadataDll, trackPath, fileName, GetChipID()&CHIPID_MASK, songTitle, songArtist, songAlbum, songYear, songGenre);
  METADATA_GetTrack_ExtraInfo(_mybook->metadataDll, FindBook(get_IsAudioPlayerBook()), GetChipID()&CHIPID_MASK, trackPath, fileName,
                              &fullTime, &frequency, &bitRate, &songMode );
  ifDrawNoMask( BCFG_Music_Artist_Enable, songArtist, BCFG_Music_Artist_FontSize, BCFG_Music_Artist_Align,
               BCFG_Music_Artist_Position_X, BCFG_Music_Artist_Position_Y, BCFG_Music_Artist_TextColor );
  
  ifDrawNoMask( BCFG_Music_Title_Enable, songTitle, BCFG_Music_Title_FontSize, BCFG_Music_Title_Align,
               BCFG_Music_Title_Position_X, BCFG_Music_Title_Position_Y, BCFG_Music_Title_TextColor );
}

