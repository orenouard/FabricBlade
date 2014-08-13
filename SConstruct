#
# Fabric Core 1.11.4
# Vicon DataStream EDK Sample
#
# Copyright 2010-2014 Fabric Software Inc. All rights reserved.
#

import os, sys

try:
  fabricEDKPath = os.environ['FABRIC_EDK_DIR']
except:
  print "You must set FABRIC_EDK_DIR in your environment."
  print "Refer to README.txt for more information."
  sys.exit(1)
SConscript(os.path.join(fabricEDKPath, 'SConscript'))
Import('fabricBuildEnv')

try:
  viconEDKPath = os.environ['VICON_EDK_DIR']
except:
  print "You must set VICON_EDK_DIR in your environment."
  sys.exit(1)
  
fabricBuildEnv.Append(CPPPATH = [viconEDKPath])
fabricBuildEnv.Append(LIBS = ['ViconDataStreamSDK_CPP'], LIBPATH=[viconEDKPath])

extFiles = []
extFiles += Glob('*.cpp')
extFiles += Glob('*.json')
extFiles += [	"ViconResult.kl",
				"ViconStreamMode.kl",
				"ViconVersion.kl",
				"ViconDirection.kl",
				"ViconAxisMapping.kl",
				"ViconTimeCodeStandard.kl",
				"ViconTimeCode.kl",		
				"ViconClient.kl",
				"ViconDataStream.kl"	]
# extFiles += Glob('*.kl')

fabricBuildEnv.Extension('ViconDataStream', extFiles)

