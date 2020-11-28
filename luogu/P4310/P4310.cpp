/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.26.09:04
*Mail          :  xzj213@qq.com
*Problem       :  P4310
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int dp[maxn],ans,n,a[maxn];
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
    freopen("P4310.in","r",stdin);
    freopen("P4310.out","w",stdout);
    n=read();
	for (int i=1;i<=n;i++) {
		a[i]=read();
		int res=0;
		for (int j=0;j<=30;j++) 
			if (a[i]&(1<<j)) chkmax(res,dp[j]+1);
		for (int j=0;j<=30;j++) 
			if (a[i]&(1<<j)) dp[j]=res;
		chkmax(ans,res);
	}
	cout<<ans<<endl;
    return 0;
}
