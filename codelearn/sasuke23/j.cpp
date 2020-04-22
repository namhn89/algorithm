using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))

const int N = 1e5 + 1; // careful
const int MOD = 1e9 + 7;
const int inf = 2e9 + 1;

int combinations[300][6];
int nc = 0;
int n ;
int k;
void comb (const int &N, const int &K)
{
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    vector <vector<int>> res;
    do {
        vector <int> a;
        int t = 0;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) {
                combinations[nc][t] = i;
                t++;
            }
        }
        nc++;
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

int convertStr (const string &a) {
    int res = 0 ;
    for(auto c : a) {
        res = res * 10 + int (c - '0');
    }
    return res ;
}

vector <pair<int, int>> processData (const vector <string> &a) {
    vector <pair<int, int>> res;
    for(string p : a) {
        int start = 0;
        vector <int> z;
        for(int i = 0; i < p.size() - 1; ++i) {

            if (p[i] == 'A' && p[i + 1] == 'M') {
                int start = 0;
                string t = "";
                for(int j = i - 2; j >= 0; --j) {
                    if (p[j] == ' ') {
                        break;
                    }
                    t += p[j];
                }
                reverse(t.begin(), t.end());
                int x = convertStr(t);
                if (x == 12) z.push_back(0);
                else z.push_back(x);
            }
            if (p[i] == 'P' && p[i + 1] == 'M') {
                 int start = 0;
                string t = "";
                for(int j = i - 2; j >= 0; --j) {
                    if (p[j] == ' ') {
                        break;
                    }
                    t += p[j];
                }
                reverse(t.begin(), t.end());
                int x = convertStr(t);
                if (x == 12) z.push_back(12);
                else z.push_back(x + 12);
            }
        }
        res.push_back(make_pair(z[0], z[1]));
    }
    return res;

}

int calc (const int &x, const int &y) {
    int layover;
    if (y - x >= 0) {
        layover = y - x;
        if (layover < 5) layover += 24;
    }
    else {
        layover = 24 - x + y;
        if (layover < 5) layover += 24;
    }
    //cout << x.st << " " << x.nd << " " << y.st << " " << y.nd << " " << layover << endl;
    return layover;
}

const int M = 10 + 2;

int hnA[M];
int hnB[M];
int hcmA[M];
int hcmB[M];
int idx[M];

int solveHN () {
    int nidx = k;
    int ans = inf ;
    for(int i = 0; i < nidx; ++i) idx[i] = i;
    do {
        int res = 0;
        for(int i = 0; i < nidx; ++i) {
            res += calc(hnA[i], hnB[idx[i]]);
        }
        ans = min(res, ans);
    }
    while (next_permutation(idx, idx + nidx));
    return ans;
}

int solveHCM () {
    int nidx = k;
    int ans = inf ;
    for(int i = 0; i < nidx; ++i) idx[i] = i;
    do {
        int res = 0;
        for(int i = 0; i < nidx; ++i) {
            res += calc(hcmA[i], hcmB[idx[i]]);
        }
        ans = min(res, ans);
    }
    while (next_permutation(idx, idx + nidx));
    return ans;
}

int myrandom (int i) { return std::rand()%i;}

int minimumLayover(const vector<string> &a, const vector<string> &b)
{
    srand(unsigned(std::time(0)));
    vector <pair<int, int>> pA, pB;
    n = a.size();
    k = n / 2;
    comb(n, k);
    pA = processData(a);
    pB = processData(b);
    /*
    for(int i = 0; i < pA.size(); ++i) {
        cout << pA[i].st << " " << pA[i].nd << endl;
    }
    for(int i = 0; i < pB.size(); ++i) {
        cout << pB[i].st << " " << pB[i].nd << endl;
    }
    */
    int ans = inf;
    for(int i = 0; i < nc; ++i) {
        for(int j = 0; j < nc; ++j) {
            for(int z = 0; z < k; ++z) {
                hnA[z] = pA[combinations[i][z]].nd;
            }
            for(int z = 0; z < k; ++z) {
                hnB[z] = pB[combinations[j][z]].st;
            }
            int t = 0;
            for(int z = 0; z < n; ++z) {
                bool strange = true;
                for(int p = 0; p < k; ++p) {
                    int c = combinations[i][p];
                    if (z == c) strange = false;
                }
                if (strange) {
                    hcmB[t] = pA[z].st;
                    t++;
                }
            }

            t = 0;
            for(int z = 0; z < n; ++z) {
                bool strange = true;
                for(int p = 0; p < k; ++p) {
                    int c = combinations[j][p];
                    if (z == c) strange = false;
                }
                if (strange) {
                    hcmA[t] = pB[z].nd;
                    t++;
                }
            }
            ans = min(ans, solveHN() + solveHCM());
        }
    }
    vector <int> mysetsx, mysetsy ;
    for(int i = 0; i < nc; ++i) mysetsx.push_back(i);
    for(int i = 0; i < nc; ++i) mysetsy.push_back(i);
    random_shuffle(mysetsx.begin(), mysetsx.end(), myrandom);
    random_shuffle(mysetsy.begin(), mysetsy.end(), myrandom);

    for(int x = 0; x < min(nc, 100); ++x) {
        int i = mysetsx[x];
        for(int y = 0; y < min(nc, 100); ++y) {
            int j = mysetsy[y];
            for(int z = 0; z < k; ++z) {
                hnA[z] = pA[combinations[i][z]].nd;
            }
            for(int z = 0; z < k; ++z) {
                hnB[z] = pB[combinations[j][z]].st;
            }
            int t = 0;
            for(int z = 0; z < n; ++z) {
                bool strange = true;
                for(int p = 0; p < k; ++p) {
                    int c = combinations[i][p];
                    if (z == c) strange = false;
                }
                if (strange) {
                    hcmB[t] = pA[z].st;
                    t++;
                }
            }

            t = 0;
            for(int z = 0; z < n; ++z) {
                bool strange = true;
                for(int p = 0; p < k; ++p) {
                    int c = combinations[j][p];
                    if (z == c) strange = false;
                }
                if (strange) {
                    hcmA[t] = pB[z].nd;
                    t++;
                }
            }
            ans = min(ans, solveHN() + solveHCM());
        }
    }
    return ans;
}

int main() {
    int n;
    std::string tmp;
    std::getline(std::cin, tmp);
    n = std::atoi(tmp.c_str());
    std::vector<std::string> a(n), b(n);
    for (auto &s : a) std::getline(std::cin, s);
    for (auto &s : b) std::getline(std::cin, s);
    std::cout << minimumLayover(a, b) << std::endl;
}