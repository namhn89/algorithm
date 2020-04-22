#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;

const int MAXN = 1e5+1;

int main(){
    int n ;
    int Max = 0 , Sum = 0;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++ i) {
        int x ;
        cin >> x ;
        Sum += x ;
        Max = max(Max , x);
    }
    cout << n * Max - Sum << endl;

    return 0;
}
