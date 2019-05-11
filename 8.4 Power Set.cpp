/*
8.4 Power Set: Write a method to return all subsets of a set.
*/
class Solution {
private:
    void bkt(vector<int>& nums,vector<vector<int>>& res,int start,vector<int>& tmp){
        res.push_back(tmp);
        for(int i=start;i<nums.size();i++){
            tmp.push_back(nums[i]);
            bkt(nums,res,i+1,tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        bkt(nums,res,0,tmp);
        return res;
    }
};
