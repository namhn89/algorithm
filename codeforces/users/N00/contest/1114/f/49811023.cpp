using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 4e5 + 5 ;
const int MOD = 1e9 + 7 ;
const int MAXP = 62 ;
const int MAXV = 301 ;

int a[MAXN] , N , Q ;
int inv[MAXP] ;
long long M[MAXV] ;

int pr[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 ,
53 , 59 , 61 , 67 , 71 , 73 , 79 , 83 , 89 , 97 , 101 , 103 , 107 , 109 , 113 , 127 , 131 , 137 ,
139 , 149 , 151 , 157 , 163 , 167 , 173 , 179 , 181 , 191 , 193 , 197 , 199 , 211 , 223 , 227 , 229 ,
233 , 239 , 241 , 251 , 257 , 263 , 269 , 271 , 277 , 281 , 283 , 293 } ;

long long Power (int a , int n) {
    long long res = 1 ;
    while(n) {
        if (n & 1LL) res = (1LL * res * a) % MOD ;
        n >>= 1LL ;
        a = (1LL * a * a) % MOD ;
    }
    return res ;
}

long long Mul (int a , int b) {
  return (1LL * a * b) % MOD ;
}

void Prepare () {
   for (int i = 0 ; i < MAXP ; ++i ) inv[i] = Power(pr[i] , MOD - 2) ;
   for (int i = 1 ; i < MAXV ; ++i ) {
      for (int k = 0 ; k < MAXP ; ++k ) {
           if (i % pr[k] == 0) {
                M[i] |= (1LL << k) ;
         }
      }
   }
}

struct SegmentTree_Product {
    vector <int> Node , Lazy ;

    void Init (int n) {
        Node.resize(4 * n + 1) ;
        Lazy.resize(4 * n + 1) ;
        for (int i = 1 ; i <= 4 * n ; ++i) Lazy[i] = 1 , Node[i] = 1 ;
    }
    void Build (int k , int left , int right) {
        if (left == right) {
            Node[k] = a[left] ;
        }
        int mid = (left + right) / 2 ;
        Build (k << 1 , left , mid ) ;
        Build (k << 1 | 1 , mid + 1 , right) ;
        Node[k] = Mul(Node[k << 1] , Node[k << 1| 1]) ;
    }
    void Push_down (int k , int left , int right) {
        if (Lazy[k] != 1 ) {
            Node[k] = Mul(Node[k] , Power(Lazy[k] , (right - left + 1))) ;
            if (left != right) {
                Lazy[k << 1] = Mul(Lazy[k << 1] , Lazy[k]) ;
                Lazy[k << 1 | 1] = Mul(Lazy[k << 1 | 1] , Lazy[k]) ;
            }
        }
        Lazy[k] = 1 ;
    }
    void Update (int k , int left , int right , int u , int v , int p ) {
        Push_down(k , left , right) ;
        if (right < u || v < left) return ;
        if (u <= left && right <= v) {
            Lazy[k] = Mul(Lazy[k] , p) ;
            Push_down(k , left , right) ;
            return ;
        }
        int mid = (left + right) / 2 ;
        Update(k << 1 , left , mid , u , v , p) ;
        Update(k << 1 | 1 , mid + 1 , right , u , v ,p) ;
        Node[k] = Mul(Node[k << 1] , Node[k << 1 | 1]) ;
    }
    long long Query (int k , int left , int right , int u , int v) {
        Push_down(k , left , right) ;
        if (right < u || v < left) return 1 ;
        if (u <= left && right <= v) {
            return Node[k] ;
        }
        int mid = (left + right) / 2 ;
        return (1LL * Query(k << 1 , left , mid , u , v) * Query(k << 1 | 1 , mid + 1 , right , u , v)) % MOD ;
    }
};

struct SegmentTree_Bool {
    vector <long long> Node , Lazy ;

    void Init (int n) {
        Node.resize(4 * n + 1) ;
        Lazy.resize(4 * n + 1) ;
    }
    void Push_down (int k , int left , int right) {
        if (Lazy[k] != 0 ) {
            Node[k] = Node[k] | Lazy[k] ;
            if (left != right) {
                Lazy[k << 1] |= Lazy[k] ;
                Lazy[k << 1 | 1] |= Lazy[k] ;
            }
        }
        Lazy[k] = 0 ;
    }
    void Update (int k , int left , int right , int u , int v , long long p ) {
        Push_down(k , left , right) ;
        if (right < u || v < left) return ;
        if (u <= left && right <= v) {
            Lazy[k] |= p ;
            Push_down(k , left , right) ;
            return ;
        }
        int mid = (left + right) / 2 ;
        Update(k << 1 , left , mid , u , v , p) ;
        Update(k << 1 | 1 , mid + 1 , right , u , v ,p) ;
        Node[k] = (Node[k << 1] | Node[k << 1 | 1]) ;
    }
    long long Query (int k , int left , int right , int u , int v) {
        Push_down(k , left , right) ;
        if (right < u || v < left) return 0 ;
        if (u <= left && right <= v) {
            return Node[k] ;
        }
        int mid = (left + right) / 2 ;
        return (Query(k << 1 , left , mid , u , v) | Query(k << 1 | 1 , mid + 1 , right , u , v)) ;
    }
};
SegmentTree_Bool BoolTree ;
SegmentTree_Product ProductTree;

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
   ios_base::sync_with_stdio(false); cin.tie(NULL);
   cin >> N >> Q ;
   Prepare() ;
   for (int i = 1 ; i <= N ; ++i) cin >> a[i] ;
   BoolTree.Init(N) ;
   ProductTree.Init(N) ;
   for (int i = 1 ; i <= N ; ++i) {
      BoolTree.Update(1 , 1 , N , i , i , M[a[i]]) ;
      ProductTree.Update(1 , 1 , N , i , i , a[i]) ;
   }
   while(Q--){
       string op ;
       cin >> op ;
       if (op[0] == 'T') {
          int left , right ;
          cin >> left >> right ;
          long long ans = ProductTree.Query(1 , 1 , N , left , right) ;
          long long Mask = BoolTree.Query(1 , 1 , N , left , right) ;
          for (int i = 0 ; i < MAXP ; ++i) {
                if ((Mask >> i) & 1) {
                    ans = Mul(ans , pr[i] - 1);
                    ans = Mul(ans , inv[i]) ;
                }
          }
          cout << ans << endl;
       }
       else {
            int left , right , value ;
            cin >> left >> right >> value ;
            ProductTree.Update(1 , 1 , N , left , right , value) ;
            BoolTree.Update(1 , 1 , N , left , right , M[value]) ;
       }
   }

    return 0;
}