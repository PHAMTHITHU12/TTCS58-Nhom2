#include <string>
#include <iostream>
using namespace std;
// chuyen chuoi sang so

int chuoisangso(char c)     
{
    return c - '0';
}
// chuyen so sang chuoi
char sosangchuoi(int n)     
{
    return (char)(n+48);
}
 // lam 2 xau co do dai bang nhau
void chuanHoa(string &a, string &b) 
{
    int l1 = a.length();//do dai xau 1
	int l2 = b.length();// d� dai xau2
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');    // chen vao dau cua b cac ky tu '0'
    }
    else
    {
        a.insert(0, l2-l1, '0');    // chen vao dau cua a cac ky tu '0'
    }
}
 // tong 2 so lon
string Tong(string a, string b)  
{
    string s = "";
    chuanHoa(a,b);      // chuan hoa
    int l = a.length(); // l=do dai xau 1
     
    int k= 0;
      // duyet va cong don
    for (int i=l-1; i>=0; i--) 
    {
        k = chuoisangso(a[i]) + chuoisangso(b[i]) + k;    // tinh tong tung doi mot
        s.insert(0,1,sosangchuoi(k%10));         // gan phan don vi vao
         k= k/10;     // lay lai phan hang chuc
    }
    if (k>0)  // neu hang chuc > 0 thi them vao KQ
    {
        s.insert(0,1,sosangchuoi(k));
    } 
    return s;
}
//hieu 2 so (a,b)
void hoanvihaiso( string &a, string &b)
{
	string k = a;
	a = b;
	b = k;
}
string kiemtra(string a, string b)
{
	bool kiemtra= false;
	int l1 = a.length();  // do dai xau l1
	int l2 = b.length();	// do dai 2 xau  l2
	if(l1 > l2) 
	   kiemtra = false;
// neu a < b hoan vi cho nhau 
	else if(l1 < l2)
	 {
		hoanvihaiso(a,b);
		kiemtra = true;
	}
	else 
	if(l1 = l2)
	{
		for(int i = 0; i < a.length(); i++)
		{
			if(a[i] > b[i])	
			{
			kiemtra = false;
			break;
			}
			else if(a[i] < b[i])
			 {
			hoanvihaiso(a,b);
			kiemtra = true;
			break;
			}
		}	
	}
	string s = "";
    chuanHoa(a,b);      // chuan hoa
    int l = a.length();
    int k = 0;
    for (int i=l-1; i>=0; i--)
	{	
		    b[i] = b[i] + k;
		    if(a[i] >= b[i])
			{
		        k = chuoisangso(a[i]) - chuoisangso(b[i]);    // tinh hieu tung doi mot
		        s.insert(0,1,sosangchuoi(k));         // gan gia tri tinh dc
		        k = 0;    
            }
    else {
    	k = chuoisangso(a[i]) + 10 - chuoisangso(b[i]);    // tinh hieu tung doi mot
        s.insert(0,1,sosangchuoi(k));         // gan gia tri tinh dc
        k = 1;  
	}
    if (kiemtra == true)  //neu b < a them dau -
    {
        s.insert(0,1,'-');
    }
    return s;
   }
}


// nhan so co 1 chu so voi so co nhieu chu so
string NhanNho(char a, string b)    
{
    string s = "";
    int k = 0;
    for (int i=b.length()-1; i>=0; i--)      
    {
       k= chuoisangso(a) * chuoisangso(b[i]) + k; // tinh nhan tung doi mot
        s.insert(0,1,sosangchuoi(k%10));
        k = k/10;
    }
     
    if (k>0)
    {
        s.insert(0,1,sosangchuoi(k));
    } 
    return s;
}
  // nhan 2 so lon 
string Nhan(string a, string b)    
{
    string s = "";
    int l = a.length();
    string s1[l];
// nhan tung chu so cua a voi b sau do cong don vao
    for (int i=l-1; i>=0; i--)   
    {
        s1[i] = NhanNho(a[i], b);   // nhan tung so cua a voi b
        s1[i].insert(s1[i].length(), l-i-1, '0');   
        s = Tong(s, s1[i]);  // cong don theo cach cong so lon
    }
    return s;
}
 
int main()
{
    string a, b, s;
 
    cout<<"Nhap a = ";
    getline(cin, a);
    cout<<"Nhap b = ";
    getline(cin, b);
    s = Tong(a,b);
    cout<<"Tong cua a va b : "<<s<<endl;
    s = kiemtra(a,b);
    cout<<"Hieu cua a va b : "<<s<<endl;
    s = Nhan(a,b);
    cout<<"Tich cua a va b : "<<s<<endl;
    return 0; 
}
