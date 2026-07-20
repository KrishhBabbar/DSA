class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        vector<int> f(2, 0);

        int low = 0;
        int res = 0;

        for (int high = 0; high < nums.size(); high++) {

            f[nums[high]]++;

            while (f[0] > k) {      
                f[nums[low]]--;
                low++;
            }
            int len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};