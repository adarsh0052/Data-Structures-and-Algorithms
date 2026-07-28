class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0,0};
        for(int i : students){
            count[i]++;
        }
        for(int j : sandwiches){
            if(count[j]==0){break;}
            else{
                count[j]--;
            }
        }
        return count[0] + count[1];        
    }
};