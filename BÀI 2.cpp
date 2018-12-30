#include<stdio.h>
#include <string.h>
#include <conio.h>
struct con{
	char masc[9];
	char hotenc[30];
	char gt[4];
	con *tiepcon;
	
};
struct xe{
	char soxe[12];
	char loaixe[6];
	char hangsx[15];
	xe *tiepxe;
};
struct ho{
    char mh[5];
    char msnk[9];
    char tenchuho[30];
    char diachi[30];
    xe *dsx;
    con *dsc;
    ho *th;
};
////..................
 ho *dau;
 //----------------------khoi tao danh sach lien ket
void khoitao(ho *&dau)
{
 dau = NULL;
}
// nhap con...........................................................
void  nhapcon(con *&daucon)
{
	con *p,*q;
	char masct[9];
	char hotenct[30];
	char gtt[4];
	do{
		printf("nhap vao ma so con,go enter de dung: ");
		 fflush(stdin);
		 gets(masct);
		  if(strcmp(masct,"\0") != 0)
		   {
			p = new con;
			strcpy(p->masc,masct);
			printf("\n nhap vao ho ten:");
			fflush(stdin);
			gets(hotenct);
			printf("\nhap vào gioi tinh");
			fflush(stdin);
			gets(gtt);
			strcpy(p->hotenc,hotenct);
			strcpy(p->gt,gtt);
			p->tiepcon=NULL;
			//moc nut vao danh sach
			if(daucon==NULL)
			  daucon=p;
			else
			 q->tiepcon=p;
			 q=p;
	      	}
		
	} while(strcmp(masct, "\0") != 0);
}
/// nhap xe..................................................
void nhapxe(xe *&dauxe)
{
	xe *p,*q;
	char soxet[12];
	char loaixet[30];
	char hangsxt[114];
	do{
		printf("nhap vao ma so xe,go enter de dung: ");
		 fflush(stdin);
		 gets(soxet);
		  if(strcmp(soxet,"\0") != 0)
		   {
			p = new xe;
			strcpy(p->soxe,soxet);
			printf("\n nhap vao loai xe:");
			fflush(stdin);
			gets(loaixet);
			printf("\nhap vào hang san xuat");
			fflush(stdin);
			gets(hangsxt);
			strcpy(p->loaixe,loaixet);
			strcpy(p->hangsx,hangsxt);
			p->tiepxe=NULL;
			//moc nut vao danh sach
			if(dauxe==NULL)
			  dauxe=p;
			else
			 q->tiepxe=p;
			 q=p;
	      	}
		
	} while(strcmp(soxet, "\0") != 0);
}
//nhap ho ...................................................
void nhapho(ho *&dsh)
{
	char mht[5];
    char msnkt[9];
    char tenchuhot[30];
    char diachit[30];
	ho *p,*q;
	
	do{
		printf("nhap vao so ho khau: ");
		fflush(stdin);
		gets(mht);
		if(strcmp(mht,"\0") != 0)
		{
			p=new ho;
			strcpy(p->mh,mht);
			printf("nhap vao ma nhan khau cua chu ho : ");
			fflush(stdin);
			gets(msnkt);
			printf("nhap vao ho ten chu ho : ");
			fflush(stdin);
			gets(tenchuhot);
			printf("nhap vào dia chi " );
			fflush(stdin);
			gets(diachit);
			  	strcpy(p->msnk,msnkt);
			  	strcpy(p->tenchuho,tenchuhot);
			  	strcpy(p->diachi,diachit);
			  	p-> dsc = NULL;
			  	p-> dsx = NULL;
			printf("\n nhap xe \n");
			  	nhapxe(p->dsx);
			printf("\n nhap con \n");
			nhapcon(p->dsc);
		if(dsh==NULL)
                    dsh=p;
                else
                    q->th=p;
                    q=p;
                
		}
	}while(strcmp(mht, "\0") != 0);
}
// in ra danh sach thanh viên cua mot ho (cho so ho khau)
int socon(con *tvcon)
{
	if(tvcon == NULL)
	 printf("\n \n ");
	 else
	  printf("%d%d%d",tvcon->hotenc,tvcon->masc,tvcon->gt);
	  socon(tvcon->tiepcon);
}
void thanhvienho(ho *dau)
{
	char tam[5];
	fflush(stdin);
	  printf("\n nhap vao ma ho ");
	  gets(tam);
	  if(dau != NULL)
	  {
	  	if((strcmp(dau->mh,tam)) == 0)
	  	  printf("\n %d",dau->mh);
	  	  printf("\n");
	  	  socon(dau->dsc);
	  }
}
// tim xem cac ho co xe cua mot hang có ten nhap tu bàn phim
void hohx(xe *dau)
{
	char tam[15];
	fflush(stdin);
	printf("\n nhap vao xe:");
	 gets(tam);
	 if(dau != NULL)
	 {
	 	if(strcmp(dau->hangsx,tam) == 0)
	 	 printf("\n %d",dau->hangsx);
	  }
}
// xoa xe
void xoaxe1(xe *&dau){
	char tam[12];
	printf("\n Nhap ma xe can xoa: ");
	fflush(stdin);
	 gets(tam);
	if(dau != NULL)
	{
		if(strcmp(dau->soxe,tam) == 0)
		dau = dau->tiepxe;
		xoaxe1(dau->tiepxe);	
	}
} 

//d : xoa xe cua 1 ho
void xoaxe1ho(ho *&dau)
{
	char mahotam[12];
	printf("\n Nhap ma ho can xoa: ");
	fflush(stdin); 
	gets(mahotam);
	if(dau != NULL)
	    {
				if(strcmp(dau->msnk,mahotam) == 0)
					xoaxe1(dau->dsx);
				xoaxe1ho(dau->th);
		}
	} 
int main(){
	khoitao(dau);
	nhapho(dau);
	thanhvienho(dau);
	printf("\n danh sách thanh vien cau 1 ho :");
	xoaxe1ho(dau);
}

