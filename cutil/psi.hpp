/** \file psi.hpp
 *	\brief
 *		Standard PSI definitions, to be used across all C++ projects
 *
 *	\author	Krzysztof Kamieniecki, <krys@passportsystems.com>, Passport Systems Inc.
 *
 *	\date	2007-10-31
 *
 *	Copyright 2007 - 2007, Passport Systems, Inc.
 *
 */

//-----------------------------------------------------------------------------
//                       Revision History
//                       ----------------
// Date        Name            Comment
//-----------------------------------------------------------------------------
// 2007-10-31  KKamieniecki    Created
// 2009-01-17  RMatracki	   Updated with VXWORKS defines
// 2009-03-13  mryan		   Added #elif for linux defintions as well as vxworks (both use gcc)
//-----------------------------------------------------------------------------

#ifndef PSI_HPP_
#define PSI_HPP_

const int MAX_LOG_MSG_LEN		= 2*1024;

#ifdef WIN32
typedef char c8;
typedef signed __int8 s8;
typedef unsigned __int8 u8;
typedef signed __int16 s16;
typedef unsigned __int16 u16;
typedef signed __int32 s32;
typedef unsigned __int32 u32;
typedef signed __int64 s64;
typedef unsigned __int64 u64;
#endif

//linux
#if defined(linux) || defined(__linux__)
#include <stdint.h>
typedef char c8;
typedef int8_t s8;
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef int64_t s64;
typedef uint64_t u64;
#endif

#ifdef VXWORKS
#include <sys/types.h>
typedef char c8;
typedef int8_t s8;
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef int64_t s64;
typedef uint64_t u64;
#endif

typedef float f32;
typedef double f64;



enum DataTypeIDS { DataSetTypeID=0, Hist1DTypeID, Hist2DTypeID, WaveFormTypeID };

#define PSI_ASSERT(TST_) assert(TST_)
#define PSI_CALL_CHECK(FUNC_) if(FUNC_) throw std::exception(#FUNC_)

//needed for VS2005 compiler add class automatically but can't handling it beign there explicilty
#ifdef WIN32
#define MTEMPLATECLASSFIX 
#else
#define MTEMPLATECLASSFIX class 
#endif


#endif //ndef PSI_HPP_
