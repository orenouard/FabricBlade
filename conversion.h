/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#ifndef __conversion_h__
#define __conversion_h__

#include "Handle.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Vec3.h"
#include "Quat.h"
#include "Euler.h"
#include "Mat33.h"
#include "ViconResult.h"
#include "ViconVersion.h"
#include "ViconAxisMapping.h"
#include "ViconTimeCode.h"
#include <Client.h> // Vicon header

using namespace Fabric::EDK;
using namespace ViconDataStreamSDK::CPP;

namespace
{
  inline Result::Enum StringToResultEnum(const char* i_Name)
  {
    if(!strcmp(i_Name, "Unknown"))
      return Result::Unknown;
    else if(!strcmp(i_Name, "NotImplemented"))
      return Result::NotImplemented;
    else if(!strcmp(i_Name, "Success"))
      return Result::Success;
    else if(!strcmp(i_Name, "InvalidHostName"))
      return Result::InvalidHostName;
    else if(!strcmp(i_Name, "InvalidMulticastIP"))
      return Result::InvalidMulticastIP;
    else if(!strcmp(i_Name, "ClientAlreadyConnected"))
      return Result::ClientAlreadyConnected;
    else if(!strcmp(i_Name, "ClientConnectionFailed"))
      return Result::ClientConnectionFailed;
    else if(!strcmp(i_Name, "ServerAlreadyTransmittingMulticast"))
      return Result::ServerAlreadyTransmittingMulticast;
    else if(!strcmp(i_Name, "ServerNotTransmittingMulticast"))
      return Result::ServerNotTransmittingMulticast;
    else if(!strcmp(i_Name, "NotConnected"))
      return Result::NotConnected;
    else if(!strcmp(i_Name, "NoFrame"))
      return Result::NoFrame;
    else if(!strcmp(i_Name, "InvalidIndex"))
      return Result::InvalidIndex;
    else if(!strcmp(i_Name, "InvalidSubjectName"))
      return Result::InvalidSubjectName;
    else if(!strcmp(i_Name, "InvalidSegmentName"))
      return Result::InvalidSegmentName;
    else if(!strcmp(i_Name, "InvalidMarkerName"))
      return Result::InvalidMarkerName;
    else if(!strcmp(i_Name, "InvalidDevideName"))
      return Result::InvalidDeviceName;
    else if(!strcmp(i_Name, "InvalidDeviceOutputName"))
      return Result::InvalidDeviceOutputName;
    else if(!strcmp(i_Name, "InvalidLatencySampleName"))
      return Result::InvalidLatencySampleName;
    else if(!strcmp(i_Name, "CoLinearAxes"))
      return Result::CoLinearAxes;
    else if(!strcmp(i_Name, "LeftHandedAxes"))
      return Result::LeftHandedAxes;
    else
      return Result::Unknown;
  }
  inline const char* ResultEnumToString(const Result::Enum i_Result)
  {
    switch(i_Result)
    {
      case Result::NotImplemented:
        return "NotImplemented";
      case Result::Success:
        return "Success";
      case Result::InvalidHostName:
        return "InvalidHostName";
      case Result::InvalidMulticastIP:
        return "InvalidMulticastIP";
      case Result::ClientAlreadyConnected:
        return "ClientAlreadyConnected";
      case Result::ClientConnectionFailed:
        return "ClientConnectionFailed";
      case Result::ServerAlreadyTransmittingMulticast:
        return "ServerAlreadyTransmittingMulticast";
      case Result::ServerNotTransmittingMulticast:
        return "ServerNotTransmittingMulticast";
      case Result::NotConnected:
        return "NotConnected";
      case Result::NoFrame:
        return "NoFrame";
      case Result::InvalidIndex:
        return "InvalidIndex";
      case Result::InvalidSubjectName:
        return "InvalidSubjectName";
      case Result::InvalidSegmentName:
        return "InvalidSegmentName";
      case Result::InvalidMarkerName:
        return "InvalidMarkerName";
      case Result::InvalidDeviceName:
        return "InvalidDevideName";
      case Result::InvalidDeviceOutputName:
        return "InvalidDeviceOutputName";
      case Result::InvalidLatencySampleName:
        return "InvalidLatencySampleName";
      case Result::CoLinearAxes:
        return "CoLinearAxes";
      case Result::LeftHandedAxes:
        return "LeftHandedAxes";
      default:
        return "Unknown";
    }
  }
}


