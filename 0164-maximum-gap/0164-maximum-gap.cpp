class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int z = INT_MIN;
        int n = nums.size();
        int i=0;
        int j=1;
        if(n<2){
           return 0;
            }
        while(j<n){
                int x = nums[j] - nums[i];
                if(x>z){
                    z = x;
                    i++;
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
        return z;
    }
};