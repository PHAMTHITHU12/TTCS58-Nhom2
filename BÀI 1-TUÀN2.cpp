#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;
FILE*p;
void nhapngaunhien(int a[][100] , int &n,int m)
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
void GhiFile(int a[][100],int n,int m)
{
	FILE*pFile;
	pFile=fopen("D:\\output1.txt","wt"); 
	fprintf(pFile,"So Luong Cac Phan Tu:%d\n",n); 
	for(int i=0;i<n;i++)
	   for(int j=0;j<m;j++)
	{
		a[i][j]=rand()%51; // nhap ngau nhien
		fprintf(pFile,"%4d%d",a[i][j]);// ghi cac gia tri vao cac phan tu tron mang
	}
	fclose(pFile); // Ðóng file .
}
void DocFile(int a[][100],int n,int m)
{
	FILE*pFile;
	pFile=fopen("D:\\output1.txt","r+t"); 
	if(pFile==NULL)
	{
		printf("\n Khong doc duoc File ");
	}
	else
	{
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++)
		{
			fscanf(pFile,"%d%d\t",&a[i][j]); // doc cac gia tri phan tu trong file ra
			printf("a[%d][%d]=%d%d\n",i,a[i][j]); //xuat ca gia tri ra mang hing
		}
	}
	fclose(pFile); // Ðóng file .
}
void XuatMaTran(int a[][100], int n,int m)
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
void XoaDong(int a[][100],int &n,int m)
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
}
// xoa cot thu j trong ma tran
void XoaCot(int a[][100],int n, int &m)
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
}
// kiem tra ma tran  co dôi xaung không
int DoiXung(int n, int A[100][100])
{
    int i, j;
       for(i=0; i<n; i++)
        {          
          for(j=0; j<n; j++)
            {
              if(A[i][j] !=A[j][i])
                return 0;
            }
        }
    return 1;
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
int soluongphantuhoanghau(int a[100][100],int n,int m)
{
	int dem=0;
	FILE*pFile;
	pFile=fopen("D:\\output1.txt","wt");
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	    {
	    	if(SoHoangHau(a,i,j,n,m)==1)
	    	   dem++;
	    }
    cout<<"\n So luong cac so hoang hau trong ma tran \n";
}
void XuatMang(int a[][100],int n,int m)
{
	FILE*pFile;
	pFile=fopen("D:\\output1.txt","at"); 
	fprintf(pFile,"soluongphantuhoanghau:\n"); // Ghi vào file .
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	{
		fprintf(pFile,"%4d4%d",a[i][j]); // Ghi vào file .
	}
	fclose(pFile); // Ðóng file .
}

int main()
{

   
    int n, m;
	int a[100][100];
	 GhiFile(a,n,m);
	 DocFile(a,n,m);
	 soluongphantuhoanghau(a,n,m);
	 XuatMang(a,n,m);
    nhapngaunhien(a,n,m);
    XuatMaTran(a,n,m);
    XoaDong(a,n,m);
    XuatMaTran(a,n,m);
    XoaCot(a,n,m);
    XuatMaTran(a,n,m);
    if(DoiXung(n, a)==0)
       {
            cout<<"\n mang vua nhap khong phai la mang doi xung"<<endl;
       }
     else
       {
           cout<<"\n mang vua nhap la mang doi xung"<<endl;
      }
     return 0; 
     
     XuatMaTran(a,n,m);
    
}
