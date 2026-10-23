class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int current_sum = 0;
        int target_sum = threshold * k;
        for (int i = 0; i < k; ++i) {
            current_sum += arr[i];
        }
        if (current_sum >= target_sum) {
            count++;
        }
        for (int i = k; i < arr.size(); ++i) {
            current_sum += arr[i] - arr[i - k];
            if (current_sum >= target_sum) {
                count++;
            }
        }
        return count;
    }
};