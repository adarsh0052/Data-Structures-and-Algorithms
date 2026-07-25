class MinStack {
public: 
    vector<int> st;     
    vector<int> minst; 
    MinStack() {  
    }
    
    void push(int val) {
        st.push_back(val); 
        if(minst.size() == 0){
           minst.push_back(val);
        }       
        else{
            int m = minst.size();
            if( val <= minst[m-1]){
                minst.push_back(val);
            }
        }
    }
    
    void pop() {
        int n = st.size();
        int m = minst.size();
        if(st[n-1] == minst[m-1]){
            minst.pop_back();
        }
        st.pop_back(); 
    }
    
    int top() {
        int n = st.size();
        return st[n-1];        
    }
    
    int getMin() {
        int m = minst.size();
        return minst[m-1];
    }
};