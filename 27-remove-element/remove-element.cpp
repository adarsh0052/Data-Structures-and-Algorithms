class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n  = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]== val){
                n--;
                nums[i]=nums[n];
            }
            else{
                i++;
            }
        }
        return n;        
    }
};