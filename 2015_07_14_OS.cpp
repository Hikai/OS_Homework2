// 2015_07_14_OS.cpp : Defines the entry point for the console application.
//

#include "FileIoHelperClass.h"
#include "stdafx.h"
#include "StopWatch.h"
#include "mmio.h"
#include <conio.h>
#include <stdint.h>


int _tmain(int argc, _TCHAR* argv[])
{
	LARGE_INTEGER fileIOSize;
	fileIOSize.QuadPart = 3221225472;

	_ASSERTE(create_very_big_file(L"big_4MB.txt", 4));

	StopWatch sw;
	sw.Start();
	_ASSERTE(file_copy_using_read_write(L"big_4MB.txt", L"big_ReadWrite.txt"));
	sw.Stop();
	print("info] Read_Write time elapsed = %f", sw.GetDurationSecond());

	StopWatch sw2;
	sw2.Start();
	_ASSERTE(file_copy_using_memory_map(L"big_4MB.txt", L"big_MMIO.txt"));
	sw2.Stop();
	print("info] MMIO time elapsed = %f", sw2.GetDurationMilliSecond());


	FileIoHelper * fileIO;
	fileIO = new FileIoHelper();
	fileIO->FIOCreateFile(L"More_than_5GB.txt", fileIOSize);
	delete fileIO;

	StopWatch sw3;
	sw3.Start();
	_ASSERTE(file_copy_using_read_write(L"More_than_5GB.txt", L"BigfileRead.txt"));
	sw3.Stop();
	print("info] Read_Write 3GB time elapsed = %f", sw.GetDurationMilliSecond());

	StopWatch sw4;
	sw4.Start();
	_ASSERTE(file_copy_using_memory_map(L"More_than_5GB.txt", L"BigfileMMIO.txt"));
	sw4.Stop();
	print("info] MMIO 3GB time elapsed = %f", sw.GetDurationMilliSecond());

	return 0;
}