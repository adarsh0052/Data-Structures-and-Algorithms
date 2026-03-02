class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;
        while(left <= right){
            int curr_sum = numbers[left]+numbers[right];
            if(curr_sum == target){
                return {left+1, right + 1};
            } 
            else if( curr_sum < target ){
                left += 1;
            }           
            else{
                right -= 1;
            }

            }
        return {};
    }
};