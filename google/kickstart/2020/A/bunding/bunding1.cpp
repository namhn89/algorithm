#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
struct node {
    node * child[26];
    // no of words having prefix formed till this node
    ll prefixes;
    // no of words ending at this node
    ll count;
};
 
node * newNode() {
    node * temp = new node();
    for(int i=0; i<26; ++i)
        temp->child[i] = NULL;
    temp->prefixes = temp->count = 0;
    return temp;
}
 
// insert string s into the trie
void insert(node * root, string s) {
    node * curr = root;
    ll n = s.length();
    curr->prefixes ++;
    for(ll i=0; i<n; ++i) {
        if(curr->child[s[i]-'A'] == NULL) {
            node * temp = newNode();
            curr->child[s[i]-'A'] = temp;
        }
        curr = curr->child[s[i]-'A'];
        // curr will be a prefix of s
        curr->prefixes ++;
    }
    // string ends at curr
    curr->count++;
}
 
ll dfs(node * u, ll k, ll depth) {
    // if cannot group into sets of k words
    if(u->prefixes < k)
        return 0;
    ll ans = 0;
    // here = no of strings ending at this node
    ll here = u->count;
    for(int i=0; i<26; ++i) {
        // v is child node
        node * v = u->child[i];
        if(v == NULL)
            continue;
        // add child ans
        ans += dfs(v, k, depth + 1);
        // add child residues to 'here'
        here += (v->prefixes % k);
    }
    // finally, ans = child_ans + sum of scores of groups formed by strings counted by 'here'
    ans += depth * (here / k);
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; ++tc) {
        ll n, k;
        cin>>n>>k;
        node * trie = newNode();
        for(ll i=0; i<n; ++i) {
            string s;
            cin >> s;
            insert(trie, s);
        }
        ll ans = dfs(trie, k, 0);
        cout<<"Case #"<<tc<<": "<<ans<<endl;
    }    
}