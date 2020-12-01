#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 20000005
#define eps 1e-10
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
	res = 0;T f = 1;char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	res *= f;
}
template<class T>
void out(T x) {
	if(x < 0) {x = -x;putchar('-');}
	if(x >= 10) {
		out(x / 10);
	}
	putchar('0' + x % 10);
}
const int MOD = 1000000007;
int inc(int a,int b) {
	return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
	return 1LL * a * b % MOD;
}
void update(int &x,int y) {
	x = inc(x,y);
}
int fpow(int x,int c) {
	int res = 1,t = x;
	while(c) {
		if(c & 1) res = mul(res,t);
		t = mul(t,t);
		c >>= 1;
	}
	return res;
}
int dp[150][405],N,f[150][405][405],w,ans;
int a[405],b[405],fac[405],invfac[405];
bool visa[405],visb[405],vis[405][405];
int cnt[405][405],g[405];
int A(int n,int m) {
	if(n < m) return 0;
	return mul(fac[n],invfac[n - m]);
}
void Solve() {
	read(N);
	for(int i = 1 ; i <= N ; ++i) read(a[i]);
	for(int i = 1 ; i <= N ; ++i) read(b[i]);
	fac[0] = 1;
	for(int i = 1 ; i <= N ; ++i) fac[i] = mul(fac[i - 1],i);
	invfac[N] = fpow(fac[N],MOD - 2);
	for(int i = N - 1 ; i >= 0 ; --i) invfac[i] = mul(invfac[i + 1],i + 1);
	dp[1][2] = 1;
	for(int i = 1 ; i < N / 3 ; ++i) {
		for(int j = 0 ; j <= i * 2 ; ++j) {
			for(int h = 0 ; h <= j; ++h) {
				update(dp[i + 1][j + 2 - h],mul(A(j,h),dp[i][j]));
			}
		}
	}
	for(int j = 0 ; j <= (N / 3) * 2 ; ++j) update(w,mul(dp[N / 3][j],fac[j]));
	for(int i = 1 ; i <= N ; ++i) {
		visa[a[i]] = 1;
		cnt[i][0] = i;
		memset(visb,0,sizeof(visb));
		for(int j = 1 ; j <= N ; ++j) {
			visb[b[j]] = 1;
			cnt[i][j] = cnt[i][j - 1];
			if(!visa[b[j]]) cnt[i][j]++;
			if(!visa[b[j]] && !visb[a[i]]) vis[i][j] = 1;
		}
	}
	for(int t = N / 3 ; t >= 1 ; --t) {
		memset(g,0,sizeof(g));

		for(int i = N ; i >= 1 ; --i) {
			int s = (t == N / 3);
			for(int j = N ; j >= 1 ; --j) {
				if(vis[i][j]) f[t][i][j] = mul(s,N - 3 * (N / 3 - t) - cnt[i][j]);
				update(s,g[j]);
				update(g[j],f[t + 1][i][j]);
			}
		}
	}
	for(int i = 1 ; i <= N ; ++i) {
		for(int j = 1 ; j <= N ; ++j) {
			update(ans,f[1][i][j]);
		}
	}
	ans = mul(ans,w);
	out(ans);enter;
}
int main() {
	freopen("gourds.in","r",stdin);
	freopen("gourds.out","w",stdout);
	Solve();
}
