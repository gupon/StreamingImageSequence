#pragma once

#ifdef _WIN32
#  if defined(COMMONLIBWIN_EXPORTS) || defined(PLUGIN_DLL_EXPORT)
#  define COMMONLIB_API __declspec(dllexport)
#  else
#  define COMMONLIB_API __declspec(dllimport)
#  endif
#else
#  define COMMONLIB_API
#endif


#include <thread>
#include <mutex>
#include <string>
#include <unordered_map>

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


#ifdef _WIN32
    #include <windows.h>
    #undef LoadImage
    typedef UINT64 u64;
    typedef UINT32 u32;
    typedef INT32 s32;
    typedef UINT16 u16;
    typedef UINT8 u8;
#else
    typedef unsigned long u64;
    typedef unsigned int u32;
    typedef int s32;
    typedef short u16;
    typedef unsigned char u8;
    typedef wchar_t WCHAR;
#endif


#define  USE_WCHAR 0

#if USE_WCHAR
    typedef WCHAR charType;
    typedef std::wstring strType;
    #define TO_STR_TYPE std::to_wstring
#else
    typedef char charType;
    typedef std::string strType;
    #define TO_STR_TYPE std::to_string
#endif


#define BIT(x) (1<<x)
#if _DEBUG && defined(_WIN32)
#define ASSERT( xx_ )  (xx_) ? (void)0 : __debugbreak()
#else
#define ASSERT( xx_ )   (void)0 
#endif
