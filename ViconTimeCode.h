#ifndef __KL2EDK_AUTOGEN_ViconTimeCode__
#define __KL2EDK_AUTOGEN_ViconTimeCode__

////////////////////////////////////////////////////////////////
// THIS FILE IS AUTOMATICALLY GENERATED -- DO NOT MODIFY!!
////////////////////////////////////////////////////////////////
// Generated by kl2exe version 1.11.4
////////////////////////////////////////////////////////////////

#include <Fabric/EDK/EDK.h>
#if FABRIC_EDK_VERSION_MAJ != 1 || FABRIC_EDK_VERSION_MIN != 11
# error "This file needs to be rebuilt for the current EDK version!"
#endif

#include "global.h"
#include "ViconTimeCodeStandard.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'ViconTimeCode'
// Defined at ./ViconTimeCode.kl:6:1

struct ViconTimeCode
{
  typedef ViconTimeCode &Result;
  typedef ViconTimeCode const &INParam;
  typedef ViconTimeCode &IOParam;
  
  UInt32 Hours;
  UInt32 Minutes;
  UInt32 Seconds;
  UInt32 Frames;
  UInt32 SubFrame;
  Boolean FieldFlag;
  ViconTimeCodeStandard Standard;
  UInt32 SubFramesPerFrame;
  UInt32 UserBits;
};

inline void Traits<ViconTimeCode>::ConstructEmpty( ViconTimeCode &val )
{
  Traits< UInt32 >::ConstructEmpty( val.Hours );
  Traits< UInt32 >::ConstructEmpty( val.Minutes );
  Traits< UInt32 >::ConstructEmpty( val.Seconds );
  Traits< UInt32 >::ConstructEmpty( val.Frames );
  Traits< UInt32 >::ConstructEmpty( val.SubFrame );
  Traits< Boolean >::ConstructEmpty( val.FieldFlag );
  Traits< ViconTimeCodeStandard >::ConstructEmpty( val.Standard );
  Traits< UInt32 >::ConstructEmpty( val.SubFramesPerFrame );
  Traits< UInt32 >::ConstructEmpty( val.UserBits );
}
inline void Traits<ViconTimeCode>::ConstructCopy( ViconTimeCode &lhs, ViconTimeCode const &rhs )
{
  Traits< UInt32 >::ConstructCopy( lhs.Hours, rhs.Hours );
  Traits< UInt32 >::ConstructCopy( lhs.Minutes, rhs.Minutes );
  Traits< UInt32 >::ConstructCopy( lhs.Seconds, rhs.Seconds );
  Traits< UInt32 >::ConstructCopy( lhs.Frames, rhs.Frames );
  Traits< UInt32 >::ConstructCopy( lhs.SubFrame, rhs.SubFrame );
  Traits< Boolean >::ConstructCopy( lhs.FieldFlag, rhs.FieldFlag );
  Traits< ViconTimeCodeStandard >::ConstructCopy( lhs.Standard, rhs.Standard );
  Traits< UInt32 >::ConstructCopy( lhs.SubFramesPerFrame, rhs.SubFramesPerFrame );
  Traits< UInt32 >::ConstructCopy( lhs.UserBits, rhs.UserBits );
}
inline void Traits<ViconTimeCode>::AssignCopy( ViconTimeCode &lhs, ViconTimeCode const &rhs )
{
  Traits< UInt32 >::AssignCopy( lhs.Hours, rhs.Hours );
  Traits< UInt32 >::AssignCopy( lhs.Minutes, rhs.Minutes );
  Traits< UInt32 >::AssignCopy( lhs.Seconds, rhs.Seconds );
  Traits< UInt32 >::AssignCopy( lhs.Frames, rhs.Frames );
  Traits< UInt32 >::AssignCopy( lhs.SubFrame, rhs.SubFrame );
  Traits< Boolean >::AssignCopy( lhs.FieldFlag, rhs.FieldFlag );
  Traits< ViconTimeCodeStandard >::AssignCopy( lhs.Standard, rhs.Standard );
  Traits< UInt32 >::AssignCopy( lhs.SubFramesPerFrame, rhs.SubFramesPerFrame );
  Traits< UInt32 >::AssignCopy( lhs.UserBits, rhs.UserBits );
}
inline void Traits<ViconTimeCode>::Destruct( ViconTimeCode &val )
{
  Traits< UInt32 >::Destruct( val.UserBits );
  Traits< UInt32 >::Destruct( val.SubFramesPerFrame );
  Traits< ViconTimeCodeStandard >::Destruct( val.Standard );
  Traits< Boolean >::Destruct( val.FieldFlag );
  Traits< UInt32 >::Destruct( val.SubFrame );
  Traits< UInt32 >::Destruct( val.Frames );
  Traits< UInt32 >::Destruct( val.Seconds );
  Traits< UInt32 >::Destruct( val.Minutes );
  Traits< UInt32 >::Destruct( val.Hours );
}
}}}

#endif // __KL2EDK_AUTOGEN_ViconTimeCode__
