#include<bits/stdc++.h>
using namespace std; 

class FirstUnique {
    private: 
        list<int> unique; // all unique values by insertion order
        unordered_map<int, list<int>::iterator> pos; // map value to position in list "unique" 
           
    public: // using default constructor 
        FirstUnique(vector<int>& numbers) {
            for (int number: numbers) {
                add(number);
            }
        }    
        int showFirstUnique() { 
            return unique.empty()? -1 : unique.front(); 
        }
  
        void add(int x) {
            // insert new unique value to the tail of list and point to tail position
            if (!pos.count(x))
                unique.push_back(x), pos[x] = --unique.end(); 
                // mark duplicated values by pointing pos[x] to end
            else if (pos[x] != unique.end())
                unique.erase(pos[x]), pos[x] = unique.end(); 
    }
};