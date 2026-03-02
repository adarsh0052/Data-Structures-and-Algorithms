class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int value;
        for(int i=0;i<n;i++){
            if(i<n-1&& nums[i]==nums[i+1]){
                i=i+1;
            }
            else{
                value=nums[i];
            }
        } 
        return value;
    }
};