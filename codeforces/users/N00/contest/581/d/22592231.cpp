using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 4 ;

int x[MAXN] , y[MAXN];
bool check (int i , int j , int k )
{
    if ( (x[i] == x[j]) && (x[j] == x[k]) && (y[i] + y[j] + y[k] == x[j]))
    {
        printf("%d\n", x[i]);
        for (int X = 0; X < y[i]; X++)
        {
            for (int Y = 0; Y < x[i]; Y++)
                printf("%c", 'A' + i);
            puts("");
        }
        for (int X = 0; X < y[j]; X++)
        {
            for (int Y = 0; Y < x[j]; Y++)
                printf("%c", 'A' + j);
            puts("");
        }
        for (int X = 0; X < y[k]; X++)
        {
            for (int Y = 0; Y < x[k]; Y++)
                printf("%c", 'A' + k);
            puts("");
        }
        return true ;
    }
    if (x[i] == x[j] + x[k] && y[j] == y[k] && y[j] + y[i] == x[i])
    {
        printf("%d\n", x[i]);
        for (int X = 0; X < y[i]; X++)
        {
            for (int Y = 0; Y < x[i]; Y++)
                printf("%c", 'A' + i);
            puts("");
        }
        for (int X = 0; X < y[j]; X++)
        {
            for (int Y = 0; Y < x[j] + x[k]; Y++)
            {
                printf("%c", 'A' + (Y >= x[j] ? k : j));
            }
            puts("");
        }
        return true ;
    }
    return false ;
}

int main()
{
#define TASK "581D"
   // freopen(TASK".inp","r",stdin);
  //  freopen(TASK".out","w",stdout);
    for (int i = 0; i < 3; i++)
        scanf("%d %d", &x[i], &y[i]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (i != j && i != k && j != k)
                {
                    for (int p = 0; p < 8; p++)
                    {
                        for (int q = 0; q < 3; q++)
                            if (p >> q & 1) swap(x[q], y[q]);
                        if (check(i, j, k)) return 0;
                        for (int q = 0; q < 3; q++)
                            if (p >> q & 1) swap(x[q], y[q]);
                    }
                }
    printf("-1\n");
}
