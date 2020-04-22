using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 2e5 + 5 ;
int N , M , K ;
typedef pair<int,int> II ;
II a[MAXN] ;

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);

    cin >> N >> M >> K ;
    for (int i = 0 ; i < N ; ++i) {
        cin >> a[i].st ;
        a[i].nd = i ;
    }
    sort(a , a + N , greater <II>()) ;
    long long ans = 0 ;
    vector <int> pos ;
    for (int i = 0 ; i < M * K ; ++i) {
         ans += a[i].st ;
         pos.push_back(a[i].nd) ;
    }
    sort(pos.begin() , pos.end()) ;
    cout << ans << endl ;
    vector <int> res ;
    for (int i = 0 ; i < K - 1 ; ++i ) {
        res.push_back(pos[(i + 1) * M - 1]) ;
    }
    TR(res , it) {
        cout << (*it) + 1 << " ";
    }

    return 0;
}

