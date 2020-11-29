#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int N = 2010;

int n;
int fac[N];
int f[N][N];

struct Solver {
  ui MOD;

  virtual void setMOD(ui MOD) { this->MOD = MOD; }

  int norm(int x) { return x >= MOD ? x - MOD : x; }

  void add(int &x, int y) {
    if ((x += y - MOD) < 0) x += MOD;
  }

  void sub(int &x, int y) {
    if ((x -= y) < 0) x += MOD;
  }

  virtual int query(int k) = 0;
};

struct Solver2 : Solver {
  int l;

  void setMOD(ui MOD) {
    Solver::setMOD(MOD);
    l = n;
    for (int i = 1; i <= n; ++i)
      if (fac[i] % MOD == 0) {
        l = i - 1;
        break;
      }
  }

  vector<ui> mul(const vector<ui> &a, const vector<ui> &b) {
    vector<ui> vec(l + 1);
    for (int i = 0; i <= l; ++i)
      for (int j = 0; j <= i; ++j)
        vec[i] += a[j] * b[i - j];
    return vec;
  }

  vector<ui> qmul(const vector<ui> &a, int k) {
    if (k == 0) {
      vector<ui> id(l + 1);
      id[0] = 1;
      return id;
    }
    auto ret = qmul(mul(a, a), k >> 1);
    if (k & 1)
      ret = mul(ret, a);
    return ret;
  }

  int query(int k) {
    if (MOD == 1) return 0;
    int t1 = n / k, t2 = n / k + 1,
        c2 = n % k, c1 = k - c2;
    vector<ui> f1(f[t1], f[t1] + l + 1), f2(f[t2], f[t2] + l + 1);
    auto res = mul(qmul(f1, c1), qmul(f2, c2));
    ui ret = 0;
    for (int i = 0; i <= l; ++i)ret += ui(fac[i]) * res[i];
    return ret % MOD;
  }
};

static ui MD, INV, R2;

struct SolverOdd : Solver {
  int nv2;

  int mpow(int x, int k) {
    if (k == 0)return 1;
    int ret = mpow(x * (ull) x % MOD, k >> 1);
    if (k & 1)
      ret = ret * (ull) x % MOD;
    return ret;
  }

  static ui reduce(ull x) {
    ui y = ui(x >> 32) - ui((ull(ui(x) * INV) * MD) >> 32);
    return int(y) < 0 ? y + MD : y;
  }

  struct Mont {
    ui x_;
    Mont() : x_(0) {}
    Mont(ui x) : x_(reduce(ull(x) * R2)) {}
    Mont &operator+=(Mont rhs) {
      x_ += rhs.x_ - MD;
      if (int(x_) < 0)x_ += MD;
      return *this;
    }
    Mont operator+(Mont rhs) const { return Mont(*this) += rhs; }
    Mont &operator*=(Mont rhs) {
      x_ = reduce(ull(x_) * rhs.x_);
      return *this;
    }
    Mont operator*(Mont rhs) const { return Mont(*this) *= rhs; }
    Mont operator-=(Mont rhs) {
      x_ -= rhs.x_;
      if (int(x_) < 0)x_ += MD;
      return *this;
    }
    ui get() const { return reduce(x_); }
  };

  Mont C[N][N];

  void setMOD(ui MOD) {
    Solver::setMOD(MOD);
    MD = MOD;
    INV = MOD;
    for (int rep = 0; rep < 4; ++rep) INV *= 2 - INV * MOD;
    R2 = -ull(MOD) % MOD;

    nv2 = (MOD + 1) >> 1;
    for (int i = 0; i <= n; ++i) {
      C[i][0] = 1;
      for (int j = 1; j <= i; ++j)
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  int query(int k) {
    if (MOD == 1) return 0;
    static Mont a[N], b[N], a1[N], b1[N], res[N];
    int t1 = n / k, t2 = n / k + 1,
        c2 = n % k, c1 = k - c2;
    Mont prd, nv;
    prd = mpow(f[t1][1], c1);
    nv = f[t1][1] == 1 ? 1 : f[t1][1] == 2 ? nv2 : MOD - nv2;
    for (int i = 1; i <= t1; ++i)
      a[i - 1] = Mont(f[t1][i]) * nv * fac[i - 1];
    prd = prd * mpow(f[t2][1], c2);
    nv = f[t2][1] == 1 ? 1 : f[t2][1] == 2 ? nv2 : MOD - nv2;
    for (int i = 1; i <= t2; ++i)
      b[i - 1] = Mont(f[t2][i]) * nv * fac[i - 1];
    res[0] = a1[0] = b1[0] = 1;
    for (int i = 1; i <= n - k; ++i) {
      Mont x = Mont();
      for (int j = 1; j <= min(i, t1 - 1); ++j)
        x += a[j] * a1[i - j] * C[i - 1][j - 1];
      Mont y = 0;
      for (int j = 1; j <= min(i, t2 - 1); ++j)
        y += b[j] * b1[i - j] * C[i - 1][j - 1];
      res[i] = x * c1 + y * c2;
      a1[i] = b1[i] = res[i];
      for (int j = 1; j <= min(i, t1 - 1); ++j)
        a1[i] -= a1[i - j] * a[j] * C[i][j];
      for (int j = 1; j <= min(i, t2 - 1); ++j)
        b1[i] -= b1[i - j] * b[j] * C[i][j];
    }
    Mont ans = 0;
    for (int i = 0; i <= n - k; ++i)
      ans += res[i] * C[i + k][i] * Mont(fac[k]);
    ans *= prd;
    return ans.get();
  }
};

int dp[N], dp1[N];

int exGcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int ret = exGcd(b, a % b, y, x);
  y -= a / b * x;
  return ret;
}

int inv(int a, int p) {
  int x, y;
  exGcd(a, p, x, y);
  if (x < 0)
    x += p;
  return x;
}

struct SolverManager : Solver {
  ui M2, MO, i2, io;
  Solver2 solver2;
  SolverOdd solverOdd;

  void setMOD(int MOD) {
    Solver::setMOD(MOD);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)fac[i] = fac[i - 1] * (ull) i % MOD;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      copy(dp, dp + n + 1, dp1);
      for (int j = 1; j <= n; ++j) {
        sub(dp1[j], dp1[j - 1]);
      }
      for (int j = 0; j <= n; ++j) {
        dp[j] = norm(MOD + norm(dp1[j] << 1) - dp[j]);
      }
      for (int j = i; j <= n; ++j) {
        f[j][i] = dp[j - i];
      }
    }

    M2 = 1, MO = MOD;
    while (MO % 2 == 0) {
      MO /= 2;
      M2 *= 2;
    }
    solver2.setMOD(M2);
    solverOdd.setMOD(MO);
    i2 = inv(MO, M2) * (ull) MO % MOD;
    io = inv(M2, MO) * (ull) M2 % MOD;
  }

  int query(int k) {
    int r2 = solver2.query(k), ro = solverOdd.query(k);
    return (r2 * (ull) i2 + ro * (ull) io) % MOD;
  }
};

SolverManager solver;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q, MOD;
  cin >> n >> q >> MOD;
  solver.setMOD(MOD);
  while (q--) {
    int k;
    cin >> k;
    cout << solver.query(k) << '\n';
  }
  return 0;
}

