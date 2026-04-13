class Solution {
public:
    vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> nge; // value -> its NGE in nums2

        // build NGE map for all elements in nums2
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                nge[nums2[i]] = -1;
            } else {
                nge[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        // answer for each element in nums1
        vector<int> result;
        for (int x : nums1) {
            result.push_back(nge[x]);
        }

        return result;
    }
};