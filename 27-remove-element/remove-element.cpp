class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            if (val == nums[i]) {
                nums.erase(nums.begin() + i);
                i--;     
                sz--;    
            }
        }

        return nums.size();
    }
};
