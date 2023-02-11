#include<iostream>
#include<vector>
using namespace std;
int bad;
bool isBadVersion(int x){
    if (x > bad) return true;
    else return false;
}
int firstBadVersion(int n) {
        int lo =1,hi= n,ans = -1;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            if(isBadVersion(mid)){
                ans = mid;
                hi = mid-1;
            }else lo =mid+1;
        }
        return ans;
}
int searchInsert(vector<int>& arr, int target) {
        if(target<arr[0] ) return 0;
        
        int n =arr.size(),hi=n-1;
        if(target>arr[n-1]) return n;
        int lo = 0;
        while(hi>=lo){
            int mid =lo+(hi-lo)/2;
            if(arr[mid] == target){
                return mid;
            }else if(mid+1<n && arr[mid] < target && target <arr[mid+1]) return mid+1;
            else if(arr[mid]<target) lo=mid+1;
            else hi = mid-1;
        }
        return -1;
}

int search(vector<int>& nums, int target) {
        int idx = -1;
        int lo = 0, high = nums.size()-1,mid ;
        while(lo<=high){
            mid = lo+ (high-lo)/2;
            if(nums[mid]==target) {idx = mid;break;}
            else if(nums[mid]<target) lo= mid+1;
            else high = mid-1;

        }
        return idx;
}
int searchInsertPos(vector<int>& nums, int target) {
        int ans=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return ans;
}
int main(){ 

}