/* iowin32.h -- IO base function header for compress/uncompress .zip 
   files using zlib + zip or unzip API
   This IO API version uses the Win32 API (for Microsoft Windows)

   Version 0.18 beta, Feb 26th, 2002

   Copyright (C) 1998-2002 Gilles Vollant
*/


void fill_win32_filefunc OF((zlib_filefunc_def* pzlib_filefunc_def));
