class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int w = 2*n;
        vector<int> arr(w);
        for(int i=0;i<n;i++){
           arr[i] = nums[i];
        }
        for(int j = n; j < w; j++){
            arr[j] = nums[j-n];
        }
        return arr;
    }
};