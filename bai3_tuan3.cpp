#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include<math.h>
using namespace std;
#define max 100
struct KhachHang{
	string MaKH;	
	string TenKH;	
	float soduTK;
	string loaiGD;
	float tienGD;
};
int n ;// bien toàn cuc cho toan chuong trinh;
KhachHang a[max];
fstream f;
ofstream g;
void docfile()
{
	f.open("customer.txt", ios::in);
		int i = 0;
		while(!f.eof())
		{
		getline(f,a[i].MaKH,'\t');
		getline(f,a[i].TenKH,'\t');
		f>>a[i].soduTK;
		i++;
		}
	f.close();
}
void xuatfile()
{
	
	for(int i = 0; i <= n ; i++)
	{
	  cout<<a[i].MaKH<<"\t"<<a[i].TenKH<<"\t"<<a[i].soduTK<<"\t"<<endl;
	}
	cout<<"\n\t\t--------------------------------------\n";
}
// them moi khach hang
void them1KH(int i)
{

	cout<<"\n Nhap ma khach hang\n: ";	fflush(stdin);
	getline(cin,a[i].MaKH);
	cout<<"\n Nhap ten khach hang:\n ";	fflush(stdin);
	getline(cin,a[i].TenKH);
	cout<<"\n Nhap so tien du trong tai khoan:\n ";
	cin>>a[i].soduTK;
}
void xuatKH(int i)
{
	f<<a[i].MaKH<< "\t" <<a[i].TenKH<< "\t" <<a[i].soduTK<<"\t " <<endl;
}
void themKH(int k){
	f.open("customer.txt", fstream::app);
	for(int i = n + 1; i <= n + k; i++){
		them1KH(i);
}
	for(int i = n + 1; i <= n + k; i++){
		xuatKH(i);
	}
	n = n + k; 
	f.close();
}
void ghifile(int i)
{
   g.open("trans.txt", ios::out  );
   cout<<"ghi du lieu thanh cong."<<"\n";	
		for(int i=0;i<n;i++)
			{
					g<<"\n du lieu duoc ghi vao file  \n";
				    g<<"\n -----------------\n";
					g<<" "<<a[i].MaKH<<"\t  "<<a[i].TenKH<<"\t	"<<a[i].soduTK<<"\n";	
            }
       g.close();
}

// thuc hien giao dich gui tien va rut tien
void thuchienGD()
{
	string tenkh;
	int tien;
	cout<<"\n nhap vao  ten khach hang : ";
	fflush(stdin);
	getline(cin,tenkh);
	for(int i=0;i<=n;i++)
	{
		if(a[i].TenKH==tenkh)// neu co ten trong danh sach 
		{
			cout<<"\n nhap vao so tien can gui:\n";
	        cin>>tien;
	        break;
		}
		else
		{
		  cout<<"\n khong co ten khach hang:";
		  break;
		}
		if(tien>a[i].soduTK)
		{
			cout<<"\n nhap vao so tien can rut:";
			cout<<"-------------------";
			break;
		}
		else
		{
		   cout<<"\n rut tien thanh cong :";
		   break;
		}
	}
	cout<<"\n";
}

//in danh sach cac khach hang
void inds(){ 
	cout<<"\n";
	for(int i=0;i<n;i++){
			cout<<" "<<a[i].MaKH<<"\t "<<a[i].TenKH<<"\t "<<a[i].soduTK<<"\n";
	}
}
//in sao ke  cho mot khach hang (cac giao dich da thuc hien) 
void insaoke()
{	
   for (int i = 0; i < n; i++)
   {
		cout<<a[i].MaKH<<a[i].tienGD<<endl;
	}	
}
int main(){
	int n;
	docfile();
	cout<<"\n \t\t  THONG TIN  GIAO DICH KHACH HANG\n";
	xuatfile();
	themKH(1);
	cout<<"\n 1.khach hang vua duoc them vao :\n";
	xuatfile();
	cout<<"\n 2.in danh sach tat cho 1 khach hang giao dich:\n";
	inds();
	cout<<"\n 3.in sao ke ";
	insaoke();
	cout<<"\n-------------------------------------------\n";
	cout<<"\n 4. thuc hien giao dich gui tien va rut tien :\n";
	thuchienGD();
    xuatfile();
	ghifile(1);
	return 0;

}

