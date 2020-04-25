#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll base=10e8+3;
const int maxn=10e5+1;
string a,b;
vector<ll> Pow,HashA;
int na,nb;

void Init()
{
    cin>>a>>b;
    na=a.length();    a=" "+a;
    nb=b.length();    b=" "+b;
    Pow.resize(nb+2);
    HashA.resize(na+2);
}

ll getHash(int i)
{
    return(HashA[i+nb-1]-HashA[i-1]*Pow[nb]+base*base)%base;
}

void Solve()
{
    ll HashB=0;
    Pow[0]=1;
    for(int i=1;i<=nb;i++)
    {
        HashB=(HashB*26 + b[i]-'a')%base;
        Pow[i]=(Pow[i-1]*26)%base;
    }
    for(int i=1;i<=na;i++)
        HashA[i]=(HashA[i-1]*26+a[i]-'a')%base;
    for (int i=1;i<=na-nb+1;i++)
    {
        if(HashB==getHash(i))
            printf("%d ",i);
    }
}

int main()
{
    Init();
    Solve();
}
