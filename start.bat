taskkill /f /im start.exe 2>nul
gcc -c Tasks_and_solutions.c -o main.o
gcc main.o -o start.exe
start.exe
