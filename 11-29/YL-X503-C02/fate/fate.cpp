/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.29.11:35
*Mail          :  xzj213@qq.com
*Problem       :  fate
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=2000+5;
int f[maxn],n,q,Mod;
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
	freopen("fate.in","r",stdin);
	freopen("fate.out","w",stdout);
    n=read();q=read();Mod=read();
	f[0]=1;f[1]=1;f[2]=0;f[3]=0;
	for (int i=4;i<=n;i++) {
		int a=(i+1)*f[i-1];
		int b=(i-2)*f[i-2];
		int c=(i-5)*f[i-3];
		int d=(i-3)*f[i-4];
		f[i]=((a-b-c+d)%Mod+Mod)%Mod;
	}
	for (int i=1;i<=q;i++) {
		int x=read();
		cout<<f[n]%Mod<<endl;
	}
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
