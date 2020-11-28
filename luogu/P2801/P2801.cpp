/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.27.08:20
*Mail          :  xzj213@qq.com
*Problem       :  P2801
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,q,a[maxn];
struct node{
	int Max,Min,len,lazy;
}tr[maxn<<2];
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
    int x=0,f=1;
    char ch=getchar();
    while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
    while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
    return x*f;
}
namespace segment_tree{
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k,int num) {
		tr[k].Max+=num;
		tr[k].Min+=num;
		tr[k].lazy+=num;
	}
	void pushdown(int k) {
		if (!tr[k].lazy) return ;
		pushup(lson,tr[k].lazy);
		pushup(rson,tr[k].lazy);
		tr[k].lazy=0;
	}
	void build(int k,int l,int r) {
		tr[k].len=r-l+1;
		if (l==r) {
			tr[k].Max=a[l];
			tr[k].Min=a[l];
			return ;
		}
		int Mid=(l+r)>>1;
		build(lson,l,Mid);
		build(rson,Mid+1,r);
		tr[k].Max=max(tr[lson].Max,tr[rson].Max);
		tr[k].Min=min(tr[lson].Min,tr[rson].Min);
	}
	void update(int k,int l,int r,int ql,int qr,int num) {
		if (l>qr || r<ql) return ;
		if (l>=ql && r<=qr) {
			pushup(k,num);
			return ;
		}
		int Mid=(l+r)>>1;
		pushdown(k);
		update(lson,l,Mid,ql,qr,num);
		update(rson,Mid+1,r,ql,qr,num);
		tr[k].Max=max(tr[lson].Max,tr[rson].Max);
		tr[k].Min=min(tr[lson].Min,tr[rson].Min);
	}
	int query(int k,int l,int r,int ql,int qr,int num) {
		if (l>qr || r<ql) return 0;
		if (l>=ql && r<=qr) {
			if (num>tr[k].Max) return 0;
			if (num<=tr[k].Min) return tr[k].len;
		}
		int Mid=(l+r)>>1;
		pushdown(k);
		return query(lson,l,Mid,ql,qr,num)+query(rson,Mid+1,r,ql,qr,num);
	}
}
using namespace segment_tree;
int main() {
    freopen("P2801.in","r",stdin);
    freopen("P2801.out","w",stdout);
    n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for (int i=1;i<=q;i++) {
		string str;
		cin>>str;
		int l=read(),r=read(),w=read();
		if (str[0]=='M') update(1,1,n,l,r,w);
		else cout<<query(1,1,n,l,r,w)<<endl;
	}
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
