#include<bits/stdc++.h>
using namespace std; 
struct Node {
    int value; 
    Node* next; 
    /* data */
};

Node *newNode(int data) 
{ 
   Node *temp = new Node(); 
   temp->value = data; 
   temp->next = NULL; 
   return temp; 
} 

Node* deleteDuplicates(Node* head) {
    Node *x, *y; 
    x = head; 
    while(x != NULL and x -> next != NULL) {
        y = x; 
        while(y -> next != NULL) {
            if (x -> value == y -> next -> value) {
                y -> next = y -> next -> next; 
            }
            else y = y -> next; 
        }
        x = x -> next; 
    }
    return head; 
}



int main() {
    Node *head = newNode(4); 
    head -> next = newNode(3); 
    head -> next -> next = newNode(2); 
    head -> next -> next -> next = newNode(3); 
    head -> next -> next -> next -> next = newNode(1); 
    head = deleteDuplicates(head); 

    while(head != NULL) {
        cout << head -> value << endl; 
        head = head -> next; 
    }

}