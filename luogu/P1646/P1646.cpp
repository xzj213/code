/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.27.20:16
*Mail          :  xzj213@qq.com
*Problem       :  P1646
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5000000+5,maxm=5000000+5,inf=0x3f3f3f3f3f3f3f3f;
int n,m,tot=1,beg[maxn],level[maxn],cnt,ans,s,t,sum;
struct edge{
	int nex,to,w;
}e[maxm*2];
void add(int x,int y,int z) {
	e[++tot]=(edge){beg[x],y,z};beg[x]=tot;
	e[++tot]=(edge){beg[y],x,0};beg[y]=tot;
}
int ID(int i,int j) {return (i-1)*m+j;}
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
    int x=0,f=1;
    char ch=getchar();
    while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
    while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
    return x*f;
}
bool bfs() {
	memset(level,0,sizeof(level));
	queue<int>q;
	level[s]=1;
	q.push(s);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		for (int i=beg[now];i;i=e[i].nex) {
			int nex=e[i].to;
			if (e[i].w && !level[nex]) {
				level[nex]=level[now]+1;
				q.push(nex);
				if (nex==t) return true;
			}
		}
	}
	return false;
}
int dinic(int now,int flow) {
	if (now==t) return flow;
	int rest=flow,inc;
	for (int i=beg[now];i && rest;i=e[i].nex) {
		int nex=e[i].to;
		if (e[i].w && level[nex]==level[now]+1) {
			inc=dinic(nex,min(e[i].w,rest));
			if (!inc) level[nex]=0;
			e[i].w-=inc;
			e[i^1].w+=inc;
			rest-=inc;
		}
	}
	return flow-rest;
}
signed main() {
    freopen("P1646.in","r",stdin);
    freopen("P1646.out","w",stdout);
 	n=read();m=read();
	s=0;t=10*n*m+1;cnt=n*m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int x=read();
			sum+=x;
			add(s,ID(i,j),x);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int x=read();
			sum+=x;
			add(ID(i,j),t,x);
		}
	}
	for (int i=1;i<n;i++) {
		for (int j=1;j<=m;j++) {
			int x=read();
			sum+=x;
			add(s,++cnt,x);
			add(cnt,ID(i,j),inf);
			add(cnt,ID(i+1,j),inf);
		}
	}
	for (int i=1;i<n;i++) {
		for (int j=1;j<=m;j++) {
			int x=read();
			sum+=x;
			add(++cnt,t,x);
			add(ID(i,j),cnt,inf);
			add(ID(i+1,j),cnt,inf);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<m;j++) {
			int x=read();
			sum+=x;
			add(s,++cnt,x);
			add(cnt,ID(i,j),inf);
			add(cnt,ID(i,j+1),inf);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<m;j++) {
			int x=read();
			sum+=x;
			add(++cnt,t,x);
			add(ID(i,j),cnt,inf);
			add(ID(i,j+1),cnt,inf);
		}
	}
	while(bfs()) ans+=dinic(s,inf);
	cout<<sum-ans<<endl;
	cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
