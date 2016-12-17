/*
*Time Complexity : O(N)
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *prev,*next;
    int data;
    Node(){
        prev = NULL;
        next = NULL;
    }
}*head;
Node* NewNode(int data){
    Node* temp = new Node();
    temp->data= data;
    return temp;
}
void Insert(int data){
    if(head==NULL){
        head = NewNode(data);
    }
    else{
        Node *temp = NewNode(data);
        head->prev = temp;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }
}
void ReverseList(){
    Node *current;
    current = head;
    while(current!=NULL){
        if(current->next == NULL){ /// Edge Case : if we reach on last element of original list then set it head
            head = current->prev->prev;
            /// prev and next value of Current->prev is swaped on previous step
            /// that's why we used current->prev->prev
        }
        Node *x = current->prev;
        current->prev = current->next;
        current->next = x;
        current = current->prev;
    }

}
void Travarse(){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);
    cout<<"Before Reverse: ";
    Travarse();
    ReverseList();
    cout<<"After Reverse: ";
    Travarse();

}
