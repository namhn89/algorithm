#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int START;
int n, max_cap;
int d[50][50];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

using State = tuple<int, int, ll>;

constexpr int OO = 1 << 20;
using triple = tuple<int, int, State>;
map<State, int> f;
int dis[50][50];

ll get_next_candidate(int cnt, ll bstate) {
    int source = bstate & ((1LL << n) - 1);
    int target = bstate >> n;
    ll nxt = 0;
    
    if (source == 0 || cnt == max_cap) {
        nxt = (1LL * target) << n;
    } else {
        if (cnt == 0) {
            nxt = 1LL * source;
        } else {
            nxt = bstate;
        }
    }
    return nxt;
}

int calc(const State &s) {
    // lst -> nearest in s
    ll bit = get<2>(s);
    int sum = 0;
    int lst = get<1>(s);
    int cnt = get<0>(s);
    while (bit != 0) {
        int min_d = OO, bpos = -1;
        ll cand = get_next_candidate(cnt, bit);

        for (int i = 0; i < (n << 1); ++i)
        if ((cand >> i) & 1) {
            if (d[lst][i] < min_d) {
                min_d = d[lst][i];
                bpos = i;
            }
        }

        lst = bpos;
        sum += min_d;
        bit ^= (1LL << bpos);
        cnt = (lst < n ? cnt + 1 : cnt - 1);
    }
    return sum;
}

int solve() {
    priority_queue<triple, vector<triple>, greater<triple>> q;
    // for i: [0, n) q.add() state: g, h, (last) + (half1 + (half2 << n)) << 3
    // add distance to map
    int bit_all = (1 << n) - 1;
    for (int i = 0; i < n; ++i) {
        int source = bit_all ^ (1 << i);
        State s = {1, i, source + ((1LL * bit_all) << n)};
        int dist = d[START][i];
        q.push(make_tuple(dist, dist, s));
        f[s] = dist;
    }

    while (!q.empty()) {
        int vf, vg;
        State s;
        tie(vf, vg, s) = q.top();
        q.pop();
        if (vg != f[s]) continue;

        ll bstate = get<2>(s);
        if (bstate == 0) {
            return vg;
        }

        int cnt = get<0>(s), lst = get<1>(s);
        // cout << cnt << ' ' << lst << ' ' << bitset<2>(bstate) << ' ' << vg << endl;
        ll nxt = get_next_candidate(cnt, bstate);

        for (int i = 0; i < (n << 1); ++i) 
        if ((nxt >> i) & 1) {
            int ncnt = (i < n ? cnt + 1 : cnt - 1);
            State nstate = make_tuple(ncnt, i, bstate ^ (1LL << i));
            int nvh = calc(nstate);
            int nvg = vg + d[lst][i];
            if (f.find(nstate) == f.end() || nvg < f[nstate]) {
                f[nstate] = nvg;
                int nvf = nvg + nvh;
                q.push(make_tuple(nvf, nvg, nstate));
            }
        }
    }

    return -1;
}

int shortestRobotPath(std::vector<std::string> wh, int nn) {
    max_cap = nn;
    vector<pair<int, int>> coords;
    int w = wh.size(), h = wh[0].size();
    vector<vector<int>> rev(w, vector<int>(h, 0));

    for (int i = 0; i < w; ++i)
    for (int j = 0; j < h; ++j) {
        if (wh[i][j] == '3') {
            rev[i][j] = (int)coords.size();
            coords.push_back(make_pair(i, j));
        }
    }
    n = (int)coords.size();
    // cout << "N = " << n << endl;
    for (int i = 0; i < w; ++i)
    for (int j = 0; j < h; ++j) {
        if (wh[i][j] == '4') {
            rev[i][j] = (int)coords.size();
            coords.push_back(make_pair(i, j));
        }
    }
    if (n == 0) return 0;
    for (int i = 0; i < w; ++i)
    for (int j = 0; j < h; ++j) {
        if (wh[i][j] == '2') {
            rev[i][j] = (int)coords.size();
            coords.push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < w; ++i)
    for (int j = 0; j < h; ++j) {
        if (wh[i][j] == '1') {
            rev[i][j] = (int)coords.size();
            coords.push_back(make_pair(i, j));
        }
    }

    for (int source = 0; source <= 2 * n; ++source) {
        for (int i = 0; i < w; ++i) for (int j = 0; j < h; ++j)
            dis[i][j] = OO;
        int u, v;
        tie(u, v) = coords[source];
        dis[u][v] = 0;
        queue<int> q;
        q.push(u); q.push(v);

        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nu = u + dx[i], nv = v + dy[i];
                if (nu < 0 || nu >= w || nv < 0 || nv >= h) continue;
                if (wh[nu][nv] == '0') continue;
                if (dis[nu][nv] == OO) {
                    dis[nu][nv] = dis[u][v] + 1;
                    q.push(nu); q.push(nv);
                }
            }
        }
        for (int i = 0; i <= 2 * n; ++i) {
            tie(u, v) = coords[i];
            d[source][i] = dis[u][v];
        }
    }

    START = 2 * n;
    // assert(wh[coords[START].first][coords[START].second] == '2');
    if (wh[coords[START].first][coords[START].second] != '2') return -1;
    for (int i = 0; i < n; ++i) {
        if (wh[coords[i].first][coords[i].second] != '3') return -1;
        // assert(wh[coords[i].first][coords[i].second] == '3');
    }
    for (int i = n; i < 2 * n; ++i) {
        if (wh[coords[i].first][coords[i].second] != '4') return -1;
        // assert(wh[coords[i].first][coords[i].second] == '4');
    }
    for (int i = 0; i < 2 * n; ++i)
        if (d[START][i] == OO) return -1;
    
    int shortest = solve();
    return shortest;
}