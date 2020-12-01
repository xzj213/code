/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.29.22:06
*Mail          :  xzj213@qq.com
*Problem       :  P3195
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e4+5;
int dp[maxn],A[maxn],B[maxn],n,l,s[maxn],q[maxn];
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int calc_up(int i,int j) {
	return dp[i]+B[i]*B[i]-dp[j]-B[j]*B[j];
}
int calc_down(int i,int j) {
	return 2*(B[i]-B[j]);
}
signed main() {
	freopen("P3195.in","r",stdin);
	freopen("P3195.out","w",stdout);
    n=read();l=read();
	for (int i=1;i<=n;i++) {
		int x=read();
		s[i]=s[i-1]+x;
	}
	for (int i=1;i<=n;i++) {
		A[i]=s[i]+i-l-1;
		B[i]=s[i]+i;
	}
	int h=1,t=1;
	for (int i=1;i<=n;i++) {
		while(h<t && calc_up(q[h+1],q[h])<=calc_down(q[h+1],q[h])*A[i]) h++;
		int j=q[h];
		dp[i]=dp[j]+(A[i]-B[j])*(A[i]-B[j]);
		while(h<t && calc_up(q[t-1],q[t])*calc_down(q[t],i)>=calc_down(q[t-1],q[t])*calc_up(q[t],i))t--;
		q[++t]=i;
	}
	cout<<dp[n]<<endl;
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
