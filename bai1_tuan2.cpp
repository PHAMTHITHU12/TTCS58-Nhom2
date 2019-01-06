#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int a[100][100];
int n,m;
char pathout[100];
FILE *f;
void nhaptenfileout(){
 	printf("\nnhap ten file out: ");
 	gets(pathout);
 }

void nhapngaunhien(int a[100][100] , int &n,int m)
{
	int i,j;
	{
		cout<<"Nhap so dong: ";
		cin>>n;
		cout<<"Nhap so cot: ";
		cin>>m;
		if (n != m)
			cout<<endl<<"So dong phai bang so cot"<<endl<<endl;
	}
	while (n != m);
	srand(time(NULL));// hàm nhap ngau ngien 

	for(i=0;i< n;i++)
	  for(j=0;j< m;j++)
	{
     	a[i][j] = rand()%51;
    }

}
void XuatMaTran(int a[100][100], int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n"<<endl;
    }
}
// xoa dong thu i trong ma tran 
void XoaDong(int a[100][100],int &n,int m)
{
 int dong; 
 cout<<"nhap dong can xoa:"; 
 cin>>dong;
    for(int i=dong;i<n-1;i++)
       for(int j=0;j<m;j++)
        {
            a[i][j]=a[i+1][j];
        }
    n--;   
    XuatMaTran(a,n,m);
}
// xoa cot thu j trong ma tran
void XoaCot(int a[100][100],int n, int &m)
{
 int cot; 
 cout<<"nhap cot can xoa:"; 
 cin>>cot;
 for(int i=0;i<n;i++)
    for(int j=cot;j<m-1;j++)
     {
        a[i][j]=a[i][j+1];
     }
     m--;
    XuatMaTran(a,n,m);
}
// kiem tra ma tran  co dôi xaung không
int DoiXung(int n, int a[100][100])
{
    int i, j;
       for(i=0; i<n; i++)
        {          
          for(j=0; j<n; j++)
            {
              if(a[i][j]!=a[j][i])
                return 0;
            }
        }
    return 1;
}
void kiemtradoixung(int a[100][100], int n)
{
	if(DoiXung(n,a) == 1) 
	    cout<<"\nma tran vua nhap doi xung";
	else 
	    cout<<"\n ma tran vua nhap ko doi xung";
}
// tim cac so hoang hau có trong ma tran
int SoHoangHau (int a[100][100], int n, int m,int vtsd,int vtsc)
{
	int k=a[vtsd][vtsc];
	// ktra  so lon nhat trên hang
	for(int j=0;j<n;j++)
	  if(a[vtsd][j] > k)
	    return 0;
	// ktra so lon nhat tren cot
	for(int i=0;i<n;i++)
	  if(a[i][vtsc] > k)
	   return 0;
	// ktra so lon nhat tren  duong cheo chinh
	int vtsd1 = vtsd + 1;
	int vtsc1 = vtsc + 1;
	while( vtsc1 + 1 < m && vtsd1 < vtsd )
	  {
	  	if(a[vtsc1][vtsd1] > k)
	  	    return 0;
	  	    //tang phai
	  	    vtsc1++;
	  	    vtsd1++;
	   }
	   vtsd1 = vtsd - 1;
	   vtsc1 = vtsc - 1;
	while (vtsc1 -1 >=0 && vtsd1 >=0)
	{
		if(a[vtsc1][vtsd1] > k)
		    return 0;
		  vtsc1--;
		  vtsd1--;
	}
	// kiem tra so lon nhat tren duong cheo phu
	vtsd1 = vtsd + 1;
    vtsc1 = vtsc - 1;
	while( vtsc1 - 1 >= 0 && vtsd1 < vtsd )
	  {
	  	if(a[vtsc1][vtsd1] > k)
	  	    return 0;
	  	    //tang trai
	  	    vtsc1++;
	  	    vtsd1--;
	   }
	   vtsd1 = vtsd - 1;
	   vtsc1 = vtsc + 1;
	while (vtsd1 -1 >=0 && vtsc1 < m)
	{
		if(a[vtsc1][vtsd1] > k)
		    return 0;
		  vtsc1--;
		  vtsd1++;
	}
return 1;
}

void kiemtrasohoanghau(char pathout[100],int a[100][100], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (SoHoangHau(a,n,n,i,j) == 1)
			{
				fprintf(f,"\n so hoang hau: %d: hang : %d, cot: %d",a[i][j],i,j);
				printf("\n so hoang hau: %d: hang : %d, cot: %d",a[i][j],i,j);
			}
}
int main() {

	nhaptenfileout();
 	f = fopen(pathout,"w");
	nhapngaunhien(a,n,m);
	XuatMaTran(a,n,n);
	XoaDong(a,n,n);
	XoaCot(a,n,n);
	kiemtradoixung(a,n);
	kiemtrasohoanghau(pathout,a,n);
}

