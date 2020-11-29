#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int L = 30, N = 1000; 

int perm[N];
int t;
int ch[N][2];
int s[N];

int main() {
    freopen("2.in", "w", stdout);
    for (int i = 0; i < L; ++i) s[i] = rng() % 2;
    int r = ++t;
    for (int rep = N / L; rep; --rep) {
        int o = rng() % t + 1;
        for (int i = 0; i < L; ++i) {
            if (!ch[o][s[i]]) {
                ch[o][s[i]] = ++t;
            }
            o = ch[o][s[i]];
        }
    }
    iota(perm + 1, perm + t + 1, 1);
    shuffle(perm + 2, perm + t + 1, rng);
    printf("%d\n", t);
    int cnt = 0;
    for (int i = t; i; --i) {
        for (int j = 0; j < 2; ++j)
            if (ch[i][j]) {
                printf("%d %d %d\n", perm[i], perm[ch[i][j]], j);
                ++cnt;
            }
    }
    cerr << cnt << '\n';
    printf("%d\n", L);
    for (int i = 0; i < L; ++i)
        printf("%d%c", s[i], " \n"[i == L - 1]);
	return 0;
}

