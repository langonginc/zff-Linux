#include<ctime>
using namespace std;
#include<iostream>
#include<windows.h>
int main(){
	system("color F0");
	time_t now = time(0);
	tm *ltm = localtime(&now);
	cout <<1900 + ltm->tm_year<<"Äê"<<1+ltm->tm_mon<<"ÔÂ"<<ltm->tm_mday<<"ÈÕ";
	cout <<ltm->tm_hour << ":"<< ltm->tm_min << ":"<< ltm->tm_sec << endl;
	return 0;
}
