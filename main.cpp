#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include"get.cpp"
#include"rand.cpp"
using namespace std;
typedef const int ci;
typedef const char cc;
typedef const double cd;
cc fu='F',you='H';

int keyboard()
{
	int ch;
	while (1)
	{
		if (_kbhit())
		{//如果有按键按下，则_kbhit()函数返回真
			ch = _getch();//使用_getch()函数获取按下的键值
			Sleep(10);
			return ch;
		}
	}
}
int check(int num){
	if(num==72)return 1;
	if(num==80)return 2;
	if(num==75)return 3;
	if(num==77)return 4;
	if(num==13)return 13;
	if(num==114)return 7;
	if(num==112)return 8;
	if(num==113)return 9;
//	else return 0;
}
ci nx[5]={0,-1,1,0,0};//sxzy
ci ny[5]={0,0,0,-1,1};
int n,field[10005][10005];
int level;
string name;
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
		cin>>n;
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
	system("cls");
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
		system("cls");
		cout<<n<<endl;
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
void maken(){
	putlevel(0);
	level=getlevel();
	printf("正在初始化……\n");
	Sleep(1000);
	printf("设定您的用户名\n");
	string UserNameSET;
	getline(cin,UserNameSET);
	putuser(UserNameSET);
	printf("即将完成……");
	Sleep(100);
	system("cls");
	Sleep(100);
}
void start(){
	system("color F0");
	printf("请稍后……\n");
	level=getlevel();
	
	system("cls");
	printf("                撞Fufu \n\n\n\n\n\n\n\n\n\n                 欢迎\n");
	if(level==-1){
		maken();
	}
	printf("                 欢迎");
	level=getlevel();
	name=getuser();
	cout<<name<<endl;
	Sleep(2000);
	"MB_OK";
}
int tr,kd;
int game(){
	//move
	int fx=n-1,fy=n-1,hx=2,hy=2;
	while(true){
		if(fx==hx&&fy==hy){
			putlevel(level+1);
			system("cls");
			printf("游戏结束，恭喜！胜利！成功晋级！\n继续游戏？[继续：q / 离开：Enter]\n");
			int r=check(keyboard());
			if(r==9)return 1;
			else return 0;
		}
		system("cls");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(field[i][j]==0)cout<<" ";
				if(field[i][j]==1)cout<<"-";
				if(field[i][j]==2)cout<<"|";
				if(field[i][j]==5)cout<<"H";
				if(field[i][j]==6)cout<<"F";
			}
			cout<<endl;
		}
		printf("\n使用“上下左右”按键以控制小人，按下R键重新开始，按下P键保存缓存\n");
		int r=check(keyboard());
		if(r==224)continue;
		cout<<r;
		
		Sleep(1000);
		if(r==7){
			system("cls");
			return 1;
		}
		if(r==8){
			system("cls");
			putpalse();
			printf("缓存加载完毕，再见\n");
			Sleep(2000);
			exit(1);
		}
		if(r>0&&r<5){
			//move
			system("cls");
			if(hx+nx[r]<=1||hx+nx[r]>=n||hy+ny[r]<=1||hy+ny[r]>=n){
				printf("ERR-ID:出界\n");
				continue;
			}
			cout<<hx<<hy<<endl;
			hx=hx+nx[r];
			hy=hy+ny[r];
			if(field[hx][hy]==0){
				field[hx][hy]=5;
				field[hx-nx[r]][hy-ny[r]]=0;
			}
			printf("成功\n");
			Sleep(1);
			cout<<hx<<hy<<endl;
			Sleep(5000);
		}
	}
}
void start_game(){
	system("cls");
	cout<<"@"<<endl;
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
	for(int i=2;i<=n-1;i++){
		for(int j=2;j<=n-1;j++){
			while(true){
				int k=r(2);
//				if(k==1&&tr>0){
//					int l=r(2)+1;
//					field[i][j]=l;
//					tr--;
//					break;
//				}
				if(k==0&&kd>0){
//					kd--;
					break;
				}
			}
		}
	}cout<<"@"<<endl;
	field[2][2]=5,field[n-1][n-1]=6;
	if(game()==1)start_game();
}
void findpalse(){
	if(getpalse()){
		game();
	}
	else{
		start_game();
	}
}
int main(){
	start();
	Sleep(1);
	findpalse();
} 
