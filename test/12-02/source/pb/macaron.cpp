#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxK = 4111;
const int maxN = 65;
int tst;
int a[maxN][maxN];
int n;
int coef[maxN][maxN];
int gen_rand() {
    ll x = 1LL * rand();
    x |= (rand() << 15);
    x %= mod;
    x ^= rand();
    int p = x % mod;
    p = (p + mod) % mod;
    if (p == 0) p++;
    return p;
}
const int maxL = 12;
int b[maxN][maxN];
int bits[maxK];
int f[maxK];
bool used[maxN];
int calc(int mask) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (bits[mask & a[i][j]] & 1) b[i][j] = sub(0, coef[i][j]);
            else b[i][j] = coef[i][j];
        }
    }
    memset(used, 0, sizeof used);
    int val = 1;
    for (int i = 1; i <= n; i++) {
        int ind = -1;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && (b[j][i] != 0)) {
                ind = j;
                break;
            }
        }
        if (ind == -1) return 0;
        val = mult(val, b[ind][i]);
        //if (i != ind) val = sub(0, val);
        int inv = pw(b[ind][i], mod - 2);
        used[ind] = true;
        for (int j = 1; j <= n; j++) {
            if (used[j]) continue;
            int ff = mult(b[j][i], inv);
            for (int k = 1; k <= n; k++) {
               b[j][k] = sub(b[j][k], mult(ff, b[ind][k]));
            }
        }
    }
    return val;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            coef[i][j] = gen_rand();
        }
    }
    for (int i = 0; i < (1 << maxL); i++) {
        f[i] = calc(i);
    }
    for (int i = 0; i < (1 << maxL); i++) {
        int ans = 0;
        for (int j = 0; j < (1 << maxL); j++) {
            if (!(bits[i & j] & 1)) {
                ans = sum(ans, f[j]);
            }
            else ans = sub(ans, f[j]);
        }
        if (ans != 0) cout << i << " ";
    }
    cout << '\n';
}
int main() {
    freopen("macaron.in", "r", stdin);
    freopen("macaron.out", "w", stdout);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    for (int i = 1; i < (1 << maxL); i++) {
        for (int j = 0; j < maxL; j++) {
            if (i & (1 << j)) {
                bits[i] = bits[i ^ (1 << j)] + 1;
                break;
            }
        }
    } solve();
    return 0;
}
