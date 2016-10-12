/*
   Time Comlexity : O(2^n)
   Reference: shouravschool
*/
#include<bits/stdc++.h>
using namespace std;
int value[100],istake[100],make;
int Solve(int sumSoFar,int currentIndex,int remainsum){
    istake[currentIndex ] = 1;
    if(sumSoFar+value[currentIndex]==make){
        for(int i = 0;i<=currentIndex;i++){
            if(istake[i]){
                cout<<value[i]<<" ";
            }
        }
        cout<<endl;
    }
    else if(sumSoFar+value[currentIndex]+value[currentIndex+1]<=make){
        Solve(sumSoFar+value[currentIndex],currentIndex+1,remainsum-value[currentIndex]);
    }
    if(sumSoFar+remainsum-value[currentIndex]>=make and sumSoFar+value[currentIndex+1]<=make){
        istake[currentIndex] = 0;
        Solve(sumSoFar,currentIndex+1,remainsum-value[currentIndex]);
    }
}
int main(){
    int n,r = 0;
    cin>>n>>make;
    for(int i = 0;i<n;i++){
        cin>>value[i];
        istake[i]=0;
        r+=value[i];
    }
    sort(value,value+n);
    Solve(0,0,r);
}
