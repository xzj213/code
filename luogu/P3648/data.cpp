/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.30.20:20
*Mail          :  xzj213@qq.com
*Problem       :  data
************************************************/
#include <bits/stdc++.h>
using namespace std;

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
	freopen("data.out","w",stdout);
    int n=10;
	int m=rand()%7+1;
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=n;i++) 
		cout<<rand()%10000<<' ';puts("");
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
