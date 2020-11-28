/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.26.16:05
*Mail          :  xzj213@qq.com
*Problem       :  sequence
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,a[maxn],dp[maxn][4];
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
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    n=read();
	for (int i=1;i<=n;i++) {
		a[i]=read();
		dp[i][0]=dp[i-1][0]+(a[i]==1);
		dp[i][1]=max(dp[i-1][0],dp[i-1][1])+(a[i]==2);
		dp[i][2]=max(dp[i-1][2],dp[i-1][1])+(a[i]==1);
		dp[i][3]=max(dp[i-1][2],dp[i-1][3])+(a[i]==2);
	}
	cout<<max(max(dp[n][0],dp[n][1]),max(dp[n][2],dp[n][3]))<<endl;
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
