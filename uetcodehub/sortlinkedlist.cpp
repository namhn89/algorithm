#include<bits/stdc++.h>
using namespace std; 

class Node {
    int value; 
    public:
        Node* next; 
        Node* prev; 
        int getValue() {
            return value; 
        }
        Node(int c) {
            value = c; 
            prev = NULL;
            next = NULL; 
        }
        
}; 

Node* insert(Node* head, Node* newValue) {
    int value = newValue->getValue(); 
    if (head == NULL) {
        head = newValue; 
    }
    else if (head->getValue() >= value) {
        newValue -> next = head; 
        newValue -> next -> prev = newValue; 
        head = newValue; 
    }
    else {
        Node* cur = head; 
        while(cur -> next != NULL and cur -> next -> getValue() < value) cur = cur -> next; 
        newValue -> next = cur -> next; 
        if (cur -> next != NULL) {
            newValue -> next -> prev = newValue; 
        }
        cur -> next = newValue; 
        newValue-> prev = cur; 
        head = cur; 
    }
    return head; 
}
    

Node* sort(Node* head) {
    Node* result = NULL;
    Node* cur = head; 
    while(cur != NULL) {
        Node* next = cur -> next;
        cur->prev = cur->next = NULL;
        result = insert(result, cur); 
        cur = next; 
    } 
    return result; 
}

int main() {
    Node* root = new Node(4); 
    root -> next = new Node(5); 
    root -> next -> prev = root; 
    root -> next -> next = new Node(3); 
    root -> next -> next -> prev = root -> next; 
    Node* cur = root;  
    while(cur != NULL) {
        cout << cur -> getValue() << endl; 
        cur = cur -> next; 
    }
    root = sort(root);
    while(root != NULL) {
        cout << root -> getValue() << endl; 
        root = root -> next; 
    }
}