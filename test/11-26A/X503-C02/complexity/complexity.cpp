/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.26.14:47
*Mail          :  xzj213@qq.com
*Problem       :  complexity
************************************************/
#include <bits/stdc++.h>
using namespace std;
string str;
int ans;
map<string,int>vis;
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
    freopen("complexity.in","r",stdin);
    freopen("complexity.out","w",stdout);
    while(cin>>str) {
		int res=0;
		cin>>str;string tmp;
		for (int i=0;i<str.size();i++) tmp+=str[i];
		while(cin>>str) {
			int sum=0;
			if (str[0]=='E') break;
			sum+=vis[str];
			cin>>str;
			for (int i=0;i<str.size();i++) 	if (str[i]=='n') sum++;
			res=max(res,sum);
		}
		ans=max(ans,res);
		vis[tmp]=res;
	}
	if (!ans) puts("O(1)");
	else if (ans==1) puts("O(n)");
	else cout<<"O(n^"<<ans<<')'<<endl;
    //cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
