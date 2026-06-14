class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n  = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == val){
                for(int idx = i+1; idx<n; idx++){
                    nums[idx-1] = nums[idx];
                }
            i--;
            n--;
            }
        }
        return n;        
    }
};