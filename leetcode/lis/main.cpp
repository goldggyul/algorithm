// https://leetcode.com/submissions/detail/688887577/

class Solution {
public:
    
    vector<int> lastVal;
    int length[2501];

    void lis(vector<int>& nums){
        lastVal.clear();
        lastVal.push_back(-10'001);
        for(int i=0;i<nums.size();i++){
            if(lastVal.back()<nums[i]){
                lastVal.push_back(nums[i]);
            }
            vector<int>::iterator it = lower_bound(lastVal.begin(), lastVal.end(), nums[i]);

            *it=nums[i];
            length[i] = it - lastVal.begin();
        }    
    }
    
    int lengthOfLIS(vector<int>& nums) {
        lis(nums);
        
        return lastVal.size()-1;
    }
};
