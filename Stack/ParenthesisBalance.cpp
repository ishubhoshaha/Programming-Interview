#include<bits/stdc++.h>
using namespace std;
bool isOpening(char ch){
    if(ch=='(' or ch=='{' or ch=='[')
        return true;
    else return false;
}
bool isMatched(char op,char close){
    if( (op=='(' and close==')') or (op=='{' and close=='}') or (op=='[' and close==']') )
        return true;
    else
        return false;
}
bool isBalanced(string inp){
    stack<int>st;
    for(int i = 0;i<inp.size();i++){
        if(isOpening(inp[i])){
            st.push(inp[i]);
            //cout<<inp[i]<<" "<<i<<endl;
        }
        else{
            char ch = st.top();
            //cout<<ch;
            st.pop();
            if(!isMatched(ch,inp[i])){
                //cout<<ch<<" "<<inp[i]<<" "<<i<<endl;
                return false;
            }
        }
    }
    if(!st.empty())
        return false;
    else return true;
}
int main(){
    string inp ="[()]{}{[()()]()}";
    isBalanced(inp)?cout<<"Yes":cout<<"No";
}
