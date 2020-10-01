#pragma once

#ifdef MR_PLATFORM_WINDOWS
	#ifdef MR_BUILD_DLL
		#define MIRO_API __declspec(dllexport)
	#else
		#define MIRO_API __declspec(dllimport)
	#endif
#else
	#error Miro only supports Windows!
#endif // MR_PLATFORM_WINDOWS


#define BIT(x) (1 << x)