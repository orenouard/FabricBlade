#ifndef __KL2EDK_AUTOGEN_Vec3__
#define __KL2EDK_AUTOGEN_Vec3__

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

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'Vec3'
// Defined at Vec3.kl:16:1

struct Vec3
{
  typedef Vec3 &Result;
  typedef Vec3 const &INParam;
  typedef Vec3 &IOParam;
  
  Float32 x;
  Float32 y;
  Float32 z;
};

inline void Traits<Vec3>::ConstructEmpty( Vec3 &val )
{
  Traits< Float32 >::ConstructEmpty( val.x );
  Traits< Float32 >::ConstructEmpty( val.y );
  Traits< Float32 >::ConstructEmpty( val.z );
}
inline void Traits<Vec3>::ConstructCopy( Vec3 &lhs, Vec3 const &rhs )
{
  Traits< Float32 >::ConstructCopy( lhs.x, rhs.x );
  Traits< Float32 >::ConstructCopy( lhs.y, rhs.y );
  Traits< Float32 >::ConstructCopy( lhs.z, rhs.z );
}
inline void Traits<Vec3>::AssignCopy( Vec3 &lhs, Vec3 const &rhs )
{
  Traits< Float32 >::AssignCopy( lhs.x, rhs.x );
  Traits< Float32 >::AssignCopy( lhs.y, rhs.y );
  Traits< Float32 >::AssignCopy( lhs.z, rhs.z );
}
inline void Traits<Vec3>::Destruct( Vec3 &val )
{
  Traits< Float32 >::Destruct( val.z );
  Traits< Float32 >::Destruct( val.y );
  Traits< Float32 >::Destruct( val.x );
}
}}}

#endif // __KL2EDK_AUTOGEN_Vec3__
