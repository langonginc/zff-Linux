/*
LanGongINC
LanGongDEV
Copyright 2020 LanGongINC
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include"get.cpp"
// #include"rand.cpp"
#include<curses.h>
#include <unistd.h>
// #include <signal.h>
// #include <termios.h>
// #include <string.h>
// #include <unistd.h>
// #include <fcntl.h>
#include "getkeyboard.cpp"
using namespace std;
typedef const int ci;
typedef const char cc;
typedef const double cd;
// int kfd = 0;
// struct termios cooked, raw;
cc fu='F',you='H';
int tr,kd,fx,fy,hx,hy,s=0;
int sysE;
int keyboard()
{
	// return getchar();
	// if(read(kfd, &c, 1) < 0)
	// {
	// 	perror("read():");
	// 	exit(-1);
	// }
	//
	// switch(c)
	// {
	// 	case KEYCODE_L:
	// 		// printf("LEFT\n");
	// 		return 75;
	// 		break;
	// 	case KEYCODE_R:
	// 		// printf("RIGHT\n");
	// 		return 77;
	// 		break;
	// 	case KEYCODE_U:
	// 		// printf("UP\n");
	// 		return 72;
	// 		break;
	// 	case KEYCODE_D:
	// 		// printf("DOWN\n");
	// 		return 80;
	// 		break;
	// 			default:
	// 						// printf("value: %c = 0x%02X = %d\n", c, c, c);
	// }
	return key::getkey();
}
void syscls()
{
	system("clear");
}
int check(int num){
	if(num==72||num=='w'||num=='W')return 1;
	if(num==80||num=='s'||num=='S')return 2;
	if(num==75||num=='a'||num=='A')return 3;
	if(num==77||num=='d'||num=='D')return 4;
	if(num==10)return 13;
	if(num==114)return 7;
	if(num==112)return 8;
	if(num==113)return 9;
	if(num==27)return 27;
	else return 0;
}
ci nx[5]={0,-1,1,0,0};//sxzy
ci ny[5]={0,0,0,-1,1};
int n,field[10005][10005];
int level;
string name;
/*

//This is for pause

bool getpalse(){
	int typeU;
	fstream file;
	file.open("palseZ.dll", ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	cin>>typeU;
	cin.rdbuf(stream_buffer_cin);
	file.close();
	if(typeU==1){
		fstream file;
		file.open("palseF.dll", ios::in);
		streambuf* stream_buffer_cout = cout.rdbuf();
		streambuf* stream_buffer_cin = cin.rdbuf();
		streambuf* stream_buffer_file = file.rdbuf();
		cin.rdbuf(stream_buffer_file);
		cin>>n>>hx>>hy>>fx>>fy;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>field[i][j];
			}
		}
		cin.rdbuf(stream_buffer_cin);
		file.close();
		return true;
	}
	return false;
}
void putpalse(){
	fstream file;
	file.open("palseZ.dll", ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	syscls();
	cout<<1;
	cout.rdbuf(stream_buffer_cout);
	file.close();
	if(1==1){
		fstream file;
		file.open("palseF.dll", ios::out);
		streambuf* stream_buffer_cout = cout.rdbuf();
		streambuf* stream_buffer_cin = cin.rdbuf();
		streambuf* stream_buffer_file = file.rdbuf();
		cout.rdbuf(stream_buffer_file);
		syscls();
		cout<<n<<hx<<hy<<fx<<hy<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<field[i][j]<<" ";
			}
			cout<<endl;
		}
		cout.rdbuf(stream_buffer_cout);
		file.close();
	}
}

//This is for pause

*/
void maken(){
	putlevel(0);
	level=getlevel();
	putboot(1);
	printf("欢迎您来到 撞FuFu游戏 本游戏由LanGongDEV出品\n");
	sleep(1);
	printf("请设定一个用户名：\n");
	string UserNameSET;
	getline(cin,UserNameSET);
	putuser(UserNameSET);
	printf("设置完成\n");
	sleep(1);
	syscls();
	sleep(1);
}
int start(){
	// system("color F0");
	system("clear");
	printf("\n\n\n              LanGongINC \n              LanGongDEV \n");
	sleep(3);
	system("clear");
	printf("欢迎\n");
	level=getlevel();
	system("clear");
	printf("                撞Fufu \n\n\n\n\n\n\n\n\n\n                 欢迎!\n");
	sleep(3);
	if(getboot()!=0){
		maken();
	}
	system("clear");
	printf("              欢迎 ");
	level=getlevel();
	name=getuser();
	cout<<name<<endl;
	printf("             您的等级%d\n\n\n\n",level);
	printf("          ---推荐使用英文输入---\n");
	sleep(2);
	if(level==-1){
		return 1;
	}
	else return 0;
}
int game(){
	s=0;
	while(true){
		if(fx==hx&&fy==hy){
			putlevel(level+1);
			system("clear");
			printf("恭喜您胜利！您的等级：%d\n继续游戏？[继续：Enter / 退出：q ]\n",level+1);
			while(1){
				int r=check(keyboard());
				if(r==9)return 0;
				else if(r==13)return 1;
				else{
					printf("------ERR4: 输入错误 请重新输入------\n");
				}
			}
		}
		system("clear");
		for(int i=1;i<=n;i++){
			for(int j=0;j<27-n;j++){
				cout<<" ";
			}
			for(int j=1;j<=n;j++){
				if(field[i][j]==0)cout<<" ";
				if(field[i][j]==1)cout<<"-";
				if(field[i][j]==2)cout<<"|";
				if(field[i][j]==5)cout<<"H";
				if(field[i][j]==6)cout<<"F";
			}
			cout<<endl;
		}
		printf("\n按上下左右键控制小人H，按‘R’键重新开始游戏,\n按‘Q’退出游戏\n");
		int r=check(keyboard());
		// printf("%d\n",r);
		// sleep(1);
		if(r==224||r==-32)continue;
		if(r==7){
			syscls();
			return 1;
		}
		if(r==9){
			syscls();
			return 0;
		}
		if(r!=1 && r!=2 && r!=3 && r!=4 && r!=0 && r!=27){
			system("clear");
			printf("------ERR4: 输入错误 请重新输入------\n");
			printf("%d",r);
			sleep(1);
			syscls();
			continue;
		}
		if(r>0&&r<5){
			//move
			system("clear");
			if(hx+nx[r]<=1||hx+nx[r]>n-1||hy+ny[r]<=1||hy+ny[r]>n-1){
				printf("----------ERR1: 出界----------\n");
				sleep(0.1);
				continue;
			}
			if(field[hx+nx[r]][hy+ny[r]]==6){
				putlevel(level+1);
				syscls();
				printf("恭喜您胜利！您的等级：%d\n继续游戏？[继续：Enter / 退出：q ]\n",level+1);
				int r=check(keyboard());
				while(1){
					int r=check(keyboard());
					if(r==9)return 0;
					else if(r==13)return 1;
					else{
						printf("------ERR4: 输入错误 请重新输入------\n");
					}
				}
			}
			if(field[hx+nx[r]][hy+ny[r]]==0){
				hx=hx+nx[r];
				hy=hy+ny[r];
				field[hx][hy]=5;
				field[hx-nx[r]][hy-ny[r]]=0;
			}
		}
		if(s>=level+5){
			s=0;
			continue;
		}
		int but[5];
		memset(but,0,sizeof(but));
		for(int i=1;i<=4;i++){
			if(fx+nx[i]<=1||fx+nx[i]>n-1||fy+ny[i]<=1||fy+ny[i]>n-1){
				but[i]=1;
			}
			if(field[fx+nx[i]][fy+ny[i]]!=0){
				but[i]=1;
			}
		}
		int tx=fx,ty=fy;
		if(hx<fx&&but[2]==0){
			fx+=nx[2];
			fy+=ny[2];
		}
		else if(hx>fx&&but[1]==0){
			fx+=nx[1];
			fy+=ny[1];
		}
		else if(hy<fy&&but[4]==0){
			fx+=nx[4];
			fy+=ny[4];
		}
		else if(hy>fy&&but[3]==0){
			fx+=nx[3];
			fy+=ny[3];
		}
		else{
			if(but[1]==0){
				fx+=nx[1];
				fy+=ny[1];
			}
			else if(but[2]==0){
				fx+=nx[2];
				fy+=ny[2];
			}
			else if(but[3]==0){
				fx+=nx[3];
				fy+=ny[3];
			}
			else if(but[4]==0){
				fx+=nx[4];
				fy+=ny[4];
			}
		}
		field[fx][fy]=6;
		field[tx][ty]=0;
		s++;
	}
}
void start_game(){
	syscls();
	memset(field,0,sizeof(field));
	if(level<=10){
		n=10,tr=24,kd=40;
	}
	else if(level<=20){
		n=12,tr=34,kd=66;
	}
	else if(level>20){
		n=15,tr=50,kd=119;
	}
	/*
	0:_
	1:-
	2:|
	5:H
	6:F
	*/
	field[1][1]=field[n][n]=1;
	field[1][n]=field[n][1]=1;
	for(int i=2;i<=n-1;i++){
		field[1][i]=field[n][i]=1;
		field[i][1]=field[i][n]=2;
	}
	// for(int i=2;i<=n-1;i++){
	// 	for(int j=2;j<=n-1;j++){
	// 		while(true){
	// 			int k=rand();
	// 			if(k==0&&kd>0){
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	//printf("NIHAO\n");
	level=getlevel();
	fx=n-1,fy=n-1,hx=2,hy=2;
	field[2][2]=5,field[n-1][n-1]=6;
	if(game()==1)start_game();
}
/*

//This is for pause

void findpalse(){
	if(getpalse()){
		game();
	}
	else{
		start_game();
	}
}

//This is for pause

*/
//This is for not pause

void findpalse(){
	start_game();
}

//This is for not pause

void goodbye(){
	printf("\n           再见！\n\n\n\n\n           LanGongINC\n           LanGongDEV\n");
}
int main(){
	// initscr();
	if(start()){
		printf("--------ERR3: start error--------\n");
		return -3;
		exit(-3);
	}
	sleep(1);
	findpalse();
	// endwin();
	return 0;
}
