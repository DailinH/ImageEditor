@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by IMAGEEDITOR.HPJ. >"hlp\ImageEditor.hm"
echo. >>"hlp\ImageEditor.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\ImageEditor.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\ImageEditor.hm"
echo. >>"hlp\ImageEditor.hm"
echo // Prompts (IDP_*) >>"hlp\ImageEditor.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\ImageEditor.hm"
echo. >>"hlp\ImageEditor.hm"
echo // Resources (IDR_*) >>"hlp\ImageEditor.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\ImageEditor.hm"
echo. >>"hlp\ImageEditor.hm"
echo // Dialogs (IDD_*) >>"hlp\ImageEditor.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\ImageEditor.hm"
echo. >>"hlp\ImageEditor.hm"
echo // Frame Controls (IDW_*) >>"hlp\ImageEditor.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\ImageEditor.hm"
REM -- Make help for Project IMAGEEDITOR


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\ImageEditor.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\ImageEditor.hlp" goto :Error
if not exist "hlp\ImageEditor.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\ImageEditor.hlp" Debug
if exist Debug\nul copy "hlp\ImageEditor.cnt" Debug
if exist Release\nul copy "hlp\ImageEditor.hlp" Release
if exist Release\nul copy "hlp\ImageEditor.cnt" Release
echo.
goto :done

:Error
echo hlp\ImageEditor.hpj(1) : error: Problem encountered creating help file

:done
echo.
