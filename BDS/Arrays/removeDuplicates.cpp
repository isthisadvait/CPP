//Remove Duplicates From Sorted Array
#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>&v){
    int ans = 0 ; 
    for(int i = 1 ; i < v.size() ; i++){
        if(v[i] > v[ans]){  // if number is not included  , just include it .
             ans++ ; 
             v[ans] = v[i] ;
        }
    }
    return ans+1;
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i<n ; i++) cin>>v[i];
    cout<<removeDuplicates(v)<<endl;
    for(int i = 0 ; i<n ; i++) cout<<v[i]<<" ";
}