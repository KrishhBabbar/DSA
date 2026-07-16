class Solution {
public:
    int longestKSubstr(string &s, int k) {

        // HashMap to store frequency of characters
        unordered_map<char, int> f;

        // Length of string
        int n = s.size();

        // Sliding window pointers
        int low = 0;
        int high = 0;

        // Stores maximum length of valid substring
        int res = INT_MIN;

        // Expand the window
        for (high = 0; high < n; high++) {

            // Include current character in window
            f[s[high]]++;

            // Shrink window if unique characters become greater than k
            while (f.size() > k) {

                // Remove leftmost character
                f[s[low]]--;

                // If frequency becomes zero, erase it
                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }

                // Move left pointer
                low++;
            }

            // If window contains exactly k unique characters
            if (f.size() == k) {

                // Calculate current window length
                int len = high - low + 1;

                // Update maximum length
                res = max(res, len);
            }
        }

        // No valid substring found
        if (res == INT_MIN)
            return -1;

        return res;
    }
};
