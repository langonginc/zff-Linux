#include<iostream>
#include<ctime>
#include<cstdlib>
#if check_sys=='w'
	#include<windows.h>
#endif
using namespace std;
int r(int n){
	srand((unsigned)time(NULL));
	return rand()%n;
}
