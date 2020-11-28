/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.27.22:06
*Mail          :  xzj213@qq.com
*Problem       :  P3514
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e7+5;
int a[maxn],l[maxn],r[maxn],n,m,Max[2];
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main() {
	freopen("data.out","r",stdin);
	freopen("P3514.out","w",stdout);
    n=read();m=read();
	string str;cin>>str;
	for (int i=0;i<n;i++) a[i+1]=(str[i]=='T'?2:1);
	int sum=0;
	for (int i=1;i<=n;i++) {
		sum+=a[i];
		l[a[i]]=r[a[i]]=i;
	}
	l[sum]=1;r[sum]=n;
	Max[(sum&1)]=sum;
	int tmp=sum,L=0,R=0;
	for (int i=1;i<=n;i++) {
		tmp-=a[i];
		if (a[i]==1) {
			L=i+1;R=n;
			break;
		}
	}
	if (tmp) {
		l[tmp]=L;r[tmp]=R;
		Max[(tmp&1)]=tmp;
	}
	for (int i=n;i>=1;i--) {
		tmp-=a[i];
		if (a[i]==1) {
			L=1;R=i-1;
			break;
		}
	}
	if (tmp) if (tmp>Max[(tmp&1)]) {
		Max[(tmp&1)]=tmp;
		l[tmp]=L;r[tmp]=R;
	}
	L=l[Max[0]],R=r[Max[0]];
	tmp=Max[0];
	while(L<=R) {
		if (!L || !R) break;
		if (a[L]==2) {
			tmp-=a[L];L++;
			l[tmp]=L;
			r[tmp]=R;
		}
		if (a[R]==2) {
			tmp-=a[R];R--;
			l[tmp]=L;
			r[tmp]=R;
		}
		if (a[L]==1 && a[R]==1) {
			tmp-=(a[L]+a[R]);
			L++;R--;
			l[tmp]=L;
			r[tmp]=R;
		}
	}
	L=l[Max[1]];R=r[Max[1]];
	tmp=Max[1];
	while(L<=R) {
		if (!L || !R) break;
		if (a[L]==2) {
			tmp-=a[L];L++;
			l[tmp]=L;
			r[tmp]=R;
		}
		if (a[R]==2) {
			tmp-=a[R];R--;
			l[tmp]=L;
			r[tmp]=R;
		}
		if (a[L]==1 && a[R]==1) {
			tmp-=(a[L]+a[R]);
			L++;R--;
			l[tmp]=L;
			r[tmp]=R;
		}
	}
	
	for (int i=1;i<=m;i++) {
		int x=read();
		if (!l[x] || !r[x]) puts("NIE");
		else cout<<l[x]<<' '<<r[x]<<endl;
	}
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
