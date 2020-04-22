
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
pair<int, int> pos[10];
int n;
char a[100]; pair<int, int> v[100];
pair<int, int> operator - (pair<int, int> a, pair<int, int> b){
    return mp(a.first - b.first, a.second - b.second);
}
pair<int, int> operator + (pair<int, int> a, pair<int, int> b){
    return mp(a.first + b.first, a.second + b.second);
}
bool inside(pair<int, int> pos){
    return (pos.first <= 3 && 1 <= pos.first && pos.second <= 3 && pos.second >= 1) || pos == (mp(4, 2));
}
int main(){
    #define TASK "in"
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);

    int cnt = 0;
    FOR(x, 1, 3){
        FOR(y, 1, 3){
            cnt++;
            pos[cnt] = mp(x, y);
        }
    }
    pos[0] = mp(4, 2);
    cin >> n;
    scanf("%s", a+1);
    FOR(i, 1, n-1){
        v[i] = pos[a[i+1] - '0'] - pos[a[i] - '0'];
    }
    if(n == 1) return cout << "NO", 0;
    int c = 0;
    FOR(i, 0, 9){
        bool ok = true;
        pair<int, int> curr_pos = pos[i];
        FOR(i, 1, n-1){
            curr_pos = curr_pos + v[i];
            if(!inside(curr_pos)) ok = false;
        }
        if(ok) c++;
    }
    if(c == 1) return cout << "YES", 0;
    cout << "NO";
}
