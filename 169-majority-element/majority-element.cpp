class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int half = n/2;
        unordered_map<int,int> countmap;
        for(int i=0;i<n;i++){
            countmap[nums[i]]++;
        }
        int mje;
        for(auto it : countmap){
            if(it.second > half){
                mje = it.first;
            }
        }
        return mje;
    }
};