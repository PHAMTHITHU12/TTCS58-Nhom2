#include<stdio.h>
#include<conio.h>
#include<math.h>
struct co{
	int tren,duoi;
	};
char path[80],pathout[80];
int n;
co a[29]; // du lieu luu cac quan co
int ttluu[29]; // luu trang thai cac quan co can tim
int tt[29]; // trang thai các con co
int cl;// do chenh lech
FILE *f;
void NhapTenFile()
{
	printf("Doc vao ten File: ");
	gets(path);
}
void DocFile(char path[50])
{
	f = fopen(path, "r");
	if(f==NULL)
	{
		printf("Mo file khong thanh cong!");
	}
	else
	{
		fscanf(f, "%d", &n);
		for(int i=1; i<=n; i++)
		{
		
			fscanf(f,"%d",&a[i].tren);
         	fscanf(f,"%d",&a[i].duoi);
		}
	}
}
//---------------xuat ra file--------------------
void NhapTenFileout()
{
 	printf("\nnhap ten file out: ");
 	gets(pathout);
 }
void Infile(char pathout[100])
{
	f = fopen(pathout,"w");
	int i;
	int demtt = 0;
	fprintf(f, "\ndo chenh lech nho nhat la: %d",cl);
	for(i = 1; i <= n; i++) 
	if(ttluu[i] == 1 ) 
		demtt = demtt + 1;
	fprintf(f,"\nso luong quan co phai quay la: %d \n", demtt);
	for(i = 1; i <= n; i++) 
	fprintf(f,"%3d",ttluu[i]);
}

//------------------------nhap cac quan co-------------------------
void nhapco(int &n)
{
	printf("\n nhap vao  so luong quan co ");
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		printf("\n quan co thu nhat %d : \n",i);
		printf("\n mat tren : ");
		scanf("%d",&a[i].tren);
		printf("\n mat duoi : ");
		scanf("%d",&a[i].duoi);
	}
}
//----------------------------
void ktra()
{
	int sumt=0,sumd=0;
	int k;
	int dochenh =0;
	for(int k=1;k<=n;k++)
	{
	  if(tt[k] == 0)
	  {
		sumt = sumt + a[k].tren;
		sumd = sumd + a[k].duoi;
    	}
	  else
	  {
	    sumt = sumt + a[k].duoi;
		sumd = sumd + a[k].tren;
    	}
	  dochenh=abs(sumt-sumd);
	}
	  if(dochenh < cl)
    	{
			cl=dochenh;
			for(k=1;k<=n;k++)
			ttluu[k]=tt[k];
    	}
	
}
//-------------------in ket qua------------
void ketqua()
{
	printf("\n do lenh be nhat %d",cl);
    // so luong quan co phia xoay
	int k;
	int dem=0;
	 for(int k=1;k<n;k++)
	 if(ttluu[k] == 1)
	  	  dem = dem + 1;
	printf("\n so luong quan co can phai  xoay: %d ",dem);
	for(k=1;k<=n;k++)
	printf("%3d",ttluu[k]);
}
//-------------------------- THU I ----------------------
void thu(int i)
{
	int k;
	for(k=0;k<=1;k++)
	{
		tt[i] = k;
		if(i<n) thu(i+1);
		else
		  ktra();
		  tt[i]=0;
	}
}
int main()
{
	NhapTenFile();
	DocFile(path);
    thu(1);
    ketqua();
    NhapTenFileout();
	Infile(pathout);
    
}
