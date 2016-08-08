#include<bits/stdc++.h>
using namespace std;
int freq[27];
struct Node
{
    char data;
    int frequency;
    Node *left,*right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};
struct compare
{
    bool operator()(Node* left, Node* right)
    {
        return (left->frequency > right->frequency);
    }
};
void print(Node *root,string str){
    if(root==NULL)
        return ;
    if(root->data!='$')
        cout<<root->data<<" "<<str<<endl;
    print(root->left,str+"0");
    print(root->right,str+"1");
}
void Compress(int sz)
{
    priority_queue<Node*,vector<Node*>,compare> pq;
    for(int i = 0;i<sz;i++)
    {
        Node *temp = new Node();
        if(freq[i]<1)
            continue;
        temp->data = 'a'+ i;
        temp->frequency = freq[i];
        //cout<<temp->frequency<<" "<<temp->data<<endl;
        pq.push(temp);
    }
//    while(!pq.empty()){
//        Node *temp = pq.top();
//        cout<<temp->frequency<<" "<<temp->data<<endl;
//        pq.pop();
//    }
    while(pq.size()>1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *temp = new Node();
        temp->data = '$';
        temp->frequency = left->frequency + right->frequency;
        temp->left = left;
        temp->right = right;
    //    cout<<left->data<<" "<<right->data<<endl;
        pq.push(temp);
    }
    print(pq.top(),"");
}
int main()
{
    //freopen("inp.txt","r",stdin);
    string str;
    cin>>str;

    for(int i = 0;i<str.size();i++)
    {
        freq[str[i]-'a']++;
    }
    cout<<"Frequency of \""<<str<<"\""<<endl;
    for(int i = 0;i<27;i++){
        if(freq[i]){
            char ch = 'a' + i;
            cout<<ch<<" "<<freq[i]<<endl;
        }
    }
    cout<<"After Compress: "<<endl;
    Compress(27);
}
