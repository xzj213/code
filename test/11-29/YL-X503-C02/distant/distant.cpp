/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.29.10:13
*Mail          :  xzj213@qq.com
*Problem       :  distant
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=400+5,maxm=5e4+5,Mod=998244353,inf=0x7f7f7f7f7f7f7f7f;
int tot,beg[maxn],n,m,q,ans,CNT[maxn],s,t,dis[maxn][maxn],dep,opt[maxn][maxn];
struct edge{
	int nex,to,w,op;
}e[maxm*2];
void add(int x,int y,int z,int op) {
	e[++tot]={beg[x],y,z,op};
	beg[x]=tot;
}
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
// now 当前是那个点
// sum 当前的总长度
// cnt 为匹配的括号的个数
void dfs(int now,int sum,int cnt) {
	if (now==t) if (cnt==0) ans=min(ans,sum);
	if (CNT[now]>dep) return ;
	if (cnt<0) return ;
//	if (sum+dis[now][t]>ans) return ;
//	if (cnt>opt[now][t]) return ;
	for (int i=beg[now];i;i=e[i].nex) {
		int nex=e[i].to;
		CNT[nex]++;
		if (e[i].op==2 && cnt) dfs(nex,sum+e[i].w,cnt-1);
		if (e[i].op==1) dfs(nex,sum+e[i].w,cnt+1);
		CNT[nex]--;
	}
}
signed main() {
	freopen("distant.in","r",stdin);
	freopen("distant.out","w",stdout);
    n=read();m=read();q=read();
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=m;i++) {
		int x=read(),y=read(),z=read(),op=read();
		add(x,y,z,op);	
		dis[x][y]=z;
		opt[x][y]=op-1;
	}
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int k=1;k<=n;k++) 
		for (int i=1;i<=n;i++) 
			for (int j=1;j<=n;j++) 
				chkmin(dis[i][j],dis[i][k]+dis[k][j]);
	for (int k=1;k<=n;k++) 
		for (int i=1;i<=n;i++) 
			for (int j=1;j<=n;j++) 
				chkmax(opt[i][j],opt[i][k]+opt[k][j]);
	for (int i=1;i<=q;i++) {
		s=read(),t=read();
		for (dep=0;dep<=5;dep++) {
			ans=inf;
			dfs(s,0,0);
			if (ans!=inf) break; 
		}
		cout<<(ans==inf?-1:(ans%Mod))<<endl;
	}
//	cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
