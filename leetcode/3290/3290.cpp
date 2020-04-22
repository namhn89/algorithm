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


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* a = head; 
        int n = 0; 
        while(a != NULL) {
            n += 1; 
            a = a -> next; 
        }
        int mid = n / 2; 
        int k = 0; 
        ListNode* res = new ListNode(a -> val);
        while(head != NULL){
            if (k == mid){
                ListNode* res = new ListNode(a -> val);  
                break; 
            }
            k += 1; 
            head = head -> next; 
        }
        return res; 
    }
};

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  Solution sol = Solution();
  ListNode* a = new ListNode(1);  
  for (int i = 2; i <= 5; ++i) {

  }
     
  return 0;
}