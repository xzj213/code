/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.27.10:54
*Mail          :  xzj213@qq.com
*Problem       :  UVA10201
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5,maxm=500+5;
int n,m,T,dp[maxn][maxm];
struct node{
	int d,v;
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
bool cmp(node x,node y) {
	return x.d<y.d;
}
signed main() {
    freopen("UVA10201.in","r",stdin);
    freopen("UVA10201.out","w",stdout);
    T=read();
	while(T--) {
		n=read();m=0;
		while("zyf loves p**") {
			string str;
			getline(cin,str);
			int x=0;bool flag=false;
			for (int i=0;i<str.size();i++) {
				if (str[i]==' ') {
					a[++m].d=x;x=0;
					continue;
				}
				if (str[i]>='0' && str[i]<='9') {
					x=x*10+str[i]-'0';
					flag=true;
				}
			}
			if (!flag) break;
			a[m].v=x;
		}
		sort(a+1,a+1+m,cmp);
		memset(dp,0x3f,sizeof(dp));
		dp[0][100]=0;
		for (int i=1;i<=m;i++) {
			int dist=a[i].d-a[i-1].d;
			for (int j=0;j<=200;j++)
				for (int k=0;k<=j;k++) {
					if (j-k+dist>200) continue;
					chkmin(dp[i][j],dp[i-1][j-k+dist]+a[i].v*k);
				}
		}
		if (n-a[m].d>100 || dp[m][n-a[m].d+100]==0x3f3f3f3f3f3f3f3f) 
			puts("Impossible");
		else cout<<dp[m][n-a[m].d+100]<<endl;
		if (T) puts("");
	}
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
