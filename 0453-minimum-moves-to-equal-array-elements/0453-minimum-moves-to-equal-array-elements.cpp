class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int minElement = *min_element(nums.begin(), nums.end());

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int moves = sum - (n * minElement);

        return moves;
    }
};