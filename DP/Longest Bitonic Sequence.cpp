/* SRC : youtube.com/TR
*/

#include<bits/stdc++.h>
using namespace std;

int seq1[100],seq2[100];
void LIS(int arr[],int n){
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
        if(x==v.size()){
            v.push_back(arr[i]);
            seq1[i] = v.size();
        }
        else{
            v[x] = arr[i];
            seq1[i] = x+1;
        }
    }
    //cout<<v.size();
}
void LIS1(int arr[],int n){
    vector<int> v;
    for(int i = n;i>=0;i--){
        int x = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
        if(x==v.size()){
            v.push_back(arr[i]);
            seq2[i] = v.size();
        }
        else{
            v[x] = arr[i];
            seq2[i] = x+1;
        }
    }
    //cout<<v.size();
}
int main(){
    freopen("inp.txt","r",stdin);
    int arr[100],arrrev[100],n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        arrrev[n-i-1] = arr[i];
    }

    LIS(arr,n);
    LIS1(arr,n);
    int mx = INT_MIN;
    for(int i = 0;i<n;i++){
        //cout<<seq2[i]<<" ";
        mx = max(mx,(seq1[i]+seq2[i]));
    }
    cout<<mx-1;
}
