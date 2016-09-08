/*
TimeComplexity: O(n)
SpaceComplexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    int n,mx = -1,tp,area;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    stack<int>st;

    for(int i = 0;i<n;i++){
        if(st.empty()){
            st.push(i);
        }
        else{

            if(a[st.top()]<=a[i]){
                st.push(i);
            }
            else{
                while(a[st.top()]>a[i]){

                    tp = st.top();
                    st.pop();
                    if(st.empty()){
                        area = a[tp] * i;
                        mx = max(mx,area);
                        break;
                    }else{
                        area = a[tp] * (i-st.top()-1);
                        mx = max(mx,area);
                    }


                }
                st.push(i);
            }
        }
    }
    while(!st.empty()){
        tp = st.top();
        st.pop();
        if(st.empty())
            area = a[tp] * n;
        else{
            area = a[tp] * (n-st.top()-1);
        }
        mx = max(mx,area);
    }
    cout<<mx;
}
