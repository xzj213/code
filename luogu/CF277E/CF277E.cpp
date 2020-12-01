/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.28.16:10
*Mail          :  xzj213@qq.com
*Problem       :  CF277E
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=4000000+5,inf=0x3f3f3f3f;
int n,tot=1,beg[maxn];
struct node{
	int x,y;
}a[maxn];
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
	freopen("CF277E.in","r",stdin);
	freopen("CF277E.out","w",stdout);
 	n=read();
	for ()
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
