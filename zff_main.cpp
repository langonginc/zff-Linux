/*
LanGongINC
LanGongDEV
中国蓝光科技股份有限公司
中国蓝光科技开发团队DEV-TEAM
copy right 2017~2020 
*/
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
int tr,kd,fx,fy,hx,hy,s=0;

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
void maken(){
	putlevel(0);
	level=getlevel();
	putboot(1);
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
int start(){
	system("color F0");
	printf("\n\n\n              LanGongINC \n              LanGongDEV \n");
	Sleep(3000);
	system("cls");
	printf("请稍后……\n");
	level=getlevel();
	system("cls");
	printf("                撞Fufu \n\n\n\n\n\n\n\n\n\n                 欢迎\n");
	Sleep(3000);
	if(level==-1||getboot()!=1){
		maken();
	}
	system("cls");
	printf("              欢迎");
	level=getlevel();
	name=getuser();
	cout<<name<<endl;
	printf("             您的等级%d\n\n\n\n",level);
	printf("          推荐使用英文输入\n");
	Sleep(2000);
	"MB_OK";
	if(level==-1){
		return 1;
	}
	else return 0;
}
int game(){
	//move
	//fx=n-1,fy=n-1,hx=2,hy=2,
	s=0;
	while(true){
		if(fx==hx&&fy==hy){
			putlevel(level+1);
			system("cls");
			printf("游戏结束，恭喜！胜利！成功晋级！您的等级%d\n继续游戏？[继续：q / 离开：Enter]\n",level+1);
			while(1){
				int r=check(keyboard());
				if(r==9)return 1;
				else if(r==13)return 0;
				else{
					printf("ERR4: 输入无效 请重新输入……\n");
				}
			}
		}
		system("cls");
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
		printf("\n使用“上下左右”按键以控制小人，按下R键重新开始\n");
		int r=check(keyboard());
		if(r==224)continue;
		cout<<r;
//		Sleep(1000);
		if(r==7){
			system("cls");
			return 1;
		}
		/*
		if(r==8){
			system("cls");
			putpalse();
			printf("缓存加载完毕，再见\n");
			Sleep(2000);
			exit(1);
		}*/
		if(r>0&&r<5){
			//move
			system("cls");
			if(hx+nx[r]<=1||hx+nx[r]>n-1||hy+ny[r]<=1||hy+ny[r]>n-1){
				printf("----------ERR1:出界----------\n");
				Sleep(1500);
				continue;
			}
			if(field[hx+nx[r]][hy+ny[r]]==6){
				putlevel(level+1);
				system("cls");
				printf("游戏结束，恭喜！胜利！成功晋级！您的等级%d\n继续游戏？[继续：q / 离开：Enter]\n",level+1);
				int r=check(keyboard());
				while(1){
					int r=check(keyboard());
					if(r==9)return 1;
					else if(r==13)return 0;
					else{
						printf("------ERR4: 输入无效 请重新输入------\n");
					}
				}
			}
			if(field[hx+nx[r]][hy+ny[r]]==0){
				
				hx=hx+nx[r];
				hy=hy+ny[r];
				field[hx][hy]=5;
				field[hx-nx[r]][hy-ny[r]]=0;
			}
//			printf("成功\n");
//			Sleep(1);
//			cout<<hx<<hy<<endl;
//			Sleep(5000);
		}
		if(s>=5){
			s=0;
			continue;
		}
		int but[5];
		memset(but,0,sizeof(but));
		for(int i=1;i<=4;i++){
			if(fx+nx[i]<=1||fx+nx[i]>n-1||fy+ny[i]<=1||fy+ny[i]>n-1){
				but[i]=1;
				//cout<<"E2"<<fx+nx[i]<<fy+ny[i]<<n<<endl;
			}
			if(field[fx+nx[i]][fy+ny[i]]!=0){
				but[i]=1;
				//cout<<"E3"<<fx+nx[i]<<fy+ny[i]<<field[fx+nx[i]][fy+ny[i]]<<endl;
			}
		}
		/*for(int i=1;i<=4;i++){
			cout<<but[i];
		}*/
//		Sleep(7000);
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
	system("cls");
	memset(field,0,sizeof(field));
//	cout<<"@"<<endl;
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
	}
	fx=n-1,fy=n-1,hx=2,hy=2;
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
void goodbye(){
	printf("\n           欢迎下次再来！\n\n\n\n\n           LanGongINC\n           LanGongDEV\n");
}
int main(){
	if(start()){
		printf("--------ERR3: start error--------\n");
		return -3;
		exit(-3);
	}
	Sleep(1);
	findpalse();
	return 0;
} 
