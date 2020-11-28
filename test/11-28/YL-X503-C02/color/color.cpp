/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.28.08:13
*Mail          :  xzj213@qq.com
*Problem       :  color
************************************************/
#include <bits/stdc++.h>
using namespace std;
int n;
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    n=read();
	if (n==1) {
		cout<<1<<endl<<1<<endl;
		return 0;
	}
	if (n==2) {
		cout<<1<<endl<<"1 1"<<endl;
		return 0;
	}
	if (n==3) {
		cout<<2<<endl<<"1 1 2"<<endl;
		return 0;
	}
	if (n==4) {
		cout<<2<<endl<<"1 1 2 2"<<endl;
		return 0;
	}
	if (n==5) {
		cout<<3<<endl<<"1 1 2 2 3"<<endl;
		return 0;
	}
	if (n==6) {
		cout<<3<<endl<<"1 1 2 2 3 3"<<endl;
		return 0;
	}
	cout<<4<<endl;
	for (int i=1;i<=n;i++) cout<<(i-1)%4+1<<' ';
	puts("");
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
