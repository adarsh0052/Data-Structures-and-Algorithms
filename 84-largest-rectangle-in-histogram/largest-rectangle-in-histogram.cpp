class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;   // monotonic increasing stack (stores indices)
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // Use 0 as sentinel height when i == n
            int currHeight = (i == n) ? 0 : heights[i];

            // While current bar is shorter than stack top → calculate area
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                // Width: distance between current right boundary and left boundary
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};