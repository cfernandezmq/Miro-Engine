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

#ifdef MR_ENABLE_ASSERTS
	#define MR_ASSERT(x, ...) {if(!(x)) { MR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MR_CORE_ASSERT(x, ...) { if(!(x)) { MR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MR_ASSERT(x, ...)
	#define MR_CORE_ASSERT(x, ...)
#endif // MR_ENABLE_ASSERTS



#define BIT(x) (1 << x)