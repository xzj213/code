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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

vector<int> bigp =
        {231921257, 372796727, 526054829, 860767181, 367088483, 179572213,
         966077327, 715684033, 118285961, 339840469, 444116081, 267774781,
         360403777, 595063811, 355101653, 345239527, 937751401, 512018753,
         888565747, 840217789, 280627939, 418242431, 119184029, 246266851,
         145065119, 401106763, 486754039, 768635513, 844535357, 461939507,
         617843407, 926085997, 875326909, 780649867, 520914137, 364584793,
         937053493, 939419161, 748237177, 526317443, 687718957, 826075721,
         889151839, 558287879, 899255053, 196126087, 100818103, 795870571,
         800491823, 703709701, 342088529, 702618593, 958825577, 388330441,
         686846071, 509758267, 202099529, 257768081, 525057329, 322852867,
         901733143, 526010971, 828955703, 310055423, 279103003, 829018153,
         541958987, 367170259, 843487627, 759644551, 804738449, 982018493,
         341145121, 131319161, 480979561, 957826399, 127006871, 877706449,
         939425099, 529548931, 452717431, 136724327, 358730909, 852806527,
         426685769, 950646253, 665459623, 264516673, 239478647, 935312699,
         313860143, 272359663, 299168143, 360824803, 828166753, 678105511,
         525923549, 527173483, 674481007, 894374449};

vector<int> smallp;
bool vis[10005];

int nextbig() {
  static int t;
  return bigp[t++ % bigp.size()];
}

int load(int x) {
  while (x * 3LL <= 1e9) {
    shuffle(smallp.begin(), smallp.end(), rng);
    for (int p : smallp)
      if (x <= 1e9 / p) x *= p;
  }
  return x;
}

vector<int> allq(int n) {
  vector<int> vec(n);
  iota(vec.begin(), vec.end(), 1);
  shuffle(vec.begin(), vec.end(), rng);
  return vec;
}

int cases;

void testcase(int n, int mod, const vector<int> &query) {
  static char fn[100];
  assert(1e8 <= mod && mod <= 1e9);
  ++cases;
  sprintf(fn, "%d.in", cases);
  //if(cases>=73&&cases<=77){
  freopen(fn, "w", stdout);
  cout << n << ' ' << query.size() << ' ' << mod << '\n';
  for (int x : query) cout << x << '\n';
  cout << flush;
  fclose(stdout);
  
  cerr << cases << ": " << n << ", fact mod = ";
  for (int x = 2; x * x <= mod; ++x)
    while (mod % x == 0) {
      cerr << x << ' ';
      mod /= x;
    }
  if (mod != 1) cerr << mod;
  cerr << '\n';
  //}
}

void subtask() {
  static int tasks;
  cerr << '#' << ++tasks << ": " << cases << '\n';
}

int main(int argc, char *argv[]) {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  for (int i = 2; i <= 10000; ++i)
    if (!vis[i]) {
      smallp.push_back(i);
      for (int j = i; j <= 10000; j += i) vis[j] = true;
    }
  smallp.erase(smallp.begin());

  shuffle(bigp.begin(), bigp.end(), rng);

  for (int i = 1; i <= 16; ++i) {
    testcase(i, nextbig(), allq(i));
    if (i == 9 || i == 16) subtask();
  }
  for (int i = 1; i <= 5; ++i) {
    if (i <= 3) testcase(rng() % 100 + 100, nextbig(), {1});
    else testcase(200, nextbig(), {1});
  }
  subtask();
  for (int i = 1; i <= 5; ++i) {
    int t = 200;
    if (i <= 3) t = rng() % 100 + 100;
    testcase(t, nextbig(), allq(t));
  }
  subtask();
  for (int i = 1; i <= 5; ++i) {
    if (i <= 3) testcase(rng() % 500 + 500, nextbig(), {1});
    else testcase(1000, nextbig(), {1});
  }
  subtask();
  for (int i = 1; i <= 5; ++i) {
    if (i <= 3) testcase(rng() % 500 + 500, nextbig(), {2});
    else testcase(1000, nextbig(), {2});
  }
  subtask();
  for (int i = 1; i <= 5; ++i) {
    int t = 1000;
    if (i <= 3) t = rng() % 500 + 500;
    testcase(t, nextbig(), allq(t));
  }
  subtask(); 
  for (int i = 0; i <= 30; ++i) {
    int t = 1000;
    if (i % 5 <= 2) t = rng() % 500 + 500;
    testcase(t, load(1 << min((1 << (i / 5)), 29)), allq(t));
  }
  subtask();
  for (int i = 1; i <= 5; ++i) {
    int t = 2000;
    if (i <= 3) t = rng() % 1000 + 1000;
    testcase(t, nextbig(), allq(t));
  }
  for (int i = 0; i <= 30; ++i) {
    int t = 2000;
    if (i % 5 <= 2) t = rng() % 1000 + 1000;
    testcase(t, load(1 << min((1 << (i / 5)), 29)), allq(t));
  }
  subtask();

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
