#include<bits/stdc++.h>
using namespace std; 

int* genNumer (int n) {
    int* res; 
    res = (int*) calloc(n, sizeof(int)); 
    for (int i = 0; i < n; ++i){
        res[i] = rand() % 49; 
    }
    return res; 
}

int main(int argc, char const *argv[])
{
    int n; 
    cin >> n; 
    int* ptr = genNumer(n); 
    int* p; 
    for (p = ptr; p != NULL; ++p) {
        cout << *p << endl; 
    }
    
    return 0;
}
