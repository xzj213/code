/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.29.21:32
*Mail          :  xzj213@qq.com
*Problem       :  P4072
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn=3000+5;
int n,m,;
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
	freopen("P4072.in","r",stdin);
	freopen("P4072.out","w",stdout);
   	
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
