class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;

            // Calculate sum of digits
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            // Check condition
            if (sum == i) {
                return i;
            }
        }

        return -1;
    }
};