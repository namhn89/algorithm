using namespace std;
#include <bits/stdc++.h>
#define long long long

const int NX = 1e5 + 10;
const long oo = 1e16 + 7;
struct segment
{
    long pre, suf, sum, ans;
    segment () {}
    segment (long sum, long pre, long suf, long ans) : sum(sum), pre(pre), suf(suf), ans(ans) {}
};

long add (long a, long b)
{
    return max(a + b, -oo);
}

segment combine (segment a, segment b)
{
    segment res;
    res.sum = add(a.sum, b.sum);
    res.pre = max(a.pre, add(a.sum, b.pre));
    res.suf = max (b.suf, add(b.sum, a.suf));
    res.ans = max (add(a.suf, b.pre), max(a.ans, b.ans));
    return res;
}

int N;

segment IT[4 * NX];
long a[NX];

void build (int node, int LL, int RR)
{
    if (LL == RR)
    {
        IT[node] = segment (a[LL], a[LL], a[LL], a[LL]);
    }
    else
    {
        int MM = (LL + RR) / 2;
        build (node * 2, LL, MM);
        build (node * 2 + 1, MM + 1, RR);
        IT[node] = combine (IT[node * 2], IT[node *2 + 1]);
    }
}

void up (int x, int node = 1, int LL = 1, int RR = N)
{
    if (x > RR || x < LL) return;
    if (LL == RR)
    {
        IT[node] = segment(-oo, -oo, -oo, -oo);
    }
    else
    {
        int MM = (LL + RR) / 2;
        up (x, node * 2, LL, MM);
        up (x, node * 2 + 1, MM + 1, RR);
        IT[node] = combine(IT[node * 2], IT[node * 2 + 1]);
    }
}
int scan (int &a)
{
    bool minus = false;
    int res = 0;
    char c;
    c = getchar();
    while (true)
    {
        if (c == '-') break;
        if (c >= '0' && c <= '9') break;
        c = getchar();
    }
    if (c == '-') minus = true;
    else res = c - '0';
    while (true)
    {
        c = getchar();
        if (c < '0' || c > '9') break;
        res = res*10 + (c - '0');
    }
    if (minus) a = -res;
    else a = res;
}
long scan (long &a)
{
    bool minus = false;
    long res = 0;
    char c;
    c = getchar();
    while (true)
    {
        if ((c == '-') || (c >= '0' && c <= '9')) break;
        c = getchar();
    }
    if (c == '-') minus = true;
    else res = c-'0';
    while (true)
    {
        c = getchar();
        if (c < '0' || c > '9') break;
        res = res*10 + (c - '0');
    }
    if (minus) a = -res;
    else a = res;
}



int main()
{
    #define file "in"
    //freopen(file".inp","r",stdin);
    //freopen(file".out","w", stdout);
    scan(N);
    for (int i = 1; i <= N; i++)
    {
        scan(a[i]);
    }
    build(1, 1, N);
    for (int i = 1; i <= N; i++)
    {
        int id;
        scan(id);
        up(id);
        if (i == N)
        {
            printf("0\n");
            return 0;
        }
        printf("%I64d\n", IT[1].ans);

    }
}