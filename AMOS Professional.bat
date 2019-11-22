REM ECHO OFF
REM  QBFC Project Options Begin
REM  HasVersionInfo: No
REM  Companyname: 
REM  Productname: 
REM  Filedescription: 
REM  Copyrights: 
REM  Trademarks: 
REM  Originalname: 
REM  Comments: 
REM  Productversion:  0. 0. 0. 0
REM  Fileversion:  0. 0. 0. 0
REM  Internalname: 
REM  Appicon: 
REM  QBFC Project Options End
if exist WinUAE if exist "%CD%\AROS\aros-amiga-m68k-rom.bin" WinUAE\WinUAE.exe -f "%CD%\AMOSPro.uae" -cfgparam kickstart_rom_file="%CD%\AROS\aros-amiga-m68k-rom.bin" -cfgparam kickstart_ext_rom_file="%CD%\AROS\aros-amiga-m68k-ext.bin" -cfgparam filesystem2=rw,HD0:AMOSPro_System:"%CD%\AMOS",0
if exist WinUAE if NOT exist "%CD%\AROS\aros-amiga-m68k-rom.bin" WinUAE\WinUAE.exe -f "%CD%\AMOSPro.uae" -cfgparam filesystem2=rw,HD0:AMOSPro_System:"%CD%\AMOS",0
if exist WinUAE exit
if exist "%ProgramFiles%\WinUAE\WinUAE.exe" if exist "%CD%\AROS\aros-amiga-m68k-rom.bin" "%ProgramFiles%\WinUAE\WinUAE.exe" -f "%CD%\AMOSPro.uae" -cfgparam kickstart_rom_file="%CD%\AROS\aros-amiga-m68k-rom.bin" -cfgparam kickstart_ext_rom_file="%CD%\AROS\aros-amiga-m68k-ext.bin" -cfgparam filesystem2=rw,HD0:AMOSPro_System:"%CD%\AMOS",0
if exist "%ProgramFiles%\WinUAE\WinUAE.exe" if NOT exist "%CD%\AROS\aros-amiga-m68k-rom.bin" "%ProgramFiles%\WinUAE\WinUAE.exe" -f "%CD%\AMOSPro.uae" -cfgparam filesystem2=rw,HD0:AMOSPro_System:"%CD%\AMOS",0
if exist "%ProgramFiles%\WinUAE\WinUAE.exe" exit
if exist "%ProgramFiles(x86)%\WinUAE\WinUAE.exe" if exist "%CD%\AROS\aros-amiga-m68k-rom.bin" "%ProgramFiles(x86)%\WinUAE\WinUAE.exe" -f "%CD%\AMOSPro.uae" -cfgparam kickstart_rom_file="%CD%\AROS\aros-amiga-m68k-rom.bin" -cfgparam kickstart_ext_rom_file="%CD%\AROS\aros-amiga-m68k-ext.bin" -cfgparam filesystem2=rw,HD0:AMOSPro_System:"%CD%\AMOS",0
if exist "%ProgramFiles(x86)%\WinUAE\WinUAE.exe" if NOT exist "%CD%\AROS\aros-amiga-m68k-rom.bin" "%ProgramFiles(x86)%\WinUAE\WinUAE.exe" -f "%CD%\AMOSPro.uae" -cfgparam filesystem2=rw,HD0:AMOSPro_System:"%CD%\AMOS",0
if exist "%ProgramFiles(x86)%\WinUAE\WinUAE.exe" exit
