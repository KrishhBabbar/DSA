class Solution {
public:
int find(vector<int> &a){
    int maxcount = -1;
    for(int i=0;i<256;i++){
        maxcount = max(maxcount,a[i]);
    }
    return maxcount;
}
    int characterReplacement(string s, int k) {
        vector<int> f(256,0);
        int n = s.size();
        int low = 0;
        int high = 0;
        int res = INT_MIN;

        for(high = 0; high<n; high++){
            f[s[high]]++;
            int maxc = find(f);
            int len = high - low + 1;
            int diff = len - maxc; 
            while(diff>k){
                f[s[low]]--;
                low++;
                maxc = find(f);
                len = high - low + 1;
                diff = len - maxc;
            }
            len = high - low + 1;
            res = max(res,len);
        }
        return res;
    }
};