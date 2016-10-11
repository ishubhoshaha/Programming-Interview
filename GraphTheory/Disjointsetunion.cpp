/*
    Time Complexity: O(logN) if we keep track the size of Component unless its O(N)
    Reference:  https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
int arr[MAX];
int sizeofComponent[MAX];
void initialize(){
    for(int i = 0;i<MAX;i++){

        arr[i] = i;
        sizeofComponent[i] = 1;
    }
}
int Root(int i){
    while(arr[i]!=i)
        i = arr[i];
    return i;
}
/*connect the elements by just changing the root of one of the element*/

//int Union(int a,int b){
//    int rootofA = Root(a);
//    int rootofB = Root(b);
//    arr[rootofA] = rootofB; //set parent of root(A) as root(B).
//}

/*
    While connecting two elements, we do not check which subset has more element than other and sometimes
    it creates a big problem as in worst case we have to perform approximately linear time operations.
    That is why we connect the root which has smaller number of elements to the root of subset which has larger number of elements.
*/
int Union(int a,int b){
    int rootofA = Root(a);
    int rootofB = Root(b);
    if(sizeofComponent[rootofB]<=sizeofComponent[rootofA]){
        arr[rootofB] = arr[rootofA];
        sizeofComponent[rootofA] += sizeofComponent[rootofB];
    }
    else if (sizeofComponent[rootofB]>sizeofComponent[rootofA]){
        arr[rootofA] = arr[rootofB];
        sizeofComponent[rootofB] += sizeofComponent[rootofA];
    }
}
bool Find(int a,int b){
    if(Root(a)==Root(b))
        return true; /// means a and b are connected with each other
    else
        return false;
}
int main(){
    initialize();
    Union(0,1);
    Union(1,2);
    Union(3,2);
    set<int>st;
    for(int i = 0;i<=5;i++){
        st.insert(arr[i]);
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Number Of Component: "<<st.size()<<endl;
    int x = 0,y = 5;
    if(!Find(x,y)){
        cout<<x<<" and "<<y<<" are not connected with each other"<<endl;
    }
    else {
        cout<<x<<" and "<<y<<" are connected with each other"<<endl;
    }
}
