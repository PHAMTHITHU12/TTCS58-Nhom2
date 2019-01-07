#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
/*
cau1 ; viet chuong trinh  tim ra so n  ngau nhien  tu 1 den m
intput: nhap vao so  m=n (n<m)
output : int ra so ngau nhien lon nhat n
*/
//m:can tren cua so ngau nhien (n<m)
void nhapngaunhien(int n, int m)
{
	do{
	 cout<<"\n nhap vao n so  ngau  ngien :";
	 cin>>n;
	 cout<<"\n nhap vao m: ";
	 cin>>m;
	 }while(n<m);
	 srand(time(NULL));// ham nhap so ngau nhien
	 for(int i=0;i<=n;i++)
	  cout<<rand()%m <<"	";
}
void xuat(int n,int m)
{
	for(int i=0;i<=n;i++)
	  cout<< m <<"  ";
}
int main()
{
	int n,m;
	nhapngaunhien(n,m);
	xuat(n,m);
	
}
