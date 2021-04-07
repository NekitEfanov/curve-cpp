#pragma once

#if __GNUC__ || __MINGW32__
#	define CURVE_ALIGN_TO_BOUNDARY(n) __attribute__((aligned(n)))
#	define CURVE_ALIGNOF(x) __alignof(x)
#elif _MSC_VER
#	define CURVE_ALIGN_TO_BOUNDARY(n) __declspec(align(n))
#	define CURVE_ALIGNOF(x) __alignof(x)
#else
	// TODO
#	define CURVE_ALIGN_TO_BOUNDARY(n)
#	define CURVE_ALIGNOF(x)
#endif

#define CURVE_ALIGN_16 CURVE_ALIGN_TO_BOUNDARY(16)

#ifdef CURVE_EXPORT
#   ifdef _MSC_VER
#       define CURVE_IMPORT_EXPORT __declspec(dllexport)
#   else
#       define CURVE_IMPORT_EXPORT 
#   endif
#else
#   ifdef _MSC_VER
#       define CURVE_IMPORT_EXPORT 
#   else
#       define CURVE_IMPORT_EXPORT 
#   endif
#endif
