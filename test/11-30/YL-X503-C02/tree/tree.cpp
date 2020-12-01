/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.30.09:17
*Mail          :  xzj213@qq.com
*Problem       :  tree
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n,tot,beg[maxn],pos[maxn],fa[maxn][25],dep[maxn],a[maxn],NOW;
struct edge{
	int nex,to;
}E[maxn*2];
struct node{
	int x,y,id;
}e[maxn];
void add(int x,int y) {
	E[++tot]=(edge){beg[x],y};
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
void dfs(int now,int F) {
	fa[now][0]=F;
	dep[now]=dep[F]+1;
	for (int i=beg[now];i;i=E[i].nex) {
		int nex=E[i].to;
		if (nex==F) continue;
		dfs(nex,now);
	}
}
bool is_fa(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=20;i>=0;i--) {
		if (tmp>=(1<<i)) {
			tmp-=(1<<i);
			x=fa[x][i];
		}
	}
	return (x==y);
}
int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if (x==y) return x; 
	for (int i=20;i>=0;i--) {
		int fx=fa[x][i];
		int fy=fa[y][i];
		if (fx!=fy) {
			x=fx;
			y=fy;
		}
	}
	return fa[x][0];
}
bool chk(int a,int b,int c) {
	int lca1=lca(a,b),lca2=lca(b,c),lca3=lca(a,c);
	if ((dep[a]-dep[lca1]+dep[b]-dep[lca1]+dep[b]-dep[lca2]+dep[c]-dep[lca2])==(dep[a]+dep[c]-dep[lca3]-dep[lca3])) return true;
	return false;
}
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    n=read();
	for (int i=1;i<n;i++) {
		int x=read(),y=read();
		add(x,y);add(y,x);
		e[i]=(node){x,y,i};
	}
	dfs(1,0);
	for (int j=1;j<=20;j++)
		for (int i=1;i<=n;i++) 
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for (int i=1;i<=n;i++) {
		int x=read();
		pos[x]=i;
		a[i]=x;
	}
	for (int i=1;i<n;i++) {
		int x=e[i].x,y=e[i].y;
		if (is_fa(pos[a[y]],x) && chk(y,x,a[y]) && is_fa(pos[a[x]],y) && chk(x,y,a[x])) {
			NOW=i;
			break;
		}
	}
	while(NOW) {
		int x=NOW;
		cout<<x<<' ';
		swap(pos[a[e[x].x]],pos[a[e[x].y]]);
		swap(a[e[x].x],a[e[x].y]);
		for (int i=1;i<n;i++) {
			NOW=0;
			int x=e[i].x,y=e[i].y;
			if (is_fa(pos[a[y]],x) && chk(y,x,a[y]) && is_fa(pos[a[x]],y) && chk(x,y,a[x])) {
				NOW=i;
				break;
			}
		}
	}
	cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
