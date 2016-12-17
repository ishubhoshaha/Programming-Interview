#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(){
        left = NULL;
        right = NULL;
    }
};
Node* NewNode(int data){
    Node *temp = new Node();
    temp->data = data;
    return temp;
}
Node* Insert(Node *root, int data){
    if(root == NULL){
        root = NewNode(data);
    }else if(root->data<=data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;
}
bool isSame(Node *root1,Node *root2){
    if(root1==NULL and root2==NULL){
        return true;
    }else if(root1==NULL || root2==NULL){
        return false;
    }
    else if(root1->data!=root2->data){
        //cout<<root1->data<<" "<<root2->data;
        return false;
    }
    isSame(root1->left,root2->left);
    isSame(root1->right,root2->right);
    return true;

}
int main(){
    Node *tree1 = NULL,*tree2 = NULL;
    tree1 = Insert(tree1,12);
    tree1 = Insert(tree1,29);
    tree1 = Insert(tree1,8);
    tree1 = Insert(tree1,77);
    tree1 = Insert(tree1,32);
    tree1 = Insert(tree1,90);
    tree1 = Insert(tree1,45);
    tree1 = Insert(tree1,122);
    tree1 = Insert(tree1,1);

    tree2 = Insert(tree2,12);
    tree2 = Insert(tree2,29);
    tree2 = Insert(tree2,8);
    tree2 = Insert(tree2,77);
    tree2 = Insert(tree2,32);
    tree2 = Insert(tree2,90);
    tree2 = Insert(tree2,45);
    tree2 = Insert(tree2,122);
    tree2 = Insert(tree2,1);
    isSame(tree1,tree2)?cout<<"YES":cout<<"No";
}
