#include <cstdio>
#include <cstring>

const int N=1e5+5,M=205;
int n,k,a[N],q[N],pre[N][M];
long long s[N],f[N],g[N];

double slope(int i,int j) {
	if(s[i]==s[j]) return -1e18;
	return 1.0*((g[i]-s[i]*s[i])-(g[j]-s[j]*s[j]))/(s[j]-s[i]);
}
int main() {
	freopen("data.out","r",stdin);
	freopen("answer.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	for(int j=1;j<=k;++j) {
		int l=1,r=0;
		q[++r]=0;
		for(int i=1;i<=n;++i) {
			while(l<r&&slope(q[l],q[l+1])<=s[i]) ++l;
			f[i]=g[q[l]]+s[q[l]]*(s[i]-s[q[l]]);
			pre[i][j]=q[l];
			while(l<r&&slope(q[r-1],q[r])>=slope(q[r],i)) --r;
			q[++r]=i;
		}
		memcpy(g,f,sizeof(f));
	}
	printf("%lld\n",f[n]);
	for(int x=n,i=k;i>=1;--i) x=pre[x][i],printf("%d%c",x," \n"[i==1]);
	return 0;
}
