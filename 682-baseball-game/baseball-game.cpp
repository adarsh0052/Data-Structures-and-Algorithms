class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int sum = 0;
        vector<int> st;
        for(int i=0; i<n; i++){
            int j = st.size();
            if(operations[i] =="+"){
                st.push_back(st[j-1] +st[j-2]);
                j++;
            }
            else if(operations[i] == "D"){
                st.push_back(2*(st[j-1]));
                j++;
            }
            else if(operations[i] == "C"){
                st.pop_back();
            }
            else{
                st.push_back(stoi(operations[i]));
            }
        }
        for(int i : st){
            sum = sum + i;
        }
        return sum;
    }
};