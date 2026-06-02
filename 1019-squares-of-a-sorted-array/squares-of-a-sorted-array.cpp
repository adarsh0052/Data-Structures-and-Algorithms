class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int ed = n-1;
        vector <int> res(n);
        int pos = n-1;
        while(st<=ed){
            if(abs(nums[st])<abs(nums[ed])){
                res[pos] = nums[ed] * nums[ed];
                pos--;
                ed--;
            }
            else{
                res[pos] = nums[st] * nums[st];
                pos--;
                st++;
            }
        }
         return res;
    }
};
        
       