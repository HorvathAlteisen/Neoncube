#include "ConfigIni.hpp"

namespace Hermes
{
	ConfigIni::ConfigIni(std::string filepath)
	{
		ReadFile(filepath);
	};

	IConfigData ConfigIni::get(std::string key){

	};

	int ConfigIni::ReadFile(const std::string filepath)
	{
		// checks if neoncube.ini exists
		switch (CheckFileForExistance(filepath.c_str()))
		{

		case CFFE_FILE_NOT_FOUND:
			// AddErrorLog("file not found (neoncube\\neoncube.ini)\n");
			MessageBoxA(NULL, "file not found (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
			return -1;

		case CFFE_PATH_NOT_FOUND:
			// AddErrorLog("invalid path (neoncube\\neoncube.ini)\n");
			MessageBoxA(NULL, "path not found (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
			return -1;

		case CFFE_ACCESS_DENIED:
			// AddErrorLog("access denied (neoncube\\neoncube.ini)\n");
			MessageBoxA(NULL, "access denied (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
			return -1;

		case CFFE_UNKNOWN_ERROR:
			// AddErrorLog("unknown error (neoncube\\neoncube.ini)\n");
			MessageBoxA(NULL, "unknown error (neoncube\\neoncube.ini)", "Error", MB_OK | MB_ICONERROR);
			return -1;
		}
	};

	CFFE_ERROR
	ConfigIni::CheckFileForExistance(LPCTSTR lpszFileName)
	{
		CFFE_ERROR ret = CFFE_FILE_EXIST;

		DWORD dwAttr = GetFileAttributes(lpszFileName);

		if (dwAttr == 0xffffffff)
		{

			DWORD dwError = GetLastError();

			if (dwError == ERROR_FILE_NOT_FOUND)
				ret = CFFE_FILE_NOT_FOUND; // file not found

			else if (dwError == ERROR_PATH_NOT_FOUND)
				ret = CFFE_PATH_NOT_FOUND; // invalid path

			else if (dwError == ERROR_ACCESS_DENIED)
				ret = CFFE_ACCESS_DENIED; // access denied (another application is using the file)

			else
				ret = CFFE_UNKNOWN_ERROR;
		}

		return ret;
	};
}