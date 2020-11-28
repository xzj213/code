/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.28.14:34
*Mail          :  xzj213@qq.com
*Problem       :  B
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,k,p,s1,s2;
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
namespace run{
	void task1() {
		int tmp=k-p*m;
		int tmp1=(tmp)/(n-p);
		if (tmp1>=m) {puts("NO");exit(0);}
		int sum=tmp/(m-1),y=tmp%(m-1);
		puts("YES");
		for (int i=1;i<=p;i++) cout<<m<<" 0"<<endl;
		for (int i=1;i<=sum;i++) cout<<m-1<<' '<<1<<endl;
		if (y) cout<<y<<' '<<m-y<<endl;
		for (int i=p+sum+1+(y!=0);i<=n;i++) cout<<"0 0"<<endl;
		exit(0);
	}
	void task2() {
		int tmp=k/p;
		int tmp1=k%p;
		if (p==n && tmp1) {puts("NO");exit(0);}
		if ((tmp1/(n-p))>=tmp) {puts("NO");exit(0);}
		puts("YES");
		for (int i=1;i<=p;i++) cout<<tmp<<' '<<m-tmp<<endl;
		if (tmp1) {
			int fk=tmp1/(n-p),Fk=tmp1%(n-p);
			for (int i=p+1;i<n;i++) {
				cout<<fk<<' '<<m-fk<<endl;
			}
			cout<<Fk+fk<<' '<<m-fk-Fk<<endl;
		}
		exit(0);
	}
}
int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
    n=read();m=read();k=read();p=read();
	int tmp=k/p;
	if (tmp>=m) run::task1();
	else run::task2();
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
