//1.khai báo du lieu de quan lý các nut thuot mot cay nhi phan tim kiem chua cac gia tri so nguyên
#include<stdio.h>
#include<conio.h>
struct nut{
	int info;
	nut*left ,*right;	
};
typedef nut Node;
// khoi tao
Node *goc,*goc1;
void khoitao(Node * &goc)
{
	goc == NULL;
}


// 2  viet thu tuc thuc hien tao mot cay nhi phan tim kiem tu cac so nguyen nhap tu ban phim,ket thuc viet nhap khi go 0
// moc nut 
void mocnut(Node *&goc,int x)
{
	if(goc == NULL)
	{
		goc = new Node;
		goc-> info = x;
		goc->left = NULL;
		goc->right = NULL;
	}
	else
	  if(goc->info >= x)
	    mocnut(goc->left , x);
	  else
	    mocnut(goc->right , x);
	    
}
void taocay(Node *&goc)
{
	int tam;
	do{
		printf("\n nhap vao mot so nguyen ,go 0 dung : \n ");
		scanf("%d",&tam);
		{
			if(tam!= 0)
			mocnut(goc , tam );
		}
	}while(tam!=0);
} 
//3. viet thu tuc duyet cay theo thu tu LNR
void duyetLNR(Node *goc)
{
	if(goc == NULL)
	  {
	  	duyetLNR(goc->left);
	  	printf("%3d",goc->info);
	  	duyetLNR(goc->right);
	  }
}
// 4. viet ham xac dinh chieu cao cua cay
int max(int a ,int b)
{
	if(a>=b)
	  return a;
	else
	  return b;
}
int  chieucao(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
	 {
	 	 if((goc->left == NULL) && (goc->right = NULL))
	 	   return 1;
	 	 else
	 	  return 1 + max(chieucao(goc->left),chieucao(goc->right));
	  }
}
// 5. viet thu tuc in ra cac nut o muc i
void inmuci(Node *goc,int i,int muc)
{
	if(goc != NULL)
	 if(muc == i)
	  printf("%3d",goc->info);
	  else
	  {
	  	inmuci(goc->left ,i,muc+1);
	  	inmuci(goc->right ,i,muc+1);
	   }
}
//6. viet thu tuc sao chep cay nhi phan tim kiem co goc duoc tro boi bien GOC1 ,thanh cay có goc duoc tro bien GOC2
void saochep(Node *goc,Node *goc1)
{
	if(goc!=NULL)
	{
		mocnut(goc,goc1->info);
		saochep(goc->left,goc1->left);
		saochep(goc->right,goc1->right);
	}
}
// xóa 1 node là lá 
void xoanutla(Node *p, Node *q)
{
	if (q->right != NULL)
	{
		xoanutla(p, q->right);
	}
	else
	{
		p->info = q->info;
		p = q;
		q = q->left;
	}



}
// 7.xoa 1 nut thuoc cay
void xoanut(Node *goc, int x)
{
	if (goc == NULL)
	{
		return;
	}
	else
	{
		if (goc->info > x)
		{
			xoanut(goc->left, x);
		}
		else if(goc->info<x)
		{
			xoanut(goc->right, x);
		}
		else
		{
			nut *p = goc;
			if (goc->left == NULL)
			{
				goc = goc->right;
			}
			else if(goc->right == NULL)
			{
				goc = goc->left;
			}
			else
			{
				xoanutla(p, goc->left);
			}
			delete p;
       }
   }

}
int main()
{
	khoitao(goc);
	taocay(goc);
	duyetLNR(goc);
	printf("\n Chieu cao cua cay: %d \n ",chieucao(goc));
	inmuci(goc,3,1);
	khoitao(goc1);
	saochep(goc,goc1);
	xoanut(goc,5);
}









