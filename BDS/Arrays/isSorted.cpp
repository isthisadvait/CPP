#include<iostream>
#include<vector>
using namespace std;
bool isSorted(vector<int>&v){
    
    for(int i =1 ;i<v.size();i++){
        if(v[i]<v[i-1]) return false;
    }
    return true;
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0 ;i<n ;i++) cin>>v[i];
    cout<<isSorted(v);
}