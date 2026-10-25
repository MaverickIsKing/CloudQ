#pragma once
#ifdef CQ_PLATFORM_WINDOWS
	#ifdef CQ_BUILD_DLL
		#define CLOUDQ_API __declspec(dllexport)
	#else
		#define CLOUDQ_API __declspec(dllimport)
	#endif // CQ_BUILD_DLL
#else
	#error CloudQ only supports Windows currently!
#endif