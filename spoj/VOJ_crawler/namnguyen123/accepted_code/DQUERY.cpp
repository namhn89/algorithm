#include <bits/stdc++.h> 

using namespace std;

#define long long long
#define FOR(i, a, b) for(int i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(int i = a, _b = (b) ; i >= _b ; i--)


const int kMaxN = 30005;
const int kMaxQuery = 200005; 
const int kMaxValue = 1e6 + 10;
int last[kMaxValue];
int a[kMaxN];
int N, Q;
int ans[kMaxQuery];
int BIT[kMaxN]; 
vector < pair <int, int> > q[kMaxN];

void up (int pos, int value) {
    for (int node = pos; node <= N; node += node & -node) {
        BIT[node] += value;
    }
}

int get (int pos) {
    int res = 0; 
    for (int node = pos; node > 0; node -= node & -node) {
        res += BIT[node]; 
    }
    return res; 
}

int main() {
    #define file "DQUERY"
    //freopen(file".INP","r",stdin); freopen(file".OUT","w", stdout);
    ios :: sync_with_stdio(false);
    scanf("%d", &N); 
    FOR (i, 1, N) scanf("%d", &a[i]); 
    scanf("%d", &Q); 
    FOR (i, 1, Q) {
        int ll, rr; 
        scanf("%d %d", &ll, &rr);
        q[rr].push_back( {ll, i} );
    }
    FOR (i, 1, N) {
        if (last[ a[i] ] != 0) up(last[ a[i] ], -1);
        up(i, 1);
        last[ a[i] ] = i; 
        for (int k = 0; k < q[i].size(); k++) {
            pair <int, int>  iQ = q[i][k]; 
            ans[iQ.second] = get (i) - get (iQ.first - 1); 
        }
    }
    FOR (i, 1, Q) {
        printf("%d\n", ans[i]); 
    }
    return 0;     
}