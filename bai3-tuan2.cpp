# include <stdio.h>
# include <iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<fstream>
using namespace std;
ifstream f("D:/input3.txt");
class NhanVien{
	private:
     string ma,hoten,chucvu,luong;
	 int hsl,hesochucvu,thang,nam;
	public:
		void nhap();
		int TinhLuong();
		void xuat();	
	friend class DSNV;
};
void NhanVien::nhap()
{
	string s;
		  getline(f,s);ma = s;
		  getline(f,s);hoten = s;
		  getline(f,s);chucvu = s;
		  getline(f,s);hsl=atoi(s.c_str());
		  getline(f,s);hesochucvu=atoi(s.c_str());
		  getline(f,s);thang=atoi(s.c_str());
		  getline(f,s);nam=atoi(s.c_str());
}


void NhanVien::xuat()
{
	cout<<ma<<"\t"<<hoten<<"\t"<<thang<<"\t"<<nam<<"\t"<<hsl<<"\t"<<hesochucvu<<"\t"<<TinhLuong()<<"\t";
	printf("\n");
}
int NhanVien::TinhLuong(){
	int luong=0,luongcb=1500;
	return luong=luongcb*(hsl+hesochucvu);
}
class DSNV {
	private:
	int n;
	vector<NhanVien>ds;
	public:
		public :
		 void nhapDS()
		 {
		      if (f.fail())
					cout << "Failed to open this file!" << endl;
				else
					{
						string s;
						getline(f, s); 
						n = atoi(s.c_str());
			 			ds.resize(n);// thay doi so luong phan tu cua vector
			  			cout << n << endl;
			 		    for (int i = 0; i < ds.size(); i++)
						  {
			 					ds[i].nhap();
							}
						f.close();
					}
		}
        void xuatDS()
		{     	
	       for(int i=0;i<ds.size();i++)   
	       {
	           ds[i].xuat();
	        }
	          cout<<endl;
        }
        
        // sap xep bang luong theo thu tu tang dan cot luong
        void sapxepluong()
        {
        	for(int i=0;i<ds.size()-1;i++)
        	   for(int j=i+1;j<ds.size();j++)
        	    if(ds[i].TinhLuong() >ds[j].TinhLuong())
        	        swap(ds[i],ds[j]);
        }
        // tim kiem thong tin nhan vien theo ma so
        void timkiem()
        {
        	string maso;
        	cout<<"nhap vao ma so nhan vien can tim :";
            getline(cin, maso);
        	for(int i=0;i<ds.size();i++)
        	   if(ds[i].ma == maso)
        	   {
        	   	 ds[i].xuat();
        	   	 break;
        	    }
        }
        // xoa thông tin nhan viên theo ma so
        void xoa()
        {
        	string maso;
        	cout<<" nhap vao ma so nhan vien can xoa :";
        	getline(cin, maso);
        	for(int i=0;i<ds.size();i++)
        	  if(ds[i].ma == maso)
        	  {
        	  	ds.erase(ds.begin() + i); // xoa 1 phan chuoi 
        	  	n--;
        	  	break;
        	   }
        	   printf("\n xoa thanh cong\n");
        }       
};
int main()
{	  
    DSNV nv;
	nv.nhapDS();
	nv.xuatDS();
	nv.sapxepluong();
	nv.timkiem();	
	nv.xoa();
	nv.xuatDS();		
	}
