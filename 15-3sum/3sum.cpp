class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int st = i+1, ed = n-1, sum = -1 * nums[i];
            while(st<ed){
                int s = nums[st] + nums[ed];
                if(s == sum){
                    ans.push_back({nums[i], nums[st], nums[ed]});
                    st++;
                    ed--;
                    while(st<ed && nums[st]==nums[st-1]){
                        st++;
                    }
                    while(st<ed && nums[ed]==nums[ed+1]){
                        ed--;
                    }}
                else if(s<sum){
                        st++;
                    }
                else{
                        ed--;
                    }
            }
        }

        return ans;
        
    }
};