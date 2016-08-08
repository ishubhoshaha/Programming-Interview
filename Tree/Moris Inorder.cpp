/*
         10
         /\
        5  30
       /\   \
     -2  6   40
      \   \
       2   8
       /
      -1
* Time Complexity of this Solution: O(n)
* Source: TusharRoy
*/
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
void MorisTravarsal(Node *root){
    Node *current = root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            Node *predecessor = current->left;
            while(predecessor->right!=current and predecessor->right!=NULL){

                predecessor = predecessor->right;
            }
            if(predecessor->right==NULL){
                predecessor->right = current;
                current = current->left;
            }
            else{
                predecessor->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}
void Inorder(Node* root){
    if(root == NULL)
        return ;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
int main(){
    Node *root = NULL;
    root = getNode(10);
    root->left = getNode(5);
    root->left->left = getNode(-2);
    root->left->left->right = getNode(2);
    root->left->left->right->left = getNode(-1);
    root->right = getNode(30);
    root->right->right = getNode(40);
    MorisTravarsal(root);
    cout<<endl;
    Inorder(root);
}
