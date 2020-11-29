#include <cstdio>

using namespace std;

const int N = 300010;

int n, m;
int s[N], fail[N], ans[N], res[N];
int ch[N][2], match[N][2];

void dfs(int u);

int main() {
  freopen("3.in", "r", stdin);
  freopen("3.ans", "w", stdout);
  scanf("%d", &n);
  for (int rep = 1; rep < n; ++rep) {
    int u, v, f;
    scanf("%d%d%d", &u, &v, &f);
    ch[u][f] = v;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d", &s[i]);
  s[m + 1] = -1;
  match[0][s[1]] = 1;
  for (int i = 1; i <= m; ++i) {
    if (i > 1)
      fail[i] = match[fail[i - 1]][s[i]];
    for (int c = 0; c < 2; ++c) {
      if (c == s[i + 1])
        match[i][c] = i + 1;
      else
        match[i][c] = match[fail[i]][c];
    }
  }
  dfs(1);
  for (int i = 1; i < n; ++i)
    printf("%d ", ans[i]);
  printf("%d\n", ans[n]);
  return 0;
}

void dfs(int u) {
  static int dep;
  static int stk[N];
  stk[++dep] = u;

  if (res[u] == m)
    ans[stk[dep - m]] = u;

  for (int c = 0; c < 2; ++c)
    if (ch[u][c]) {
      res[ch[u][c]] = match[res[u]][c];
      dfs(ch[u][c]);
    }

  --dep;
}
