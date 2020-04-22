using namespace std;
#include<bits/stdc++.h>
#define __unique(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define FOR(i, a, b) for(int i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(int i = a, _b = (b) ; i >= _b ; i--)
#define DEB(X) cout << #X << ": " << X << endl ;
#define long long long
#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair<int, int> ii;
typedef pair<long, long> ll;

const int N = 1e5 + 10;
int n;
char a[N];
int cnt[N][130];
int exist[130], check[130];
bool ok(int L, int R){
    FOR(c, 'a', 'z') check[c] = false;
    FOR(c, 'A', 'Z') check[c] = false;
    FOR(c, 'a', 'z'){
        check[c] = cnt[R][c] - cnt[L-1][c];
    }
    FOR(c, 'A', 'Z'){
        check[c] = cnt[R][c] - cnt[L-1][c];
    }
    FOR(c, 'a', 'z') if(exist[c] && !check[c]) return false;
    FOR(c, 'A', 'Z') if(exist[c] && !check[c]) return false;
    return true;
}
int main(){
    #define TASK "in"
    cin >> n;
    FOR(i, 1, n) cin >> a[i], exist[a[i]] = 1;
    FOR(i, 1, n) {
        FOR(k, 'a', 'z') {
            cnt[i][k] = cnt[i-1][k];
        }
        FOR(k, 'A', 'Z') cnt[i][k] = cnt[i-1][k];
        cnt[i][a[i]]++;
    }
    int k = 1;
    long res = n;
    FOR(i, 1, n){
        while(!ok(i, k) && k <= n) k++;
        if(ok(i, k - (k == n+1))) res = min(res, (long)(k - i + 1));
    }
    cout << res;
}
