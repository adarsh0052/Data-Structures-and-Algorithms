class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Count frequencies
        for (int num : nums) {
            mp[num]++;
        }

        // Move hashmap entries to vector
        vector<pair<int, int>> freq(mp.begin(), mp.end());

        // Sort by frequency in descending order
        sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Take top k
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};