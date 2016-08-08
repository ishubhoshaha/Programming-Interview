#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(){
        left = NULL;
        right = NULL;
    }
};
Node* GetNode(int data){
    Node *temp = new Node();
    temp->data = data;
    return temp;
}
int TreeHight(Node *root){
    if(root==NULL)
        return -1; // If we return 0 then the height of leaf become 1
    int x = TreeHight(root->left);
    int y = TreeHight(root->right);
    return max(x,y)+1;
}
int main(){
    Node *root = NULL;
    root = GetNode(10);
    root->left = GetNode(16);
    root->left->right = GetNode(-3);
    root->right = GetNode(5);
    root->right->left = GetNode(6);
    root->right->right = GetNode(11);
    cout<<endl<<"Height of Tree: "<<TreeHight(root);

}
