using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

vector <int> d;
int ans , n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x ;
        scanf("%d" , &x);
        vector<int> :: iterator it = lower_bound(d.begin() , d.end() , x );
        if (it == d.end() ) d.push_back(x);
        else *it = x ;
    }
    printf("%d", d.size());
    return 0;
}
