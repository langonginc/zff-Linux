#include<iostream>
using namespace std;
// char check_sys;
#ifdef _WIN64
	check_sys='w'
#endif
#ifdef _WIN32
	check_sys='w'
#endif
#ifdef _linux
	check_sys='l'
#endif
#ifdef _unix
	check_sys='u'
#endif
#ifdef __ANDROID__
	check_sys='a'
#endif
#ifdef __APPLE__
	check_sys='i'
#endif
/*
made by LanGongDEV.
Copyright 2020 LanGongINC
This is Lan-ZFF GamesFiles (LanGongZFF Check System-used).
*/
