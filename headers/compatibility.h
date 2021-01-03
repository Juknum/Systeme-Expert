// WINDOWS USERS
#ifdef _WIN32

#include <windows.h>

#define CLEAR system("cls")
#define ASCII	system("chcp 65001")

#endif

// LINUX USERS
#ifdef linux

#include <stdio.h>
#define CLEAR	printf("\x1b[H\x1b[J")
#define ASCII	NULL

#endif