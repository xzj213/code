/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.26.15:46
*Mail          :  xzj213@qq.com
*Problem       :  squares
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=1e9+7;
int n,m,ans;
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
    freopen("squares.in","r",stdin);
    freopen("squares.out","w",stdout);
	n=read();m=read();if (n>m) swap(n,m);
	for (int i=1;i<=n;i++) {
		int sum=(n-i+1)*(m-i+1);
		ans+=(sum*i)%Mod;ans%=Mod;
	}
	cout<<ans<<endl;
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
