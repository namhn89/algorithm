#include <bits/stdc++.h>
using namespace std;

int N, a[11], b[11];
string s[2002];
vector <long long> data[2002];

long long get(long long x, long long y, int op)
{
    if (op == 1) return x + y;
    if (op == 2) return x - y;
    return x * y;
}

void build(int id)
{
    s[id] = " " + s[id] + "+";
    int num = 0, c = 0;
    for (int i = 1; i < s[id].size(); i++)
    {
        if ('0' <= s[id][i] && s[id][i] <= '9')
            num = num * 10 + s[id][i] - '0';
        else
        {
            c++;
            a[c] = num;
            b[c] = (s[id][i] == '+') ? 1 : (s[id][i] == '-' ? 2 : 3);
            num = 0;
        }
    }

//    cout<<c[id]<<endl;
//    for (int i =1; i <= c[id]; i++) cout<<a[i]<<" "; cout<<endl;
//    for (int i =1; i < c[id]; i++) cout<<b[i]<<" "; cout<<endl;

    if (c == 2)
    {
        data[id].push_back(get(a[1], a[2], b[1]));
    }
    if (c == 3)
    {
        data[id].push_back(get(get(a[1], a[2], b[1]), a[3], b[2]));
        data[id].push_back(get(a[1], get(a[2], a[3], b[2]), b[1]));
    }
    sort(data[id].begin(), data[id].end());
    data[id].resize(distance(data[id].begin(), unique(data[id].begin(), data[id].end())));
}

string cvt(int id, int x)
{
    if (id == 0)
    {
        if (x == 1) return "+";
        if (x == 2) return "-";
        return "*";
    }
    string ret = "";
    while (x)
    {
        ret = char(x % 10 + 48) + ret;
        x /= 10;
    }
    return ret;
}

string rev(int id, long long v)
{
    int num = 0, c = 0;
    for (int i = 1; i < s[id].size(); i++)
    {
        if ('0' <= s[id][i] && s[id][i] <= '9')
            num = num * 10 + s[id][i] - '0';
        else
        {
            c++;
            a[c] = num;
            b[c] = (s[id][i] == '+') ? 1 : (s[id][i] == '-' ? 2 : 3);
            num = 0;
        }
    }

    if (c == 2)
        return cvt(1, a[1]) + cvt(0, b[1]) + cvt(1, a[2]);
    if (c == 3)
    {
        if (get(get(a[1], a[2], b[1]), a[3], b[2]) == v)
            return cvt(1, a[1]) + cvt(0, b[1]) + cvt(1, a[2]) + cvt(0, b[2]) + cvt(1, a[3]);
        return cvt(1, a[1]) + cvt(0, b[1]) + "(" + cvt(1, a[2]) + cvt(0, b[2]) + cvt(1, a[3]) + ")";
    }
}

set <long long> cur;
int pos[2002];
double Start;

void dfs(int p)
{
    if ((clock() - Start) / CLOCKS_PER_SEC > 0.95) cout << "NO SOLUTION", exit(0);
    if (p > N)
    {
        for (int i = 1; i <= N; i++)
            cout << rev(i, data[i][pos[i]]) << '\n';
        exit(0);
    }
    for (int j = 0, l = data[p].size(); j < l; j++)
        if (cur.count(data[p][j]) == 0)
        {
            pos[p] = j;
            cur.insert(data[p][j]);
            dfs(p + 1);
            cur.erase(cur.find(data[p][j]));
        }
}

main()
{
 //   freopen("vao.inp", "r", stdin);
   // freopen("ra.out", "w", stdout);

    Start = clock();
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> s[i];

    for (int i = 1; i <= N; i++)
        build(i);

    dfs(1);
    cout << "NO SOLUTION";
}
