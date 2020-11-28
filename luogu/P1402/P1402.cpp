/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.27.14:49
*Mail          :  xzj213@qq.com
*Problem       :  P1402
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100000+5,inf=0x3f3f3f3f3f3f3f3f;
int n,p,q,tot=1,beg[maxn],level[maxn],s,t,ans;
struct edge{
	int nex,to,w;
}e[maxn*2];
void add(int x,int y,int z) {
	e[++tot]=(edge){beg[x],y,z};beg[x]=tot;
	e[++tot]=(edge){beg[y],x,0};beg[y]=tot;
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
bool bfs() {
	queue<int>q;
	memset(level,0,sizeof(level));
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
			inc=dinic(nex,min(rest,e[i].w));
			if (!inc) level[nex]=0;
			e[i].w-=inc;
			e[i^1].w+=inc;
			rest-=inc;
		}
	}
	return flow-rest;
}
signed main() {
    freopen("P1402.in","r",stdin);
    freopen("P1402.out","w",stdout);
    n=read();p=read();q=read();s=0;t=4*n+1;
	for (int i=1;i<=q;i++) add(s,n+i,1);
	for (int i=1;i<=p;i++) add(2*n+i,t,1);
	for (int i=1;i<=n;i++) add(i,3*n+i,1);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=p;j++) {
			int x=read();
			if (x) add(3*n+i,2*n+j,1);
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=q;j++) {
			int x=read();
			if (x) add(n+j,i,1);
		}
	}
	while(bfs()) ans+=dinic(s,inf);
	cout<<ans<<endl;
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
