class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> mer;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                mer.push_back(nums1[i]);
                i++;
            }
            else{
                mer.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            mer.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            mer.push_back(nums2[j]);
            j++;
        }
        
        int size = mer.size();

        if (size % 2 == 0) {
            return (mer[size/2] + mer[size/2 - 1]) / 2.0;
}
        else {
            return mer[size/2];
}
    }
};