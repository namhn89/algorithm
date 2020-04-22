using namespace std;
#include<bits/stdc++.h>
#define __unique(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define FOR(i, a, b) for(long i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(long i = a, _b = (b) ; i >= _b ; i--)
#define DEB(X) cout << #X << ": " << X << endl ;
#define long long long
#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair<long, long> ii;
typedef pair<long, long> ll;
long n, m;
long res;
map<long, long> cntR, cntC;
set<long> sR, sC;
int main(){
    #define TASK "in"
    scanf("%I64d %I64d", &n, &m);
    res = n*n;
    FOR(i, 1, m){
        long x, y;
        scanf("%I64d %I64d", &x, &y);
        long tmp = 0;
        if(sR.find(x) == sR.end()) tmp += n - 1 - sC.size() + (sC.find(y) != sC.end());
        if(sC.find(y) == sC.end()) tmp += n - 1 - sR.size() + (sR.find(x) != sR.end());
        if(sR.find(x) == sR.end() && sC.find(y) == sC.end()) tmp++;
        sR.insert(x);
        sC.insert(y);
        //cout << tmp << endl;
        res -= tmp;
        printf("%I64d\n", res);
    }
}
