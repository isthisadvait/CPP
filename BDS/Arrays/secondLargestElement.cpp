#include<iostream>
#include<vector>
using namespace std;
int  secondLargestElement(vector<int>&v){
    int second = -1 ,first = 0 ;
    for(int i =1 ;i<v.size();i++){
        if(v[first]<v[i]) {
            second = first ;
            first = i ;
        }else if(v[first]!= v[i]){
            if(second == -1 || v[second] < v[i]){
                      second = i;
            }

        }
    }
    return second;
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0 ;i<n ;i++) cin>>v[i];
    cout<<secondLargestElement(v);
}