using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;

int n;
int a[MAXN] ;

int main(){
    cin >> n;
    set<int> table;
    int res = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (table.find(a[i]) != table.end()) table.erase(a[i]);
        else table.insert(a[i]);
        res = max(res , (int)table.size() );
    }
    cout << res;
    return 0;
}
