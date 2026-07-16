#include <bits/stdc++.h>
using namespace std;

// This is a two pointers approach to count the number of triplets in an array that have a sum smaller than a given value. The function first sorts the input array arr. It then iterates through the array using an index i, treating arr[i] as the first element of the triplet. For each i, it uses two pointers, j and k, to find pairs of elements that, when added to arr[i], yield a sum smaller than the given sum. If the sum of arr[i], arr[j], and arr[k] is smaller than the target sum, it counts all pairs between j and k (i.e., k - j) as valid triplets and increments j. If the sum is greater than or equal to the target sum, it decrements k. Finally, it returns the total count of such triplets found.

class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int count = 0;
        
        for(int i = 0 ;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int s = arr[i] + arr[j] + arr[k];
                if(s == sum){
                    k--;
                }
                if(s>sum){
                    k--;
                }
                if(s<sum){
                    count+=k-j;
                    j++;
                }
            }
        }
        return count;
    }
};
