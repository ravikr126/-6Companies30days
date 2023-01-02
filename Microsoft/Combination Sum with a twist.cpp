class Solution {
public:
    vector<vector<int>> ans;
    int sum(vector<int> &nums){
        int res=0;
        for(auto x: nums){
            res+=x;
        }
        return res;
    }
    void helper(int k, int n , vector<int> &nums, int num){
        //Base Case
        if(k==0){
            if(sum(nums)==n){
                ans.push_back(nums);
            }
            return;
        }
        
        if(num>9)
            return;
        
        nums.push_back(num); 
        helper(k-1, n, nums, num+1);   //pick then num
        nums.pop_back();
        helper(k, n , nums, num+1);    //not pick the num
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        helper(k, n, nums, 1);
        return ans;
    }
};