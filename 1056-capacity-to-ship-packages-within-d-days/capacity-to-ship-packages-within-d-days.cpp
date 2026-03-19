class Solution {
public:
    int numofdays(vector<int>& weights, int capacity) {
        int daysreq = 1, load = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            if (weights[i] + load > capacity) {
                daysreq++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return daysreq;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0, hi = 0;
        for (int w : weights) {
            if (w > lo) lo = w;
            hi += w;
        }
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (numofdays(weights, mid) <= days)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};