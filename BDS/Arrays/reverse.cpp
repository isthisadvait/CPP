#include<iostream>
#include<vector>
using namespace std;
void reverseArray(vector<int>&v){
    int low = 0 ,high = v.size()-1 ; 
   while(low < high){
    int temp = v[low];
    v[low++] = v [high];
    v[high--] = temp ;
    
   }
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i<n ; i++) cin>>v[i];
    reverseArray(v);
    for(int i = 0 ; i<n ; i++) cout<<v[i]<<" ";
}