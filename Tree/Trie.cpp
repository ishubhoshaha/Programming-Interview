/*
Assume word only contains small alphabetical letter.
Inserting Time Complexity : O(stringLength)
Searching Time Complexity : O(stringLength)
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    bool isEnd;
    node *next[26];
    node(){
        isEnd = false;
        for(int i = 0;i<26;i++){
            next[i] = NULL;
        }
    }
};
void Insert(node *root,string inp){
    node *temp = root;
    int n = inp.size();

    for(int i = 0;i<n;i++){
        int id = inp[i]-'a';
        if(temp->next[id] ==NULL){
            temp->next[id] = new node();
        }
        temp = temp->next[id];
    }
    temp->isEnd = true;
}
bool Check(node *root,string inp){
    node *temp = root;
    int n = inp.size();
    for(int i = 0;i<n;i++){
        int id = inp[i]-'a';
        if(temp->next[id]==NULL)
            return false;
        temp = temp->next[id];
    }
    return temp->isEnd;
}
int main(){
    node *root = new node();
    cout<<"Insert Word: ";
    string inp;
    for(int i= 0;i<5;i++){
        cin>>inp;
        Insert(root,inp);
    }
    cout<<endl<<"Query: ";
    for(int i= 0;i<5;i++){
        cin>>inp;
        Check(root,inp)?cout<<"Exist\n" : cout<<"Not Exist\n";
    }

}
