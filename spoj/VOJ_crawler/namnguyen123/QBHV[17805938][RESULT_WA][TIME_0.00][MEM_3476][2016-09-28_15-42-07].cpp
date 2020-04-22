#include<bits/stdc++.h>
using namespace std;
string s;int a[100];int res;int gt[]={1,1,2,6,24,120,720,5040,40320,362880};vector<char> q;
int main()

{
    cin>>s;
    int n;n=s.size();res=gt[n];
    for(int i=0;i<n;i++)
    {
        a[s[i]]++;
    }
    for(int i='A';i<='Z';i++)
        if(a[i]>1)res=res/a[i];
    cout<<res<<endl;
     for(int i=0;i<n;i++)
        q.push_back(s[i]);
     int n1=q.size();
     sort(q.begin()+1,q.end());
   do {
       for(int i=0;i<n;i++)
        cout<<q[i];
       cout<<endl;
    }
    while(next_permutation(q.begin(),q.end()));


}
