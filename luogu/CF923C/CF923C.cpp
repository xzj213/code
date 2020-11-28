/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.26.11:47
*Mail          :  xzj213@qq.com
*Problem       :  CF923C
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int tr[maxn*30][2],siz[maxn*30],a[maxn],b[maxn],n,tot=1;
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
    int x=0,f=1;
    char ch=getchar();
    while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
    while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
    return x*f;
}
void insert(int u,int i,int x) {
	if (i<0) {
		siz[u]++;
		return ;
	}
	int tmp=(x>>i)&1;
	if (!tr[u][tmp]) tr[u][tmp]=++tot;
	insert(tr[u][tmp],i-1,x);
	siz[u]=siz[tr[u][0]]+siz[tr[u][1]];
}
int query(int x) {
	int u=1,res=0;
	for (int i=30;~i;i--) {
		int tmp=(x>>i)&1;siz[u]--;
		if (tr[u][tmp] && siz[tr[u][tmp]]) u=tr[u][tmp];
		else {u=tr[u][tmp^1];res+=(1<<i);}
	}
	siz[u]--;
	return res;
}
int main() {
    freopen("CF923C.in","r",stdin);
    freopen("CF923C.out","w",stdout);
    n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) {
		b[i]=read();
		insert(1,30,b[i]);
	}
	for (int i=1;i<=n;i++) cout<<query(a[i])<<' ';puts("");
    return 0;
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
}
