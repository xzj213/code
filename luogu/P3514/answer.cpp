#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f; 
}
inline int getc(){
	char c=getchar();
	while(c<'A'||c>'Z')c=getchar();
	return c=='W'?1:2;
}
const int maxn=1e6+10;
int n,m,a[maxn],sum[maxn],c1,c2,asl[maxn],asr[maxn];
struct node{int x,id;}od[maxn],ev[maxn];
inline int cmp(node x,node y){return x.x>y.x;}
int main(){
	//freopen("3514.in","r",stdin);
	//freopen("3514.out","w",stdout);
	freopen("data.out","r",stdin);
	freopen("answer.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=getc();
	int x,lo=0,ro,so,le=0,re,se;
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
		if(sum[i]%2){if(!lo)lo=i;ro=i;}
		else re=i;
	}
	for(int i=1;i<=m;i++){
		x=read();
		if(x&1)od[++c1]=(node){x,i};
		else ev[++c2]=(node){x,i};
	}
	sort(od+1,od+1+c1,cmp);
	sort(ev+1,ev+1+c2,cmp);
	int l,r,tot;
	if(sum[ro]-sum[le]>sum[re]-sum[lo])l=le+1,r=ro;
	else l=lo+1,r=re;tot=sum[r]-sum[l-1];
	for(int i=1;i<=c1;i++){
		while(tot>od[i].x){
			if(a[l]==2)l++;
			else if(a[r]==2)r--;
			else l++,r--;
			tot-=2;
		}
		if(tot<od[i].x)asl[od[i].id]=-1;
		else asl[od[i].id]=l,asr[od[i].id]=r;
	}
	if(sum[re]-sum[le]>sum[ro]-sum[lo])l=le+1,r=re;
	else l=lo+1,r=ro;tot=sum[r]-sum[l-1];
	for(int i=1;i<=c2;i++){
		while(tot>ev[i].x){
			if(a[l]==2)l++;
			else if(a[r]==2)r--;
			else l++,r--;
			tot-=2;
		}
		if(tot<ev[i].x)asl[ev[i].id]=-1;
		else asl[ev[i].id]=l,asr[ev[i].id]=r;
	}
	for(int i=1;i<=m;i++)
		if(asl[i]==-1)puts("NIE");
		else printf("%d %d\n",asl[i],asr[i]);
	return 0;
}
