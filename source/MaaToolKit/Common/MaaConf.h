#pragma once

#if !defined(MAA_USE_RANGES_STL) && !defined(MAA_USE_RANGES_RANGE_V3) && !defined(MAA_USE_RANGES_BOOST)
#if defined(__clang__) && __clang_major__ < 15
#define MAA_USE_RANGES_RANGE_V3
#else
#define MAA_USE_RANGES_STL
#endif
#endif

#ifdef _MSC_VER
#define MAA_DO_PRAGMA(x) __pragma(x)
#elif defined(__GNUC__)
#define MAA_DO_PRAGMA(x) _Pragma(#x)
#else
#define MAA_DO_PRAGMA(x)
#endif

#ifdef _MSC_VER
#define MAA_SUPPRESS_CV_WARNINGS_BEGIN \
    MAA_DO_PRAGMA(warning(push))       \
    MAA_DO_PRAGMA(warning(disable : 5054 4251 4305 4275 4100 4244 4127))
#define MAA_SUPPRESS_CV_WARNINGS_END MAA_DO_PRAGMA(warning(pop))
#elif defined(__clang__)
#define MAA_SUPPRESS_CV_WARNINGS_BEGIN                                               \
    MAA_DO_PRAGMA(clang diagnostic push)                                             \
    MAA_DO_PRAGMA(clang diagnostic ignored "-Wdeprecated-enum-enum-conversion")      \
    MAA_DO_PRAGMA(clang diagnostic ignored "-Wdeprecated-anon-enum-enum-conversion") \
    MAA_DO_PRAGMA(clang diagnostic ignored "-Wc11-extensions")                       \
    MAA_DO_PRAGMA(clang diagnostic ignored "-Wunused-but-set-variable")
#define MAA_SUPPRESS_CV_WARNINGS_END MAA_DO_PRAGMA(clang diagnostic pop)
#elif defined(__GNUC__)
#define MAA_SUPPRESS_CV_WARNINGS_BEGIN \
    MAA_DO_PRAGMA(GCC diagnostic push) \
    MAA_DO_PRAGMA(GCC diagnostic ignored "-Wdeprecated-enum-enum-conversion")
#define MAA_SUPPRESS_CV_WARNINGS_END MAA_DO_PRAGMA(GCC diagnostic pop)
#else
#define MAA_SUPPRESS_CV_WARNINGS_BEGIN
#define MAA_SUPPRESS_CV_WARNINGS_END
#endif

#ifdef __GNUC__
#define MAA_AUTO_DEDUCED_ZERO_INIT_START \
    MAA_DO_PRAGMA(GCC diagnostic push)   \
    MAA_DO_PRAGMA(GCC diagnostic ignored "-Wmissing-field-initializers")
#define MAA_AUTO_DEDUCED_ZERO_INIT_END MAA_DO_PRAGMA(GCC diagnostic pop)
#elif defined(__clang__)
#define MAA_AUTO_DEDUCED_ZERO_INIT_START \
    MAA_DO_PRAGMA(clang diagnostic push) \
    MAA_DO_PRAGMA(clang diagnostic ignored "-Wmissing-field-initializers")
#define MAA_AUTO_DEDUCED_ZERO_INIT_END MAA_DO_PRAGMA(clang diagnostic pop)
#else
#define MAA_AUTO_DEDUCED_ZERO_INIT_START
#define MAA_AUTO_DEDUCED_ZERO_INIT_END
#endif

#define MAA_TOOLKIT_NS MaaToolKitNS
#define MAA_TOOLKIT_NS_BEGIN \
    namespace MAA_TOOLKIT_NS \
    {
#define MAA_TOOLKIT_NS_END }

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifndef MAA_TOOLKIT_VERSION
#define MAA_TOOLKIT_VERSION "DEBUG_VERSION"
#endif
