class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff;
        int m = INT_MAX;
        int result_sum;

        for(int i = 0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                diff = abs(sum-target);
                if(diff<m){
                    m = diff;
                    result_sum = sum;
                }
                else if(sum>target){
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else if(sum == target){
                    return target;
                }
            }
        }
        return result_sum;
    }
};