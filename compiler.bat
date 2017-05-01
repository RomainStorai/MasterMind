@echo OFF
echo Lancement de la compilation...
gcc mastermind.c -o mastermind -std=c99 -D_POSIX_C_SOURCE=199309L
echo Compilation effectuee !
pause