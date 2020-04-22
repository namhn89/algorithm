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

const int N = 105;
ii a[N];
int main(){
    #define TASK "in"
    int n;
    cin >> n;
    FOR(i, 1, n) cin >> a[i].st, a[i].nd = i;
    sort(a + 1, a + 1 + n);
    for(int l = 1, r = n; l < r; l++, r--){
        cout << a[l].nd << " " << a[r].nd << endl;
    }
}
