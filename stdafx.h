// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <crtdbg.h>
#include <iostream>
#include <stdint.h>
#include <strsafe.h>
#include <Windows.h>


void print(_In_ const char* fmt, _In_ ...);
bool is_file_existsW(_In_ const wchar_t* file_path);
wchar_t* get_current_directory(void);
