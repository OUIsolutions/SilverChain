@echo off
gcc .\src\cli\main.c -o .\a.exe
copy .\a.exe ..\BearHttpsClient\Silverchain.exe
echo Arquivo compilado e copiado com sucesso!
