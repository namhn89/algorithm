using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int N = 300010;

char s[N];
int vn, pos[255], cnt[N];
long long hash[N], vhash[N];
map<long long, int> mymap;

inline void add(long long h)
{
    int p = lower_bound(vhash + 1, vhash + vn + 1, h) - vhash;
    cnt[p] += vhash[p] == h;
}

inline int get(long long h)
{
    int p = lower_bound(vhash + 1, vhash + vn + 1, h) - vhash;
    return vhash[p] == h ? cnt[p] : 0;
}

int main()
{
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
    //std::ios::sync_with_stdio(0);
    //std::cin.tie(0);
    for (int i = 'a'; i <= 'z'; ++i)
    {
        pos[i] = i - 'a';
    }
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        pos[i] = i - 'A' + 26;
    }
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    vhash[++vn] = 0;
    for (int i = 1; i <= n; ++i)
    {
        hash[i] = hash[i - 1] ^ (1LL << pos[s[i]]);
        vhash[++vn] = hash[i];
    }
    sort(vhash + 1, vhash + vn + 1);
    vn = unique(vhash + 1, vhash + vn + 1) - vhash - 1;
    add(0);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += get(hash[i]);
        for (int j = 0; j < 52; ++j)
        {
            ans += get(hash[i] ^ (1LL << j));
        }
        add(hash[i]);
    }
    printf("%lld", ans);
}
