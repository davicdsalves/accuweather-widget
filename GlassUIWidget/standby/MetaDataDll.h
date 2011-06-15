#pragma once
typedef struct METADATA_DLL_DATA
{
  wchar_t * dll_name; // required for UnLoadDLL
  
 /**
 * Get current playing item's track path and name.
 *
 * @param[in] data         		 
 * @param[in] bk			   The pointer to audio player book        		 
 * @param[in] ChipID           The ChipID of device
 * @param[out] fpath           The path of current playing item
 * @param[out] fname           The name of current playing item with extension
 */ 
  void (*GetCurrent_Track)(METADATA_DLL_DATA *data, BOOK *bk, int ChipID, wchar_t *fpath, wchar_t *fname);
  
 /**
 * Get current playing track's metadata.
 * If title metadata is missing, the filename (without path and extension) is given as title instead.
 * If artist, album, year and genre metadata is missing, return as unknown
 *
 * @param[in] data 
 * @param[in] fpath            The path of current playing item
 * @param[in] fname            The name of current playing item with extension
 * @param[out] title           The title metadata
 * @param[out] artist          The artist metadata
 * @param[out] album           The album metadata
 * @param[out] year            The year metadata
 * @param[out] genre           The genre metadata
 *
 */ 
  void (*GetTrack_FullInfo)(METADATA_DLL_DATA *data, wchar_t *fpath, wchar_t *fname, int ChipID, wchar_t *title, wchar_t *artist, wchar_t *album, wchar_t *year, wchar_t *genre);
  
 /**
 * Get current playing track's extra info.
 *
 * @param[in] data         		 
 * @param[in] bk			   The pointer to audio player book        		 
 * @param[in] ChipID           The ChipID of device
 * @param[in] fpath            The path of current playing item
 * @param[in] fname            The name of current playing item with extension
 * @param[out] Fulltime        The item's play length
 * @param[out] Frequency       The item's frequency
 * @param[out] Bitrate         The item's birate
 * @param[out] SongMode        The item's song mode
 *
 */ 
  void (*GetTrack_ExtraInfo)(METADATA_DLL_DATA *data, BOOK *bk, int ChipID, wchar_t *fpath, wchar_t *fname, int *FullTime, int *Frequency, int *Bitrate, int *SongMode);


#ifdef DLL_PRIVATE_AREA
#include "MetaDataDll_private.h"
#endif

}_METADATA_DLL_DATA;



#define METADATA_GetCurrent_Track(__this__,...) __this__->GetCurrent_Track(__this__,__VA_ARGS__)
#define METADATA_GetTrack_FullInfo(__this__,...) __this__->GetTrack_FullInfo(__this__,__VA_ARGS__)
#define METADATA_GetTrack_ExtraInfo(__this__,...) __this__->GetTrack_ExtraInfo(__this__,__VA_ARGS__)
