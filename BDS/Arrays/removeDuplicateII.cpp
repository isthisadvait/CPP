//Remove Duplicates From Sorted Array
#include<iostream>
#include<vector>
using namespace std;
//two instances allowed
int removeDuplicates(vector<int>&v){
    int i = 0 ; 
    for(int item : v){
        if(i<2 || v[i-2] != item){
             v[i++] = item;
        }
    }
    return i;
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i<n ; i++) cin>>v[i];
    int x = removeDuplicates(v);
    cout<<x<<endl;
    for(int i = 0 ; i<x; i++) cout<<v[i]<<" ";
}