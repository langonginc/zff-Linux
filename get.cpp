#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
int getlevel(){
	int typeU;
	fstream file;
	file.open("level.dll", ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	cin>>typeU;
	cin.rdbuf(stream_buffer_cin);
	file.close();
	return typeU;
}
void putlevel(int n){
	fstream file;
	file.open("level.dll", ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	system("clear");
	cout<<n;
	cout.rdbuf(stream_buffer_cout);
	file.close();
}
int getboot(){
	int typeU;
	fstream file;
	file.open("boot.dll", ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	cin>>typeU;
	cin.rdbuf(stream_buffer_cin);
	file.close();
	return typeU;
}
void putboot(int n){
	fstream file;
	file.open("boot.dll", ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	system("clear");
	cout<<n;
	cout.rdbuf(stream_buffer_cout);
	file.close();
}
string getuser(){
	string typeU;
	fstream file;
	file.open("user.dll", ios::in);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cin.rdbuf(stream_buffer_file);
	getline(cin,typeU);
	cin.rdbuf(stream_buffer_cin);
	file.close();
	return typeU;
}
void putuser(string n){
	fstream file;
	file.open("user.dll", ios::out);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_file = file.rdbuf();
	cout.rdbuf(stream_buffer_file);
	system("clear");
	cout<<n;
	cout.rdbuf(stream_buffer_cout);
	file.close();
}
