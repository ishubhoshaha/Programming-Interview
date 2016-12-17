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
Node* LCA(Node *root,int num1,int num2){
    if(root == NULL)
        return NULL;
    if(root->data == num1 or root->data == num2){
        return root;
    }
    Node* l = LCA(root->left,num1,num2);
    Node* r = LCA(root->right,num1,num2);
    if(l!=NULL and r!=NULL)
        return root;
    if(l==NULL and r==NULL)
        return NULL;
    return l!=NULL ? l : r;
}
int main(){
    Node *root = NULL;
    root = getNode(10);
    root->left = getNode(20);
    root->right = getNode(30);
    root->left->left = getNode(40);
    root->left->right = getNode(50);
    root->left->right->left = getNode(60);
    root->right->right = getNode(70);
    root->right->right->right = getNode(80);
    root->right->right->right->right = getNode(90);
    cout<< LCA(root,40,70)->data;
}
