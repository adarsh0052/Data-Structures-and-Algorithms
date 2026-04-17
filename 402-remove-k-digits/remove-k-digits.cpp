class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk; // acts as our monotonic stack (increasing order)

        for (char digit : num) {
            // Remove digits from stack that are greater than current digit
            while (k > 0 && !stk.empty() && stk.back() > digit) {
                stk.pop_back();
                k--;
            }
            stk.push_back(digit);
        }

        // If k > 0, remove from the end (number is already non-decreasing)
        while (k > 0) {
            stk.pop_back();
            k--;
        }

        // Remove leading zeros
        int start = 0;
        while (start < (int)stk.size() - 1 && stk[start] == '0') {
            start++;
        }

        return stk.empty() ? "0" : stk.substr(start);
    }
};