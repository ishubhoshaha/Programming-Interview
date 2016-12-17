/*
        10
        /\
       16 5
        \  /\
        -3 6 11
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
struct Node{
    int data;
    Node *left,*right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};
Node* GetNode(int data){
    Node *temp = new Node();
    temp->data = data;
    return temp;
}
bool isSummed(Node *root, int sum){
    if(root==NULL)
        return false;
    if(root->left == NULL and root->right==NULL){
        if( (sum - root->data)!=0 )
            return false;
        else {
            v.push_back(root->data);
            return true;
        }
    }
    if(isSummed(root->left,sum-root->data)){
        v.push_back(root->data);
        return true;
    }
    if(isSummed(root->right,sum-root->data)){
        v.push_back(root->data);
        return true;
    }
    return false;
}
int main(){
    Node *root;
    root = GetNode(10);
    root->left = GetNode(16);
    root->left->right = GetNode(-3);
    root->right = GetNode(5);
    root->right->left = GetNode(6);
    root->right->right = GetNode(11);
    isSummed(root,26);
    cout<<"From Root to Leaf: ";
    for(vector<int>::reverse_iterator it = v.rbegin();it!=v.rend();it++){
        cout<<*it<<"->";
    }
}
