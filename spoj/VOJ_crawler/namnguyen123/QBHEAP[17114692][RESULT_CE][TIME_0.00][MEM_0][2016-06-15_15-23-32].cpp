using namespace std;
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e5+1;
const int INF =1e9;
int f (string s)
{
    int sum = 0;
    FORE(i, 1, s.size() - 1)
    {
        sum = sum*10 + (s[i]-'0');
    }
    return sum ;
}
int main ()
{
    //freopen("IO.inp","r",stdin);
    // freopen(".out","w",stdout);
    priority_queue< int > q ;
    string s ;
    while (cin >> s)
    {
        if (s[0] == '+')
        {
            if (q.size() < 15000)
            {
                q.push(f(s));
            }
        }
        else if (s[0] == '-')
        {
            if (!q.empty())
            {
                int x = q.top();
                while(q.top() == x && !q.empty())q.pop();
            }
        }
    }
    vector < int > g;
    if (q.size())
    {
        while (!q.empty())
        {
            int a = q.top();
            while (!q.empty() && q.top() == a ) q.pop() ;
            g.push_back(a);
        }
        cout << g.size() << endl;
        FORE (i, 0, g.size()-1)
        {
            cout << g[i] << " ";
        }
    }
    else cout << 0 << endl;

    return 0;
}
     
using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e5+1;
const int INF =1e9;
int f (string s)
{
    int sum = 0;
    FORE(i, 1, s.size() - 1)
    {
        sum = sum*10 + (s[i]-'0');
    }
    return sum ;
}
int main ()
{
    //freopen("IO.inp","r",stdin);
    // freopen(".out","w",stdout);
    priority_queue< int > q ;
    string s ;
    while (cin >> s)
    {
        if (s[0] == '+')
        {
            if (q.size() < 15000)
            {
                q.push(f(s));
            }
        }
        else if (s[0] == '-')
        {
            if (!q.empty())
            {
                int x = q.top();
                while(q.top() == x && !q.empty())q.pop();
            }
        }
    }
    vector < int > g;
    if (q.size())
    {
        while (!q.empty())
        {
            int a = q.top();
            while (!q.empty() && q.top() == a ) q.pop() ;
            g.push_back(a);
        }
        cout << g.size() << endl;
        FORE (i, 0, g.size()-1)
        {
            cout << g[i] << " ";
        }
    }
    else cout << 0 << endl;

    return 0;
}
    
