/*
10.3
Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        if(nums.size()==0) return -1;
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]>nums[j]){
                if(nums[mid]<target||target<=nums[j]) i=mid+1;
                else j=mid;
            }
            else{
                if(nums[mid]<target&&target<=nums[j]) i=mid+1;
                else j=mid;
            }
        }
        if(i==j&&nums[i]!=target) return -1;
        return i;
    }
};
