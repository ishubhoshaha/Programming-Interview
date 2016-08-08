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
Node* getNode(int data){
    Node *temp = new Node();
    temp->data = data;
    return temp;
}
Node* Insert(Node* root,int data){
    if(root == NULL){
        root = getNode(data);
    }else  if(data<=root->data){
        root->left = Insert(root->left,data);
    }else  if(data>root->data){
        root->right = Insert(root->right,data);
    }
    return root;
}
void Inorder(Node* root){
    if(root==NULL)
        return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void PreOrder(Node* root){
    if(root == NULL)
        return ;
    printf("%d ",root->data);
    Inorder(root->left);
    Inorder(root->right);
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
    cout<<endl<<"Height of Tree: "<<TreeHight(root);

}
