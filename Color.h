#ifndef __KL2EDK_AUTOGEN_Color__
#define __KL2EDK_AUTOGEN_Color__

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

// KL struct 'Color'
// Defined at Color.kl:18:1

struct Color
{
  typedef Color &Result;
  typedef Color const &INParam;
  typedef Color &IOParam;
  
  Float32 r;
  Float32 g;
  Float32 b;
  Float32 a;
};

inline void Traits<Color>::ConstructEmpty( Color &val )
{
  Traits< Float32 >::ConstructEmpty( val.r );
  Traits< Float32 >::ConstructEmpty( val.g );
  Traits< Float32 >::ConstructEmpty( val.b );
  Traits< Float32 >::ConstructEmpty( val.a );
}
inline void Traits<Color>::ConstructCopy( Color &lhs, Color const &rhs )
{
  Traits< Float32 >::ConstructCopy( lhs.r, rhs.r );
  Traits< Float32 >::ConstructCopy( lhs.g, rhs.g );
  Traits< Float32 >::ConstructCopy( lhs.b, rhs.b );
  Traits< Float32 >::ConstructCopy( lhs.a, rhs.a );
}
inline void Traits<Color>::AssignCopy( Color &lhs, Color const &rhs )
{
  Traits< Float32 >::AssignCopy( lhs.r, rhs.r );
  Traits< Float32 >::AssignCopy( lhs.g, rhs.g );
  Traits< Float32 >::AssignCopy( lhs.b, rhs.b );
  Traits< Float32 >::AssignCopy( lhs.a, rhs.a );
}
inline void Traits<Color>::Destruct( Color &val )
{
  Traits< Float32 >::Destruct( val.a );
  Traits< Float32 >::Destruct( val.b );
  Traits< Float32 >::Destruct( val.g );
  Traits< Float32 >::Destruct( val.r );
}
}}}

#endif // __KL2EDK_AUTOGEN_Color__
