/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.29.18:18
*Mail          :  xzj213@qq.com
*Problem       :  P5785
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int n,s,st[maxn],sc[maxn],dp[maxn],q[maxn];
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
	return dp[i]-dp[j];
}
int calc_down(int i,int j) {
	return sc[i]-sc[j];
}
int main() {
	freopen("P5785.in","r",stdin);
	freopen("P5785.out","w",stdout);
    n=read();s=read();
	for (int i=1;i<=n;i++) {
		int t=read(),c=read();
		st[i]=st[i-1]+t;
		sc[i]=sc[i-1]+c;
		dp[i]=0x3f3f3f3f;
	}
	int hd=1,tl=1;
	dp[0]=0;
	for (int i=1;i<=n;i++) {
		while(hd<tl && calc_up(q[hd],q[hd+1])>=(st[i]+s)*calc_down(q[hd],q[hd+1])) hd++;
		int j=q[hd];
		dp[i]=dp[j]+st[i]*(sc[i]-sc[j])+s*(sc[n]-sc[j]);
		while(hd<tl && calc_up(q[tl-1],q[tl])*calc_down(q[tl],i)>=calc_down(q[tl-1],q[tl])*calc_up(q[tl],i)) tl--;
		q[++tl]=i;
	}
	cout<<dp[n]<<endl;
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
