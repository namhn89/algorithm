using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 7e4 + 5 ;
const int MAXM = 20 ;
const long long BASE = 11 ;

int n;
char s[MAXN][MAXM];
typedef pair <int , int>  II ;
long long Hash_mod[MAXN][MAXM] , pw[MAXN];
vector < pair <long long , int> > myset[MAXN][MAXM];
map  < pair <long long , int> , int > kBase;

long long get(int i , int j , long long h[]) {
    return h[j] - h[i - 1] * pw[j - i + 1];
}

pair <int, int> fff (int l, int pos) {
    for (int i = 1; i + l - 1 <= 9; i++) {

        long long code = get(i, i + l - 1, Hash_mod[pos]);

        int cnt = 0;
        int itl = lower_bound(myset[pos][l].begin(), myset[pos][l].end(), make_pair(code, l)) - myset[pos][l].begin();

        if (myset[pos][l][itl].st != code) continue;
        int itr = upper_bound(myset[pos][l].begin(), myset[pos][l].end(), make_pair(code, l)) - myset[pos][l].begin() - 1;

        if (myset[pos][l][itr].st != code) continue;


        if (kBase[make_pair(code, l)] == itr - itl + 1) return make_pair(i , l);
    }


    return make_pair(-1 , -1);
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d",&n) ;
    pw[0] = 1 ;
	for (int i = 1 ; i <= 10 ; i++) pw[i] = pw[i - 1] * BASE;

	for (int i = 1 ; i <= n ; i++) scanf("%s", s[i] + 1) ;

	for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ;  j <= 9 ; j++) Hash_mod[i][j] = Hash_mod[i][j - 1] * BASE + s[i][j] - '0';

    for (int i = 1 ; i <= n ; i++)
        for (int dodai = 1; dodai <= 9; dodai++) {
            for (int j = 1; j + dodai - 1 <= 9; j++) {
                long long code = get(j, j + dodai - 1, Hash_mod[i]);

                myset[i][dodai].push_back(make_pair(code, dodai));

                kBase[make_pair(code, dodai)]++;
            }
            sort(myset[i][dodai].begin(), myset[i][dodai].end());
        }

    for (int i = 1; i <= n; i++) {
        int low = 1, high = 9, mid;
        II ans;
        while (low <= high) {
            mid = (low + high) / 2 ;
            if (fff(mid, i).st != -1) {
                high = mid - 1;
                ans = fff(mid , i);
            } else {
                low = mid + 1;
            }
        }
        for (int j = ans.st ; j <= ans.st + ans.nd - 1; j++) cout << s[i][j];

        cout << endl ;
    }

    return 0;
}
