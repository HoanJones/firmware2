@echo off

set CURDIR=%~dp0
set MODULE=A7672S_LASC_EPI
set build_target=%1
set option=%2
set ROOTDIR=%CURDIR%
set project_macro=
set IMAGEDIRNAME=

if NOT "%build_target%"=="" (
	for %%i in (a b c d e f g h i j k l m n o p q r s t u v w x y z) do call set build_target=%%build_target:%%i=%%i%%
)
if NOT "%option%"=="" (
	for %%i in (a b c d e f g h i j k l m n o p q r s t u v w x y z) do call set option=%%option:%%i=%%i%%
)

echo.
echo ..
echo module=%MODULE%
echo part=%build_target%
echo option=%option%
echo ..

::---------------------default config---------------------------------
set project_macro_FS_OLD=NO_FEATURE_SIMCOM_FS_OLD
set project_macro_OVERSEASGNSS=NO_FEATURE_SIMCOM_GPS_OVERSEAS
set project_macro_AT_SUPPORT=NO_AT_COMMAND_SUPPORT
set project_macro_CUS=CUS_NONE
set project_macro_TLS13=NO_FEATURE_SIMCOM_TLS_1_3
set project_macro=SIMCOM_A7678_V1_02
set project_macro_BT=BT_NOT_SUPPORT
set project_macro_GNSS=NO_FEATURE_SIMCOM_GPS

set compile_tools_file=%ROOTDIR%\sc_tool\cross_tool.zip
set compile_tools_dir=%ROOTDIR%\sc_tool\cross_tool
set compile_tools_unzip_dir=%ROOTDIR%\sc_tool
set cmd_7z=%ROOTDIR%\sc_tool\7z\7z.exe

if not exist %compile_tools_dir% (
	echo ------------uncompress compile tools-------------
	%cmd_7z% x -y %compile_tools_file% -o%compile_tools_unzip_dir% || ( echo ------------uncompress compile tools failed------------- & goto END)
	echo ------------uncompress compile tools successfully-------------
)


set MODULE=%MODULE%_8M

if "%build_target%" == "app" (
	@call :build_app %MODULE% %option%
) else if "%build_target%" == "image" (
	@call :create_image %MODULE% %option%
) else if "%build_target%" == "all" (
	@call :build_app %MODULE% %option%
	@call :create_image %MODULE% %option%
) else if "%build_target%" == "clean" (
	@call :build_app %MODULE% clean
	@call :create_image %MODULE% clean
) else (
	if not "%build_target%"=="" echo part [%build_target%] has not exist....
	goto USAGE
)

echo.
echo *********************************************
echo          build %MODULE% success
echo *********************************************
echo.

goto:eof

:build_app
	pushd sc_app\
	@call build.bat %ROOTDIR% %1 %2
	popd
goto:eof

:create_image
	if "%2" == "clean" (
		if exist target (
			echo clean image
			rd /s/q target
		)
	) else (
		@call %ROOTDIR%sc_config\script\make_target_image.bat %ROOTDIR% %1
	)
goto:eof


:END

goto:eof


:FAIL

echo.
echo *********************************************
echo          build %MODULE% FAIL
echo *********************************************
echo.

exit /b 1
