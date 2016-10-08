#include<bits/stdc++.h>
using namespace std;
int used[20]={0},result[20];
int arr[20];
void permution(int i,int sz){
    if(i==sz){
        for(int j = 0;j<sz;j++){
            cout<<result[j];
        }
        cout<<endl;
        return ;
    }
    for(int j = 0;j<sz;j++) if(used[j]==0){
        used[j] = 1;
        result[i] = arr[j];
        permution(i+1,sz);
        used[j] = 0;
    }

}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    permution(0,n);
}
