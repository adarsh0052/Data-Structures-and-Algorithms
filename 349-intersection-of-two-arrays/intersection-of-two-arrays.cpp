class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());
        vector<int>nums3;
        for(int i : s1){
            if (s2.count(i)){
                nums3.push_back(i);
            }        
        }
        return nums3;
    }
};