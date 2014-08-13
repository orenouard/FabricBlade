#ifndef __KL2EDK_AUTOGEN_ViconResult_functions__
#define __KL2EDK_AUTOGEN_ViconResult_functions__

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
#include "ViconResult.h"


// Defined at ./ViconResult.kl:16:1
FABRIC_EXT_EXPORT void ViconResultFromString(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconResult >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::INParam name
);

// Defined at ./ViconResult.kl:17:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::SInt32 ViconResultAsCode(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconResult >::INParam this_
);

// Defined at ./ViconResult.kl:18:1
FABRIC_EXT_EXPORT void ViconResultAsString(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconResult >::INParam this_
);

// Defined at ./ViconResult.kl:19:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean ViconResultIsSuccess(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconResult >::INParam this_
);

// Defined at ./ViconResult.kl:20:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean ViconResultEqual(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconResult >::INParam a,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconResult >::INParam b
);

// Defined at ./ViconResult.kl:21:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean ViconResultNotEqual(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconResult >::INParam a,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconResult >::INParam b
);

#endif // __KL2EDK_AUTOGEN_ViconResult_functions__
