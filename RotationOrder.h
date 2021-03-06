#ifndef __KL2EDK_AUTOGEN_RotationOrder__
#define __KL2EDK_AUTOGEN_RotationOrder__

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

// KL struct 'RotationOrder'
// Defined at RotationOrder.kl:17:1

struct RotationOrder
{
  typedef RotationOrder &Result;
  typedef RotationOrder const &INParam;
  typedef RotationOrder &IOParam;
  
  SInt32 order;
};

inline void Traits<RotationOrder>::ConstructEmpty( RotationOrder &val )
{
  Traits< SInt32 >::ConstructEmpty( val.order );
}
inline void Traits<RotationOrder>::ConstructCopy( RotationOrder &lhs, RotationOrder const &rhs )
{
  Traits< SInt32 >::ConstructCopy( lhs.order, rhs.order );
}
inline void Traits<RotationOrder>::AssignCopy( RotationOrder &lhs, RotationOrder const &rhs )
{
  Traits< SInt32 >::AssignCopy( lhs.order, rhs.order );
}
inline void Traits<RotationOrder>::Destruct( RotationOrder &val )
{
  Traits< SInt32 >::Destruct( val.order );
}
}}}

#endif // __KL2EDK_AUTOGEN_RotationOrder__
