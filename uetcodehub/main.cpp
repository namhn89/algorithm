#include<bits/stdc++.h>
using namespace std; 

struct Time {
    // your code goes here
    // Cac bien thanh vien
    int h, m, s; 
    // your code goes here
    // Hai ham khoi tao
    Time(int _h = 0, int _m = 0, int _s = 0): h(_h), m(_m), s(_s) {}

    int second() {
        // your code goes here
        return h * 3600 + m * 60 + s; 
    }
    
    void print() {
        // your code goes here
        printf("%02d:%02d:%02d\n", h, m, s); 
    }
};

Time normalize(int h, int m, int s) {
    // your code goes here
    while(s >= 60) {
        s -= 60; 
        m += 1; 
    }
    while(m >= 60) {
        m -= 60; 
        h += 1; 
    }
    return Time(h, m, s); 
    
}

string findSum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
    int carry = 0; 
  
    for (int i=n1-1; i>=0; i--) 
    { 
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    for (int i = n2 - n1 - 1; i >= 0; --i) { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) {
        str.push_back(carry + '0');
    } 
  
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

int main() {
    int n; 
    cin >> n; 
    vector <int> a(n);
    vector <int> b;
    vector <int> pos;   
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        if (a[i] % 2 == 1) {
            b.push_back(a[i]);
            pos.push_back(i);  
        }
    }
    sort(b.begin(), b.end()); 
    for(int i = 0; i < b.size(); ++i) {
        a[pos[i]] = b[i];  
    }
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl; 
}