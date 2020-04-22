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
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
vector<string> a;
bool cmp(string s1, string s2)
{
    if(s1.length()==s2.length())
    {
        if(s1.compare(s2)==-1) return true;
        return false;
    }
    if(s1.length()<s2.length())
    {
        for (int i=0; i<s1.length(); i++)
        {
            if(s1[i]<s2[i]) return true;
            if(s1[i]>s2[i]) return false;
        }
        for (int i=s1.length(); i<s2.length(); i++)
        {
            if(s1[0]<s2[i]) return true;
            if(s1[0]>s2[i]) return false;
        }
        return false;
    }
    if(s1.length()>s2.length())
    {
        for (int i=0; i<s2.length(); i++)
        {
            if(s1[i]<s2[i]) return true;
            if(s1[i]>s2[i]) return false;
        }
        for (int i=s2.length(); i<s1.length(); i++)
        {
            if(s1[i]<s2[0]) return true;
            if(s1[i]>s2[0]) return false;
        }
        return false;
    }
}
int main()
{
     //freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string x;
    while(cin>>x != NULL)
    {
        a.push_back(x);
    }
    sort(a.begin(),a.end(),cmp);
    for (int i=a.size()-1; i>=0; i--)
    {
        cout<<a[i];
    }

    return 0;
}
