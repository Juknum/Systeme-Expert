// WINDOWS USERS
#ifdef _WIN32

#include <windows.h>
/*
#define pause 				Sleep(1000)
#define pause_load 		Sleep(10)
*/
#define CLEAR system("cls")
#define ASCII	system("chcp 65001")

#endif

// LINUX USERS
#ifdef linux

/*
#include <unistd.h>
#define pause 				sleep(1)
#define pause_load 		sleep(0.1)
*/
#include <stdio.h>
#define CLEAR	printf("\x1b[H\x1b[J")
#define ASCII	NULL

#endif