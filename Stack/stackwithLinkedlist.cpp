#include<bits/stdc++.h>
using namespace std;
class Stack{
private:
    struct Node{
        int info;
        struct Node *next;
        int counter = 0;
    };
    Node *head;
public:
    Stack(){
 
        head = NULL;
    }
    void Push(int item);
    void Pop();
    int top();
    int Size();
};
void Stack::Push(int item){
    Node *temp;
    temp = new Node;
    temp->info=item;
    if(head ==NULL){
        head = temp;
        head->next=NULL;
        head->counter=1;
    }else{
        temp->next=head;
        temp->counter=head->counter+1;
        head = temp;
    }
}
int Stack::top(){
    if (head==NULL){
        cout<<"Stack Is Empty";
    }else{
        return head->info;
    }
}
void Stack::Pop(){
    if(head==NULL){
        cout<<"Stack is Empty";
    }else{
        Node *del;
        del = head;
        head=head->next;
        delete(del);
    }
}
int Stack::Size(){
    if(head==NULL)
        return 0;
    else
        return head->counter;
}
int main(){
    Stack stk;
    while(1){
        cout<<"1.Push"<<endl
            <<"2.Pop"<<endl
            <<"3.Top"<<endl
            <<"4.Size"<<endl
            <<"5.Exit";
        cout<<endl<<"Insert Choice# ";
        int c;
        cin>>c;
        switch(c){
        case 1:
            int val;
            cout<<"Value: ";
            cin>>val;
            stk.Push(val);
            break;
        case 2:
            stk.Pop();
            break;
        case 3:
            cout<<"Top of Stack: "<<stk.top()<<endl;
            break;
        case 4:
            cout<<"Size of Stack: "<<stk.Size()<<endl;
            break;
        case 5:
            return 0;
        }
        cout<<endl;
    }
}
