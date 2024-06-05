
@echo off

set CURDIR=%~dp0
set ROOTDIR=%CURDIR%

set download_tool=%ROOTDIR%sc_tool\aboot\adownload.exe
set target_file=%ROOTDIR%target\BURN_A7672S_LASC_EPI_8M_APP.zip

if not exist %target_file% (
	echo ------------target_file has not exist-------------
	exit /b 1
)

:burn
	@call reset.exe
	@call %download_tool% -u -a -s 115200 -r -q %target_file%

@REM exit /b 1

echo.
echo *********************************************
echo          burn A7672S_LASC success
echo *********************************************
echo.

exit /b 1
