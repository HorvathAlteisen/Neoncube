#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#undef MessageBox
#endif

#include <tchar.h>

#include <shlwapi.h>
