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
void LevelOrderTraverse(Node* root){
    if(root==NULL)
        return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        cout<<temp->data<<" ";

    }
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
    LevelOrderTraverse(root);
}
