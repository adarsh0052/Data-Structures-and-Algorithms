class Solution {
public:
    int numofsubarrays(vector<int>& nums, int capacity) {
        int subarrays = 1, total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (total + nums[i] > capacity) {
                subarrays++;
                total = nums[i];
            } else {
                total += nums[i];
            }
        }
        return subarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > low) low = nums[i];
            high += nums[i];
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int subarrays = numofsubarrays(nums, mid);
            if (subarrays > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};