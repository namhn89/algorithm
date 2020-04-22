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
//typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
const int MOD=1e9+7;
const int MAXN=2700000;
vector<ull>P;
ull N,k,T;

void sang()
{
    bool *A=new bool [MAXN+5];
    for(ull i=3 ; i<=MAXN ; i+=2 )A[i]=true;
    P.push_back(2);
    for(ull i=3; i*i<=MAXN ; i+=2)
    if(A[i])    for(ull j=i*i;j<=MAXN;j+=i) A[j]=false;
    for(ull i=3 ; i<=MAXN ; i+=2) if(A[i]) P.push_back(i);
    delete []A;
}
int main()
{
    sang();
    cin>>T;
    while(T>0)
    {
        cin>>N>>k;
        ull pos=0;
        ull g=1;
        bool ok = true;
        for(ull i=0 ; i<k ; i++)
        {
            if(g>N/P[i]) {ok=false;break;}
            g*=P[i];
        }
        if(!ok) cout<<-1<<endl;
        else
        {
            while(g/P[pos]<=N/P[pos+k])
            {
                g=g/P[pos]*P[pos+k];
                pos++;
            }
            cout<<g<<endl;
        }
        T--;
    }

}
