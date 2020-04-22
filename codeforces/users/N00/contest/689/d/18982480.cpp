using namespace std;
#include<bits/stdc++.h>
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define FOR(i, a, b) for(int i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(int i = a, _b = (b) ; i >= _b ; i--)
#define REP(i, a) FOR(i, 0, a - 1)
#define DEB(X) cout << #X << ": " << X << endl ;
#define long long long
#define pb push_back
#define mp make_pair
const int N = 200005;
const int LOGN = 20;
int MaxA[N][LOGN], MinB[N][LOGN];
int n, a[N], b[N];
int getmax(int u, int v){
    int k = log2(v - u + 1);
    return max(MaxA[u][k], MaxA[v - (1 << k) + 1][k]);
}
int getmin(int u, int v){
    int k = log2(v - u + 1);
    return min(MinB[u][k], MinB[v - (1 << k) + 1][k]);
}
int main(){
    #define TASK "in"
    
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) scanf("%d", &b[i]);
    FOR(i, 1, n) MaxA[i][0] = a[i], MinB[i][0] = b[i];
    for(int k = 1; (1 << k) <= n; k++){
        for(int i = 1; i + (1 << k) - 1 <= n; i++){
            MaxA[i][k] = max(MaxA[i][k-1], MaxA[i + (1 << (k-1))][k-1]);
            MinB[i][k] = min(MinB[i][k-1], MinB[i + (1 << (k-1))][k-1]);
        }
    }
    long res = 0;
    FOR(i, 1, n){
        int low = i, high = n, res1 = -1;
        while(low <= high){
            int middle = (low + high) / 2;
            /// tim vi tri dau tien
            if(getmax(i, middle) >= getmin(i, middle)) {
                res1 = middle;
                high = middle - 1;
            }
            else low = middle + 1;
        }
        low = i, high = n; int res2 = -1;
        while(low <= high){
            int middle = (low + high) / 2;
            if(getmax(i, middle) <= getmin(i, middle)){
                res2 = middle;
                low  = middle + 1;
            }
            else high = middle - 1;
        }
        if((res1 != -1 && res2 != -1) && (getmax(i, res1) == getmin(i, res1)) && (getmax(i, res2) == getmin(i, res1)))
            res += max(0, (res2 - res1 + 1));
    }
    cout << res;
}