template<class A, class B>
inline bool conv_from_baseType(const A & a, B & b)
{
  b = a;
  return true;
}

template<class B, class A>
inline bool conv_to_baseType(const A & a, B & b)
{
  b = a;
  return true;
}

// We use struct for simple object and object for more complex ones
// Here a copy is done instead of returning a pointer
template<class A, class B>
inline bool conv_from_KLStruct(const A & a, B & b)
{
  if(a.handle == NULL)
    FABRIC_EXT_SETERROR_AND_RETURN_VALUE(false, "%s: %s", "NULL handle in KL Struct", "");
  b = B(* (B *)(a.handle));
  return true;
}

// We do a copy since the struct will have ownership of its own copy
template<class B, class A>
inline bool conv_to_KLStruct(const A & a, B & b)
{
  if(b.handle != NULL)
    delete b.handle;
  b.handle = new A(a);
  return true;
}

template<class A, class B>
inline bool conv_from_KLObject(const A & a, B * & b)
{
  if(!a.isValid())
    FABRIC_EXT_SETERROR_AND_RETURN_VALUE(false, "%s: %s", "Invalid KL Object", a.getType());
  Handle<B> * handle = (Handle<B> *)a->handle;
  if(handle == NULL)
    FABRIC_EXT_SETERROR_AND_RETURN_VALUE(false, "%s: %s", "NULL handle in KL Object", a.getType());
  b = handle->data();
  return true;
}

template<class B, class A>
inline bool conv_to_KLObject(const A * a, B & b, bool owned = false)
{
  if(!b.isValid())
    b = B::Create();
  if(b->handle != NULL)
    ((Handle<A> *)b->handle)->release();
  b->handle = new Handle<A>((A *)a, owned);
  return true;
}

inline bool conv_from_String(const KL::String & a, std::string & b)
{
  if(a.data() == NULL)
    b = "";
  else
    b = a.data();
  return true;
}

inline bool conv_to_String(const std::string & a, KL::String & b)
{
  if(a.length() == 0)
    b = "";
  else
    b = a.c_str();
  return true;
}

inline bool conv_from_Vec3(const KL::Vec3 & a, double b[3])
{
  b[0] = a.x;
  b[1] = a.y;
  b[2] = a.z;
  return true;
}

inline bool conv_to_Vec3(const double a[3], KL::Vec3 & b)
{
  b.x = a[0];
  b.y = a[1];
  b.z = a[2];
  return true;
}

inline bool conv_from_Quat(const KL::Quat & a, double b[4])
{
  b[0] = a.v.x;
  b[1] = a.v.y;
  b[2] = a.v.z;
  b[3] = a.w;
  return true;
}

inline bool conv_to_Quat(const double a[4], KL::Quat & b)
{
  b.v.x = a[0];
  b.v.y = a[1];
  b.v.z = a[2];
  b.w   = a[3];
  return true;
}

// Vicon SDK always assume XYZ order
inline bool conv_from_Euler(const KL::Euler & a, double b[3])
{
  if (a.ro.order == 0)
  {
    b[0] = a.x;
    b[1] = a.y;
    b[2] = a.z;
    return true;
  } else {
    FABRIC_EXT_SETERROR_AND_RETURN_VALUE(false, "%s: %s", "Invalid rotation order in KL Euler (must be XYZ)", "");
  }
}

inline bool conv_to_Euler(const double a[3], KL::Euler & b)
{
  b.x = a[0];
  b.y = a[1];
  b.z = a[2];
  b.ro.order = 0; // XYZ
  return true;
}

// column major matrix, will have to change when Fabric switches to row major
inline bool conv_from_Mat33(const KL::Mat33 & a, double b[9])
{
  b[0] = a.row0.x;
  b[1] = a.row0.y;
  b[2] = a.row0.z;
  b[3] = a.row1.x;
  b[4] = a.row1.y;
  b[5] = a.row1.z;
  b[6] = a.row2.x;
  b[7] = a.row2.y;
  b[8] = a.row2.z;     
  /*
  b[0] = a.row0.x;
  b[1] = a.row1.x;
  b[2] = a.row2.x;
  b[3] = a.row0.y;
  b[4] = a.row1.y;
  b[5] = a.row2.y;
  b[6] = a.row0.z;
  b[7] = a.row1.z;
  b[8] = a.row2.z;   
  */  
  return true;
}

