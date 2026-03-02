class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int first = 0; first < n - 2; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int left = first + 1;
            int right = n - 1;
            while (left < right) {
                int curr_sum = nums[first] + nums[left] + nums[right];
                if (curr_sum == 0) {
                    result.push_back({nums[first], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (curr_sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};