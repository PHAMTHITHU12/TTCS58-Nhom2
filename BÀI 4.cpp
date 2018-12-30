#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>
void nhapngaunhien(int a[], int n)
{
	int i;
	srand(time(NULL));// hàm nhap ngau ngien 

	for(i=0;i< n;i++)
	{
     	a[i] = rand()%30;
    }

}
void xuatmang(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
// thu tuc chinh heap
void chinhheap(int a[50],int n,int i)
{
	// khoi tao
	int vt=i;
	int l= (2*i)+1;// nhanh trai
	int r= (2*i)+2;// nhanh phai
	// Neu nut con trai lon hon so voi  vi tri
	if(l<n && a[l]> a[vt])
		vt=l;
// Neu nut con phai lon hon so voi  vi tri
	if(r<n && a[r]> a[vt])
		vt=r;
	//neu i khong phai la vi tri lon nhat
	if(vt != i)
	{
		swap(a[i],a[vt]);
		//de quy lai ham
		chinhheap(a,n,i);
	}
}
// thu tuc sap xepheapsort 
void heapsort(int a[50],int n)
{
	//tao mot dong
	for(int i=n/2-1;i>=0;i--)
		chinhheap(a,n,i);
	//qua trinh dung lai khi con 1 phan tu
	for(int i=n-1;i>=0;i--)
	{
	 // hoan vi phan tu cuoi cung và phan tu dau tien cua heap
		swap(a[0],a[i]);
		//thuc hien thao tac chinh heap
		chinhheap(a,i,0);
	}
}
int main()
{
	int a[50],n,i;
	cout<<"\nnhap so phan tu cua mang: ";
	cin>>n;
	nhapngaunhien(a,n);
	xuatmang(a,n);
    chinhheap(a,n,i);
    cout<<"\n sau khi chinh heap: \n";
	xuatmang(a,n);
	heapsort(a,n);
	cout<<"\n sau khi sapxep: \n";
	xuatmang(a,n);
}