inline bool conv_to_Mat33(const double a[9], KL::Mat33 & b)
{
  b.row0.x = a[0];
  b.row0.y = a[1];
  b.row0.z = a[2];
  b.row1.x = a[3];
  b.row1.y = a[4];
  b.row1.z = a[5]; 
  b.row2.x = a[6];
  b.row2.y = a[7];
  b.row2.z = a[8]; 
  /*
  b.row0.x = a[0];
  b.row1.x = a[1];
  b.row2.x = a[2];
  b.row0.y = a[3];
  b.row1.y = a[4];
  b.row2.y = a[5]; 
  b.row0.z = a[6];
  b.row1.z = a[7];
  b.row2.z = a[8];    
  */
  return true;
}

inline bool conv_from_ViconVersion(const KL::ViconVersion & a, ViconDataStreamSDK::CPP::Output_GetVersion & b)
{
  b.Major = a.major;
  b.Minor = a.minor;
  b.Point = a.point;
  return true;
}

inline bool conv_to_ViconVersion(const ViconDataStreamSDK::CPP::Output_GetVersion & a, KL::ViconVersion & b)
{
  b.major = a.Major;
  b.minor = a.Minor;
  b.point = a.Point;
  return true;
}

inline bool conv_from_ViconAxisMapping(const KL::ViconAxisMapping & a, ViconDataStreamSDK::CPP::Output_GetAxisMapping & b)
{
  return (conv_from_KLStruct(a.XAxis, b.XAxis) &&
          conv_from_KLStruct(a.YAxis, b.YAxis) &&
          conv_from_KLStruct(a.ZAxis, b.ZAxis));
}

inline bool conv_to_ViconAxisMapping(const ViconDataStreamSDK::CPP::Output_GetAxisMapping & a, KL::ViconAxisMapping & b)
{
  return (conv_to_KLStruct(a.XAxis, b.XAxis) &&
          conv_to_KLStruct(a.YAxis, b.YAxis) &&
          conv_to_KLStruct(a.ZAxis, b.ZAxis));
}

inline bool conv_from_ViconTimeCode(const KL::ViconTimeCode & a, ViconDataStreamSDK::CPP::Output_GetTimecode & b)
{
  if (conv_from_KLStruct(a.Standard, b.Standard))
  {
    b.Result = Result::Unknown;
    b.Hours = a.Hours;
    b.Minutes = a.Minutes;
    b.Seconds = a.Seconds;
    b.Frames = a.Frames;
    b.SubFrame = a.SubFrame;
    b.FieldFlag = a.FieldFlag;
    b.SubFramesPerFrame = a.SubFramesPerFrame;
    b.UserBits = a.UserBits;
    return true;
  } else {
    return false;
  }
}

inline bool conv_to_ViconTimeCode(const ViconDataStreamSDK::CPP::Output_GetTimecode & a, KL::ViconTimeCode & b)
{
  if (conv_to_KLStruct(a.Standard, b.Standard))
  {
    b.Hours = a.Hours;
    b.Minutes = a.Minutes;
    b.Seconds = a.Seconds;
    b.Frames = a.Frames;
    b.SubFrame = a.SubFrame;
    b.FieldFlag = a.FieldFlag;
    b.SubFramesPerFrame = a.SubFramesPerFrame;
    b.UserBits = a.UserBits;
    return true;
  } else {
    return false;
  }
}

inline bool isSuccess(KL::ViconResult result)
{
  Result::Enum resultEnum;
  if (conv_from_KLStruct(result, resultEnum))
    return (Result::Success == resultEnum);
  else
    return false;
}

inline const char* toString(KL::ViconResult result)
{
  Result::Enum resultEnum;
  if (conv_from_KLStruct(result, resultEnum))
    return (ResultEnumToString(resultEnum));
  else
    return "";
}


#endif
