REM
REM Example environment setup file for Fabric Engine
REM Update BASEDIR to point to the chosen installation dir
REM

set BASEDIR=C:\Program Files\Fabric Engine

set FABRIC_EXTS_PATH=%BASEDIR%\Exts
set FABRIC_EDK_DIR=%BASEDIR%\EDK
set FABRIC_CAPI_DIR=%BASEDIR%\CAPI
set FABRIC_PYTHON_MODULE_DIR=%BASEDIR%\Python\2.7
set FABRIC_DOCUMENTATION_DIR=%BASEDIR%\Documentation
set FABRIC_TOOLS_DIR=%BASEDIR%\Tools

set PATH=%FABRIC_CAPI_DIR%\lib;%FABRIC_PYTHON_MODULE_DIR%\PySide;%FABRIC_TOOLS_DIR%;%PATH%
set PYTHONPATH=%FABRIC_PYTHON_MODULE_DIR%;%PYTHONPATH%

