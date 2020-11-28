/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.27.15:48
*Mail          :  xzj213@qq.com
*Problem       :  P3355
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000+5,maxm=400000+5,inf=0x3f3f3f3f3f3f3f3f;
const int d[8][2]={1,2,2,1,-1,2,2,-1,1,-2,-2,1,-2,-1,-1,-2};
int n,m,tot=1,beg[maxm],vis[maxn][maxn],s,t,level[maxm],ans;
struct edge{
	int nex,to,w;
}e[maxm*2];
void add(int x,int y,int z) {
	e[++tot]=(edge){beg[x],y,z};beg[x]=tot;
	e[++tot]=(edge){beg[y],x,0};beg[y]=tot;
}
int ID(int i,int j) {
	return (i-1)*n+j;
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
    freopen("P3355.in","r",stdin);
    freopen("P3355.out","w",stdout);
    n=read();m=read();s=0;t=n*n+1;
	for (int i=1;i<=m;i++) {
		int x=read(),y=read();
		vis[x][y]=1;
	}
	for (int i=1;i<=n;i++,puts("")) 
		for (int j=1;j<=n;j++) 
			cout<<vis[i][j]<<' ';
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=n;j++) {
			if (vis[i][j]) continue;
			if ((i+j)&1) add(s,ID(i,j),1);
			else add(ID(i,j),t,1);
		}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if ((i+j)&1) {
				for (int k=0;k<8;k++) {
					int xx=i+d[k][0];
					int yy=j+d[k][1];
					if (xx<1 || xx>n || yy<1 || yy>n) continue;
					if (!vis[xx][yy]) add(ID(i,j),ID(xx,yy),inf);
				}
			}
		}
	}
	while(bfs()) ans+=dinic(s,inf);
	cout<<n*n-m-ans<<endl;
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
