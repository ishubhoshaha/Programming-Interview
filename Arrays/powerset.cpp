#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[20];///Maximum 20 element
    int n = 3;
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    int sz_of_power_set = 1<<n;
    for(int i = 0;i<sz_of_power_set;i++){
        for(int j = 0;j<n;j++){
            if((i>>j)&1)
                cout<<arr[j];
        }
        cout<<endl;
    }
    return 0;
}
