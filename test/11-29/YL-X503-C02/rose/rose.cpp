/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.29.08:00
*Mail          :  xzj213@qq.com
*Problem       :  rose
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+4;
const int base1=131,Mod1=1e9+7;
const int base2=133,Mod2=1e9+9;
int n,m,son[maxn][2],vis[maxn],rt,dep[maxn],a[maxn],opt[maxn],Son[maxn];
int tr[maxn],nex[maxn],pos[maxn],ans[maxn],fa[maxn][25],tot,beg[maxn];
string s1[maxn],s2,str;
pair<int,int>sta,Hash[maxn];
struct edge{
	int nex,to,w;
}e[maxn*2];
void add(int x,int y,int z) {
	e[++tot]=(edge){beg[x],y,z};
	beg[x]=tot;
}
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
/*
	int dfs(int now,int Id) {
		if (Id==m+1) return now;
		return dfs(son[now][a[Id]],Id+1);
	}
	void subtask1() {
		for (int i=1;i<n;i++) {
			int x=read(),y=read(),op=read();
			son[x][op]=y;vis[y]=1;
		}
		for (int i=1;i<=n;i++) if (!vis[i]) {rt=i;break;}
		m=read();
		for (int i=1;i<=m;i++) a[i]=read();
		for (int i=1;i<=n;i++) cout<<dfs(i,1)<<(i==n?'\n':' ');
	}
	void Getnext(string str){
		nex[0]=-1;
		int i=0,j=-1,len2=str.size();
		while(i<len2){
			if(j==-1 || str[i]==str[j]){
				i++;
				j++;
				nex[i]=j;
			}
			else j=nex[j];
		}
	}
	void KMP(string str1,string str2){
		Getnext(str2);
		int i=0,j=0,len1=str1.size(),len2=str2.size();
		while(i<len1){
				if(j==len2-1 && str1[i]==str2[j]){
				pos[i-j+1]=1;
				j=nex[j];
			}
			else if(j==-1 || str1[i]==str2[j]){
				i++;
				j++;
			}
			else j=nex[j];
		}
	}
	void subtask2() {
		for (int i=1;i<n;i++) {
			int x=read(),y=read(),op=read();
			Son[x]=y;vis[y]=1;opt[x]=op;
		}
		for (int i=1;i<=n;i++) if (!vis[i]) {rt=i;break;}
		int cnt=1,now=rt;tr[1]=rt;
		while(cnt<=n) {
//			if (cnt==n) break;
			tr[++cnt]=Son[now];
			now=Son[now];
		}
		for (int i=1;i<n;i++) str+=(opt[tr[i]]+'0');
		m=read();
		for (int i=1;i<=m;i++) {
			int x=read();
			s2+=(x+'0');
		}
		KMP(str,s2);
		for (int i=1;i<=n;i++) {
			if (!pos[i]) cout<<0<<' ';
			else cout<<tr[i+m]<<' ';
//			cout<<tr[i+m]<<endl;
		}
	}
*/
	int ksm(int x,int y,int Mod) {
		int sum=1;
		while(y) {
			if (y&1) {sum*=x;sum%=Mod;}
			x*=x;x%=Mod;y>>=1;
		}
		return sum;
	}
	int findfa(int x,int m) {
		for (int i=20;i>=0;i--) {
			if (m>=(1<<i)) {
				m-=(1<<i);
				x=fa[x][i];
			}
		}
		return x;
	}
	void Dfs(int now) {
	 	for (int i=beg[now];i;i=e[i].nex) {
			int nex=e[i].to;
			Hash[nex]=make_pair((Hash[now].first*base1+e[i].w)%Mod1,(Hash[now].second*base2+e[i].w)%Mod2);
			int F=findfa(nex,m);
			int Fir=(Hash[nex].first-Hash[F].first*ksm(base1,m,Mod1)%Mod1+Mod1)%Mod1;
			int Sec=(Hash[nex].second-Hash[F].second*ksm(base2,m,Mod2)%Mod2+Mod2)%Mod2;
			if (sta==make_pair(Fir,Sec)) ans[F]=nex;
			Dfs(nex);
		}
	}
	void subtask3(){
		for (int i=1;i<n;i++) {
			int x=read(),y=read(),z=read();
			add(x,y,z);vis[y]=1;
			fa[y][0]=x;
		}
		for (int i=1;i<=n;i++) if (!vis[i]) {rt=i;break;}
		for (int j=1;j<=20;j++)
			for (int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		m=read();
		for (int i=1;i<=m;i++) {
			int x=read();	
			sta=make_pair((sta.first*base1+x)%Mod1,(sta.second*base2+x)%Mod2);
		}
		Dfs(rt);
		for (int i=1;i<=n;i++) cout<<ans[i]<<' ';puts("");
	}
}
signed main() {
	freopen("rose.in","r",stdin);
	freopen("rose.out","w",stdout);
    n=read();
//	if (n<=1e3) run::subtask1();
//	else run::subtask2();
	run::subtask3();
    return 0;
}
