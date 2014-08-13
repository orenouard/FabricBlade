#
# Fabric Core 1.11.4
# HelloWorld EDK Sample
#
# Copyright 2010-2014 Fabric Software Inc. All rights reserved.
#

import os
if 'FABRIC_EXTS_PATH' in os.environ:
  os.environ['FABRIC_EXTS_PATH'] = os.pathsep.join(['.', os.environ['FABRIC_EXTS_PATH']])
else:
  os.environ['FABRIC_EXTS_PATH'] = '.'

import FabricEngine.Core as fabric
fabricClient = fabric.createClient();

opSource = """
require ViconDataStream;

operator testViconDataStream(io String string);
"""

op = fabricClient.DG.createOperator("op")
op.setSourceCode(opSource)
op.setEntryPoint("testViconDataStream")

b = fabricClient.DG.createBinding()
b.setOperator(op)
b.setParameterLayout(['self.string'])

node = fabricClient.DG.createNode("node")
node.addMember("string", "String", "localhost:801")
node.bindings.append(b)
node.evaluate()
print "Python got: " + node.getData("string", 0)

fabricClient.close()
