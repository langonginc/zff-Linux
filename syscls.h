#include"checksys.h"
#include<iostream>
#include<cstdio>
using namespace std;
#if check_sys=='w'
	#include<windows.h>
	#define syscls() system("cls")
#endif
#if check_sys=='l' || check_sys=='u' || check_sys=='i'
	#define syscls() system("clear")
#endif
/*
made by LanGongDEV.
Copyright 2020 LanGongINC
This is Lan-ZFF GamesFiles (LanGongZFF Check System-used).
*/
