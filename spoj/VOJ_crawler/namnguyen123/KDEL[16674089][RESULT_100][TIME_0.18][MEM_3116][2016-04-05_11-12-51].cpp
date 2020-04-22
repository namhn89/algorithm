#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
 
const int maxN=611953;
vector<int> ngto,a;
int n,k;
string s;
 
void Sang_NTo()
{
    a.resize(maxN+2);
    for(int i=2;i*i<=maxN;i++)
        if (a[i]==0)
        {
            int j=i*i;
            while(j<=maxN)
            {
                a[j]=1;
                j+=i;
            }
        }
        for(int i=2;i<=maxN;i++)
        {
            if(a[i]==0) ngto.push_back(i);
            if(ngto.size()==n) break;
        }
}
 
void Add(int i)
{
    string st2="";
    stack<char> st;
    while(i!=0)
    {
        st2.insert(0,1,i%10+48);
        i/=10;
    }
    s+=st2;
}
 
void Init()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) Add(ngto[i]);
}
 
void Solve()
{
    deque<char> dq;
    for(int i=0;i<s.length();i++)
    {
        while(k>0 && dq.size()>0 && dq.back()<s[i])
        {
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }
    while(dq.size()>k)
    {
        cout<<dq.front();
        dq.pop_front();
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    Sang_NTo();
    Init();
    Solve();
}