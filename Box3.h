#ifndef __KL2EDK_AUTOGEN_Box3__
#define __KL2EDK_AUTOGEN_Box3__

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
#include "Vec3.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'Box3'
// Defined at Box3.kl:19:1

struct Box3
{
  typedef Box3 &Result;
  typedef Box3 const &INParam;
  typedef Box3 &IOParam;
  
  Vec3 min;
  Vec3 max;
};

inline void Traits<Box3>::ConstructEmpty( Box3 &val )
{
  Traits< Vec3 >::ConstructEmpty( val.min );
  Traits< Vec3 >::ConstructEmpty( val.max );
}
inline void Traits<Box3>::ConstructCopy( Box3 &lhs, Box3 const &rhs )
{
  Traits< Vec3 >::ConstructCopy( lhs.min, rhs.min );
  Traits< Vec3 >::ConstructCopy( lhs.max, rhs.max );
}
inline void Traits<Box3>::AssignCopy( Box3 &lhs, Box3 const &rhs )
{
  Traits< Vec3 >::AssignCopy( lhs.min, rhs.min );
  Traits< Vec3 >::AssignCopy( lhs.max, rhs.max );
}
inline void Traits<Box3>::Destruct( Box3 &val )
{
  Traits< Vec3 >::Destruct( val.max );
  Traits< Vec3 >::Destruct( val.min );
}
}}}

#endif // __KL2EDK_AUTOGEN_Box3__
