#include <bits/stdc++.h>

using namespace std;

char fn[100];

int main() {
  for (int i = 1; i <= 108; ++i) {
    sprintf(fn, "std.exe < %d.in > %d.ans", i, i);
    system(fn);
  }
  return 0;
}

