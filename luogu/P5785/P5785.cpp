/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.26.09:43
*Mail          :  xzj213@qq.com
*Problem       :  P5785
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=100,maxm=4000+5;
int f[maxn][maxn][maxn],n,m,t,a[maxn][maxn],dp[maxn][maxm],sum[maxn][maxn];
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
    freopen("P5785.in","r",stdin);
    freopen("P5785.out","w",stdout);
    n=read();m=read();t=read();
	for (int i=1;i<=n;i++) {
		string str;
		cin>>str;
		for (int j=0;j<m;j++) a[i][j+1]=str[j]-'0';
	}
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++) 
			sum[i][j]=sum[i][j-1]+a[i][j];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			for (int k=j;k<=m;k++) {
				for (int u=j-1;u<k;u++) {
					chkmax(f[i][k][j],f[i][u][j-1]+max(k-u-(sum[i][k]-sum[i][u]),(sum[i][k]-sum[i][u])));
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=t;j++)
			for (int k=0;k<=min(m,j);k++) 
				chkmax(dp[i][j],dp[i-1][j-k]+f[i][m][k]);
	cout<<dp[n][t]<<endl;
	cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
