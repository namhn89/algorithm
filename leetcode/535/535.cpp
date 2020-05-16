using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e5 + 1;
const int MOD = 1e9 + 7; 

class TrieNode {
	public:
		bool isEnd; 
		TrieNode *child[26]; 
		TrieNode () {
			isEnd = false; 
			for (int i = 0; i < 26; ++i) {
				child[i] = NULL; 
			}
		}
}; 

class Trie {

	public:
    	/** Initialize your data structure here. */
    	Trie() {
			root = new TrieNode();
    	}
    
    	/** Inserts a word into the trie. */
    	void insert(string word) {
			TrieNode *cur = root; 
			for(char c: word) {
				if (cur -> child[c - 'a'] == NULL) {
					cur -> child[c - 'a'] = new TrieNode();
				}
				cur = cur -> child[c - 'a']; 
			}
			cur -> isEnd = true; 
    	}
    
   		/** Returns if the word is in the trie. */
    	bool search(string word) {
			TrieNode* cur = root;
			for (char c : word) {
				if (cur -> child[c - 'a'] == NULL) return false; 
				cur = cur -> child[c - 'a']; 
			}
			return cur -> isEnd; 
    	}
    
    	/** Returns if there is any word in the trie that starts with the given prefix. */
    	bool startsWith(string prefix) {
			TrieNode* cur = root; 
			for (char c : prefix) {
				if (cur -> child[c - 'a'] == NULL) return false;
				cur = cur -> child[c - 'a']; 
			}
			return true; 
    	}
	private:
    	TrieNode* root;
};



 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Trie* obj = new Trie();
	obj->insert("abbc");
	obj->insert("aaa"); 
	obj->insert("cca");
	bool param_2 = obj->search("aaa");
	bool param_3 = obj->startsWith("ab");
    cout << param_2 << endl; 
	cout << param_3 << endl;  
  	return 0;
}