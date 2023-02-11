 #include<iostream>
#include<vector>
using namespace std;
 vector<int> shuffle(vector<int>& nums, int n) {
        // Store each y(i) with respective x(i).
        for (int i = n; i < 2 * n; ++i) {
            int secondNum = nums[i] << 10;
            int firstNum = nums[i-n] ;
            nums[i-n] = firstNum | secondNum;
        }

        // '0000000000 1111111111' in decimal.
        int allOnes = pow(2, 10) - 1;

        // We will start putting all numbers from the end, 
        // as they are empty places.
        for (int i = n - 1; i >= 0; --i) {
            // Fetch both the numbers from the current index.
            int secondNum = nums[i] >> 10;
            int firstNum = nums[i] & allOnes;
            nums[2 * i + 1] = secondNum;
            nums[2 * i] = firstNum;
        }
        return nums;
    
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0 ;i<n ;i++) cin>>v[i];
    cout<<shuffle(v,n);
}