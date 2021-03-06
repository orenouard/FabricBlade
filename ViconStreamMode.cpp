/*
 * Fabric Core 1.11.4
 * Vicon Datastream EDK wrap
 */

#include "ViconStreamMode.h" // Automatically generated by kl2edk
#include "ViconStreamMode_functions.h"
#include <Client.h> // Vicon header
#include "conversion.h"

using namespace ViconDataStreamSDK::CPP::StreamMode;

namespace
{
  inline Enum StringToEnum(const char* i_string)
  {
    if(!strcmp(i_string, "ClientPull"))
      return ClientPull;
    else if(!strcmp(i_string, "ClientPullPreFetch"))
      return ClientPullPreFetch;
    else if(!strcmp(i_string, "ServerPush"))
      return ServerPush;
    else
      FABRIC_EXT_SETERROR_AND_RETURN_VALUE(ClientPull, "%s: %s", "Invalid ViconStreamMode name", i_string);
  }  
  inline Fabric::EDK::KL::String EnumToString(const Enum i_enum)
  {
    switch(i_enum)
    {
      case ClientPull:
        return "ClientPull";
      case ClientPullPreFetch:
        return "ClientPullPreFetch";
      case ServerPush:
        return "ServerPush";
      default:
        FABRIC_EXT_SETERROR_AND_RETURN_VALUE("", "%s: %i", "Invalid ViconStreamMode code", int(i_enum));
    }
  }
}

FABRIC_EXT_EXPORT void ViconStreamModeFromString(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconStreamMode >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::INParam name
)
{
  this_.handle = new Enum(StringToEnum(name.data()));
}

FABRIC_EXT_EXPORT Fabric::EDK::KL::SInt32 ViconStreamModeAsCode(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconStreamMode >::INParam this_
)
{
  Enum resultEnum;
  if (conv_from_KLStruct(this_, resultEnum))
  {
    return Fabric::EDK::KL::Integer(resultEnum);
  } else {
    FABRIC_EXT_SETERROR_AND_RETURN_VALUE(0, "%s: %s", "ViconStreamModeAsCode", "Invalid ViconStreamMode");
  }
}

FABRIC_EXT_EXPORT void ViconStreamModeAsString(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconStreamMode >::INParam this_
)
{
  Enum resultEnum;
  if (conv_from_KLStruct(this_, resultEnum))
  {
    _result = EnumToString(resultEnum);
  } else {
    _result = "Unknown";
    FABRIC_EXT_SETERROR_AND_RETURN("%s: %s", "ViconStreamModeAsString", "Invalid ViconStreamMode");
  }
}

FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean ViconStreamModeEqual(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconStreamMode >::INParam a,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconStreamMode >::INParam b
)
{
  Enum enumA;
  Enum enumB;
  if (conv_from_KLStruct(a, enumA) && conv_from_KLStruct(b, enumB))
  {
    return (enumA == enumB);
  } else {
    FABRIC_EXT_SETERROR_AND_RETURN_VALUE(false, "%s: %s", "ViconStreamModeEqual", "Invalid ViconStreamMode");
  }
}

FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean ViconStreamModeNotEqual(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconStreamMode >::INParam a,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::ViconStreamMode >::INParam b
)
{
  Enum enumA;
  Enum enumB;
  if (conv_from_KLStruct(a, enumA) && conv_from_KLStruct(b, enumB))
  {
    return (enumA != enumB);
  } else {
    FABRIC_EXT_SETERROR_AND_RETURN_VALUE(true, "%s: %s", "ViconStreamModeNotEqual", "Invalid ViconStreamMode");
  }
}
