/* 
* Reference: http://stackoverflow.com/questions/685060/design-a-stack-such-that-getminimum-should-be-o1 
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> st,minimum;
void Push(int n){
    st.push(n);
    if(minimum.empty()){
        minimum.push(n);
    }
    else if(minimum.top()>=n){
        minimum.push(n);
    }
}
void Pop(){
    if(st.empty())
        return ;
    int t = st.top();
    //cout<<"TOP"<<t<<endl;
    st.pop();
    if(minimum.top()==t)
        minimum.pop();
}
int GetMinimum(){
    if(!minimum.empty())
        return minimum.top();
    else
        return -1;
}
int main(){
    int c;
    cout<<"1. Push"<<endl
        <<"2. Pop"<<endl
        <<"3. Get Minimum"<<endl;
    while(cin>>c){
        switch(c){
        case 1:
            int item;
            cout<<"Push Data"<<endl;
            cin>>item;
            Push(item);
            break;
        case 2:
            Pop();
            break;
        case 3:
            cout<<"Minimum Value" <<" "<<GetMinimum()<<endl;
            break;
        default:
            return 0;
        }
    }
}
