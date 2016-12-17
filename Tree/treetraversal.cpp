#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left,*right;
    Node(){
        left = NULL;
        right = NULL;
    }
};
Node* NewNode(int data){
    //cout<<data<<endl;
    Node *temp = new Node();
    temp->data = data;
    return temp;
}
Node* Insert(Node *root,int data){
    if(root==NULL){
        root = NewNode(data);
    }else if (data<=root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;
}
void Inorder(Node* root){
    if(root == NULL)
        return ;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void PreOrder(Node* root){
    if(root == NULL)
        return ;
    printf("%d ",root->data);
    Inorder(root->left);
    Inorder(root->right);
}
void PostOrder(Node* root){
    if(root == NULL)
        return ;
    Inorder(root->left);
    Inorder(root->right);
    printf("%d ",root->data);
}
int main(){
    Node *root = NULL;
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
    cout<<endl<<"PreOrder: ";
    PreOrder(root);
    cout<<endl<<"PostOrder: "<<endl;
    PostOrder(root);
}
