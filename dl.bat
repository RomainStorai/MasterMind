@echo off

rem -------------------------------------------------------------------------
set DLOAD_SCRIPT=script.vbs
echo Option Explicit                                                    >  %DLOAD_SCRIPT%
echo Dim args, http, fileSystem, adoStream, url, target, status         >> %DLOAD_SCRIPT%
echo.                                                                   >> %DLOAD_SCRIPT%
echo Set args = Wscript.Arguments                                       >> %DLOAD_SCRIPT%
echo Set http = CreateObject("WinHttp.WinHttpRequest.5.1")              >> %DLOAD_SCRIPT%
echo url = args(0)                                                      >> %DLOAD_SCRIPT%
echo target = args(1)                                                   >> %DLOAD_SCRIPT%
echo.                                                                   >> %DLOAD_SCRIPT%
echo http.Open "GET", url, False                                        >> %DLOAD_SCRIPT%
echo http.Send                                                          >> %DLOAD_SCRIPT%
echo status = http.Status                                               >> %DLOAD_SCRIPT%
echo.                                                                   >> %DLOAD_SCRIPT%
echo If status ^<^> 200 Then                                            >> %DLOAD_SCRIPT%
echo    WScript.Echo "FAILED to download: HTTP Status " ^& status       >> %DLOAD_SCRIPT%
echo    WScript.Quit 1                                                  >> %DLOAD_SCRIPT%
echo End If                                                             >> %DLOAD_SCRIPT%
echo.                                                                   >> %DLOAD_SCRIPT%
echo Set adoStream = CreateObject("ADODB.Stream")                       >> %DLOAD_SCRIPT%
echo adoStream.Open                                                     >> %DLOAD_SCRIPT%
echo adoStream.Type = 1                                                 >> %DLOAD_SCRIPT%
echo adoStream.Write http.ResponseBody                                  >> %DLOAD_SCRIPT%
echo adoStream.Position = 0                                             >> %DLOAD_SCRIPT%
echo.                                                                   >> %DLOAD_SCRIPT%
echo Set fileSystem = CreateObject("Scripting.FileSystemObject")        >> %DLOAD_SCRIPT%
echo If fileSystem.FileExists(target) Then fileSystem.DeleteFile target >> %DLOAD_SCRIPT%
echo adoStream.SaveToFile target                                        >> %DLOAD_SCRIPT%
echo adoStream.Close                                                    >> %DLOAD_SCRIPT%
echo.                                                                   >> %DLOAD_SCRIPT%
rem -------------------------------------------------------------------------

if not exist "src" mkdir src
if not exist "src/res" mkdir src/res
echo #########################
echo #       Mastermind      #
echo #########################
echo Mise a jour de Mastermind...
cscript //Nologo %DLOAD_SCRIPT% https://github.com/RomainStorai/MasterMind/blob/master/mastermind.exe?raw=true src/Mastermind.exe

if not exist "src/res/credits.txt" cscript //Nologo %DLOAD_SCRIPT% https://github.com/RomainStorai/MasterMind/blob/master/res/credits.txt?raw=true src/res/credits.txt
if not exist "src/res/logo.txt" cscript //Nologo %DLOAD_SCRIPT% https://github.com/RomainStorai/MasterMind/blob/master/res/logo.txt?raw=true src/res/logo.txt
if not exist "src/res/egle.txt" cscript //Nologo %DLOAD_SCRIPT% https://github.com/RomainStorai/MasterMind/blob/master/res/regles.txt?raw=true src/res/regles.txt
if not exist "src/res/score.txt" cscript //Nologo %DLOAD_SCRIPT% https://github.com/RomainStorai/MasterMind/blob/master/res/score.txt?raw=true src/res/score.txt
if not exist "src/res/stats.txt" cscript //Nologo %DLOAD_SCRIPT% https://github.com/RomainStorai/MasterMind/blob/master/res/stats.txt?raw=true src/res/stats.txt

src/Mastermind.exe
cscript //Nologo %DLOAD_SCRIPT% https://github.com/RomainStorai/MasterMind/blob/master/dl.bat?raw=true %~n0.bat