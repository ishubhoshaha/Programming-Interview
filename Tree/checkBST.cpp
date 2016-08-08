#include<bits/stdc++.h>
using namespace std;
bool flag = true;
struct Node{
    int data;
    struct Node *left,*right;
    Node(){
        left = NULL;
        right = NULL;
    }
};
Node* getNode(int item){
    Node *temp = new Node();
    temp->data = item;
    return temp;
}
Node* Insert(Node* root,int data){
    if(root == NULL){
        root = getNode(data);
    } else if(root->data<=data){
        root->left = Insert(root->left,data);
    } else if(root->data>data){
        root->right = Insert(root->right,data);
    }
    return root;
}
void Inorder(Node *root){
    static int prev = 0;
    if(root==NULL)
        return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    if(prev>root->data){
        flag = false;
    }
    prev = root->data;
    Inorder(root->right);
}
int main(){
    Node* root = NULL;
    root = Insert(root,12);
    root = Insert(root,29);
    root = Insert(root,8);
    root = Insert(root,77);
    root = Insert(root,32);
    root = Insert(root,90);
    root = Insert(root,45);
    root = Insert(root,122);
    root = Insert(root,1);
    cout<<"Inorder: ";
    Inorder(root);
    cout<<endl;
    if(flag) cout<<"BST";
    else cout<<"Not BST";
}
