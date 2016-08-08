#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *prev,*next;
    int data;
    Node(){
        prev = NULL;
        next = NULL;
    }
}*root;
Node* NewNode(int data){
    Node* temp = new Node();
    temp->data= data;
    return temp;
}
void Insertat_Begin(int data){
    if(root == NULL){
        root = NewNode(data);
    }else{
        Node *temp ;
        temp = NewNode(data);
        root->prev = temp;
        temp->next = root;
        root = temp;
    }
}
void InsertAfter_Node(int after,int data){
    if(root == NULL)
        root = NewNode(data);
    else{
        Node *temp = root;
        Node *New = NewNode(data);
        while(1){
            if(temp->data==after){
                New->prev = temp;
                New->next = temp->next;
                temp->next->prev = New;
                temp->next = New;
                break;
            }
            temp = temp->next;
        }

    }
}
void DeleteFromBegin(){
    Node *temp = root;
    if(temp==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    root = temp->next;
    root->prev = NULL;
    free(temp);

}
void DeleteFromEnd(){
    Node *temp = root;
    if(temp==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp!=NULL){
        if(temp->next == NULL){
            //cout<<temp->data;
            temp->prev->next = NULL;
            return ;
        }
        temp = temp->next;
    }
}
void Travarse(){
    Node *temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void ReverseTravarse(){
    Node *temp = root,*last;
    while(temp!=NULL){
        last = temp;
        temp = temp->next;
    }
    while(last!=NULL){
        cout<<last->data<<" ";
        last = last->prev ;
    }
    cout<<endl<<endl;
}
int main(){
    root = NULL;
    Insertat_Begin(10);
    Insertat_Begin(34);
    Insertat_Begin(8);
    Travarse();
    ReverseTravarse();

    InsertAfter_Node(34,17);
    Travarse();
    DeleteFromBegin();
    Travarse();
    DeleteFromEnd();
    Travarse();

}
