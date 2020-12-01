#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;
const ll inv2 = (mod + 1) / 2;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll inv(ll x) {
  return mpow(x, mod - 2);
}

const int N = 4096;
array<array<array<int, N>, 60>, 60> v;

int up(int x) {
  if (x < 0) return x + mod;
  return x;
}

int dw(int x) {
  if (x < mod) return x;
  return x - mod;
}

void fft(array<int, N> &a, int low, int high)
{
	if(low == high - 1)
		return;

	int len = (high - low) / 2, mid = low + len;
	fft(a, low, mid);
	fft(a, mid, high);
	
	for(int i = low; i < mid; i++)
	{
		int x1 = a[i];
		int x2 = a[i + len];

		a[i] = up(x1 - x2);
		a[i + len] = dw(x1 + x2);
	}
}

void inv_fft(array<int, N> &a, int low, int high)
{
	if(low == high - 1)
		return;

	int len = (high - low) / 2, mid = low + len;
	
	for(int i = low; i < mid; i++)
	{
		int y1 = a[i];
		int y2 = a[i + len];

		a[i] = (y1 + y2) * inv2 % mod;
		a[i + len] = (y2 - y1) * inv2 % mod;
	}
	
	inv_fft(a, low, mid);
	inv_fft(a, mid, high);
}

bool has_zero(const array<int, N>& a) {
  for (int x : a) if (x == 0) return true;
  return false;
}

vi solve(const vvi& a) {
  int n = a.size();
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    v[i][j].fill(0);
    v[i][j][a[i][j]] = rand() % mod;
    fft(v[i][j], 0, N);
  }
  array<int, N> ans;
  ans.fill(1);
  for (int j = 0; j < n; ++j) {
    assert(!has_zero(v[j][j]));
    for (int t = 0; t < N; ++t) {
      ll mul = inv(v[j][j][t]);
      ans[t] = ans[t] * (ll)v[j][j][t] % mod;
      for (int l = j; l < n; ++l) v[j][l][t] = v[j][l][t] * mul % mod;
    }
    for (int i = j + 1; i < n; ++i) {
      for (int l = j + 1; l < n; ++l) {
        for (int t = 0; t < N; ++t) {
          v[i][l][t] = (v[i][l][t] - v[j][l][t] * (ll)v[i][j][t]) % mod;
        }
      }
      v[i][j].fill(0);
    }
  }
  inv_fft(ans, 0, N);
  vi res;
  for (int i = 0; i < N; ++i) if (ans[i]) res.push_back(i);
  return res;
}

int main() {
  freopen("macaron.in", "r", stdin);
  freopen("macaron.out", "w", stdout);
  int T = 1;
  for (int test = 1; test <= T; ++test) {
    int n = 60;
    scanf("%d", &n);
    vvi a(n, vi(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      a[i][j] = rand() % 4096;
      scanf("%d", &a[i][j]);
    }
    vi res = solve(a);
    for (int i : res) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
