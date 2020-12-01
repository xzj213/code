/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.30.16:36
*Mail          :  xzj213@qq.com
*Problem       :  P3648
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000+5;
int f[maxn],n,K,g[maxn],s[maxn],pre[maxn][200+5],q[maxn];
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
	return (g[i]-s[i]*s[i])-(g[j]-s[j]*s[j]);
}
int calc_down(int i,int j) {
	if (s[i]==s[j]) return -1e18;
	return s[i]-s[j];
}
long double slope(int i,int j) {
	if (s[i]==s[j]) return -1e18;
	return 1.*(g[i]-s[i]*s[i]-g[j]+s[j]*s[j])/(s[j]-s[i]);
}
signed main() {
	freopen("P3648.in","r",stdin);
	freopen("P3648.out","w",stdout);
    n=read();K=read();
	for (int i=1;i<=n;i++) {
		int x=read();
		s[i]=s[i-1]+x;
	}
	for (int k=1;k<=K;k++) {
		int h=1,t=1;
		q[1]=0;
		for (int i=1;i<=n;i++) {
//			while(h<t && calc_up(q[h],q[h+1])<=-s[i]*calc_down(q[h],q[h+1])) h++;
			while(h<t && slope(q[h],q[h+1])<=s[i]) h++;
			int j=q[h];
	//		cout<<j<<endl;
			f[i]=g[j]+s[j]*(s[i]-s[j]);
			pre[i][k]=j;
//			while(h<t && calc_up(q[t],q[t-1])*calc_down(i,q[t])<=calc_down(q[t],q[t-1])*calc_up(i,q[t])) t--;
			while(h<t && slope(q[t-1],q[t])>=slope(q[t],i)) t--;
			q[++t]=i;
		}
		for (int i=1;i<=n;i++) g[i]=f[i];
	}
	cout<<f[n]<<endl;
	int x=n;
	for (int i=K;i>=1;i--) {
		cout<<pre[x][i]<<(i==1?'\n':' ');
		x=pre[x][i];
	}
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
