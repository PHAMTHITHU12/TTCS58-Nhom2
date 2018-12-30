#include<stdio.h>
#include<conio.h>
#define cot 5
#define hang 5
 FILE *f;
 int a[cot][hang];
 char pathin[100], pathout[100];
 void nhaptenfile()
 {
 	printf("nhap ten file: ");
 	gets(pathin);
 }
 void docfile(char pathin[100])
 {
     f = fopen(pathin,"r");
      if (f == NULL) printf("khong tim duoc file");
      else{
			 	printf("\n tim duoc file\n");
			 	for(int i = 0; i < cot; i++)
			 	for(int j =0; j < hang; j++) 
			 	fscanf(f,"%d",&a[i][j]);
				fclose(f);
           }
 }
 void xuatfile()
 {
 	printf("\nn xuat  file out: ");
 	gets(pathout);
 }
 void finxoanoc(char pathout[100], int a[5][5], int k, int n){
 	int i;
 	if(k == n) fprintf(f,"%3d",a[k][k]);
 	else{
 		  
            {
			    for(i = k; i <= n; i++) fprintf(f,"%3d",a[k][i]);
				//in dong dau k
		 		for(i = k + 1; i <= n; i++) fprintf(f,"%3d",a[i][n]);
				 //in hang cuoi n
		 		for(i = n - 1; i >= k; i--) fprintf(f,"%3d",a[n][i]);
				 //in dong cuoi n
		 		for(i = n -1 ; i >= k + 1; i--) fprintf(f,"%3d",a[i][k]);
				 //in hang dau k
           }
		finxoanoc(pathout,a,k+1,n-1);
 	     }
 }
 
void inxoanoc (int a[5][5],int k,int n)
{
	 int i;
 	if(k == n) fprintf(f,"%3d",a[k][k]);
 	else {
			    for(i = k; i <= n; i++) printf("%3d",a[k][i]);
			   //in dong dau k
		 		for(i = k + 1; i <= n; i++) printf("%3d",a[i][n]);
				 //in hang cuoi n
		 		for(i = n - 1; i >= k; i--) printf("%3d",a[n][i]);
				 //in dong cuoi n
		 		for(i = n -1 ; i >= k + 1; i--) printf("%3d",a[i][k]);
				 //in hang dau k
           }
       inxoanoc(a,k+1,n-1);
       } 
 int main(){
 	nhaptenfile();
 	docfile(pathin);
    xuatfile();
 	f = fopen(pathout,"w");
 	finxoanoc(pathout,a,0,4);
// 	inxoan(a,0,4);
 	fclose(f);
 	return 0;
 }
