#include <bits/stdc++.h>
namespace my_std {
using namespace std;
#define pii pair<int, int>
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define drep(i, x, y) for (int i = (x); i >= (y); i--)
#define templ template <typename T>
#define sz 201010
typedef long long ll;
templ inline void read(T &t) {
    t = 0;
    char f = 0, ch = getchar();
    while (ch > '9' || ch < '0')
        f |= (ch == '-'), ch = getchar();
    while (ch <= '9' && ch >= '0')
        t = t * 10 + ch - 48, ch = getchar();
    t = (f ? -t : t);
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args) {
    read(t);
    read(args...);
}
} // namespace my_std
using namespace my_std;

int n, Q;
int a[sz];
int R[sz], del[sz];

void work() {
    read(n, Q);
    rep(i, 0, n - 1) read(a[i]), a[i] -= n;
    a[n] = 0;
    rep(i, n + 1, n + n + 1) a[i] = a[i - n - 1];
    rep(i, 0, n + n + 1) R[i] = -1, del[i] = 0;
    static int st[sz];
    int tp = 0;
    drep(i, n + n + 1, 0) if (a[i] == -1) st[++tp] = i;
    else if (a[i] && tp) del[st[tp]] = R[i] = st[tp] - i, --tp;
    rep(i, n + 1, n + n + 1) del[i - n - 1] = del[i];
    while (Q--) {
        ll x;
        read(x);
        int y = x % n;
        x /= n;
        int t = (y - x % (n + 1) + (n + 1)) % (n + 1);
        if (a[t] == 1 && (R[t] == -1 || R[t] > x))
            printf("%d\n", n + 1);
        else if (a[y] == -1 && (!del[y] || del[y] > x))
            printf("%d\n", n - 1);
        else
            printf("%d\n", n);
    }
}

int main() {
    freopen("monologue.in", "r", stdin);
    freopen("monologue.out", "w", stdout);
    int T=1;
    while (T--)
        work();
    return 0;
}
