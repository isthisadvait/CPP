#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0 or n==1){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
  cout<<factorial(5);
}