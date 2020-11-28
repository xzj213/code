/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.27.09:37
*Mail          :  xzj213@qq.com
*Problem       :  CF842D
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
int tr[maxn*21][2],n,m,tot=1,siz[maxn*21];
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
    int x=0,f=1;
    char ch=getchar();
    while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
    while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
    return x*f;
}
void insert(int k,int i,int x) {
	if (i<0) {
		siz[k]=1;
		return ;
	}
	int bit=(x>>i)&1;
	if (!tr[k][bit]) tr[k][bit]=++tot;
	insert(tr[k][bit],i-1,x);
	siz[k]=siz[tr[k][0]]+siz[tr[k][1]];
}
int query(int x) {
	int k=1,res=0;
	for (int i=20;i>=0;i--) {
		int bit=(x>>i)&1;
		if (siz[tr[k][bit]]==(1<<i)) {
			k=tr[k][bit^1];
			res+=(1<<i);
		}
		else k=tr[k][bit];
		if (!k) return res;
	}
	return res;
}
signed main() {
    freopen("CF842D.in","r",stdin);
    freopen("CF842D.out","w",stdout);
    n=read();m=read();
	for (int i=1;i<=n;i++) {
		int x=read();
		insert(1,20,x);
	}
	for (int i=1,x=0;i<=m;i++) {
		int y=read();x^=y;
		cout<<query(x)<<endl;
	}
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
