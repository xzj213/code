#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int N = 503;
const double eps = 1e-10;
int T, test, n, m, k, kk, vec[N]; double c[N];
unordered_set<int> S;
unordered_map<int, int> tmp;
int id(int u, int v){return u * n + v;}
void solve(){
    n = inf.readInt(); m = inf.readInt(); S.clear();
    for(int i = 0;i < n;++ i) c[i] = inf.readDouble();
    for(int i = 0, u, v;i < m;++ i){
        u = inf.readInt(); v = inf.readInt();
        S.insert(id(u, v)); S.insert(id(v, u));
    } kk = ans.readInt(); k = ouf.readInt();
    if(!kk){
        if(k) quitf(_wa, format("Case #%d: No Solution but you Found!", test).c_str());
    } else {
    	if(!k) quitf(_wa, format("Case #%d: There is a solution but you didn't find!\n", test).c_str());
        tmp.clear();
        for(int i = 0;i < kk;++ i) ans.readInt();
        for(int i = 0;i < k;++ i){
            vec[i] = ouf.readInt();
            if(tmp.count(vec[i]))
                quitf(_wa, format("Case #%d: p[%d] = p[%d] = %d!\n", test, tmp[vec[i]], i, vec[i]).c_str());
            tmp[vec[i]] = i;
        }
        for(int i = 0;i < k;++ i)
            if(!S.count(id(vec[i], vec[(i+1)%k])))
                quitf(_wa, format("Case #%d: There is no edges between %d and %d!\n", test, vec[i], vec[(i+1)%k]).c_str());
        double tt = 0;
        for(int i = 0;i < k;++ i) tt += c[vec[i]];
        if(tt <= (k>>1) - eps)
            quitf(_wa, format("Case #%d: the sum of weight is %.6lf < %d!\n", test, tt, k>>1).c_str());
    }
}
int main(int argc, char **argv){
//  registerLemonChecker(argc, argv);
    registerTestlibCmd(argc, argv);
    T = inf.readInt();
    for(test = 0;test < T;++ test) solve();
    quitf(_ok, "Oll Koret");
}
