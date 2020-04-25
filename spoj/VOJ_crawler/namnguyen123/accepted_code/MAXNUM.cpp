#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int> > factors;

int get(int n, int x)
{
    int ret = 0;
    while(n > 0)
    {
        ret += n / x;
        n /= x;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    int res = INT_MAX;
    int rem = m;
    for(int i = 2, cnt = 0; i * i <= rem; cnt = 0, ++i)
    {
        for(; m % i == 0; cnt++, m /= i);
        if(cnt) factors.push_back({i, cnt});
    }
    if(m > 1) factors.push_back({m, 1});
    for(int i = 0; i < factors.size(); ++i) res = min(res, get(n, factors[i].first) / factors[i].second);
    printf("%d", res);
    return 0;
}
    