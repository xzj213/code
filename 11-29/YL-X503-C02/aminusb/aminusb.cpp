/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.29.08:14
*Mail          :  xzj213@qq.com
*Problem       :  aminusb
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5,Mod=998244353;
int n,a[maxn],T;
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
signed main() {
	freopen("aminusb.in","r",stdin);
	freopen("aminusb.out","w",stdout);
	T=read();
	while(T--) {
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		cout<<((a[1]-a[2])%Mod+Mod)%Mod<<endl;
	}
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
