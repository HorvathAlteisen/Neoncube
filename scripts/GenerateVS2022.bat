@echo off
pushd %~dp0\..\
call .\vendor\premake-core\bin\release\premake5.exe vs2022
popd
PAUSE
