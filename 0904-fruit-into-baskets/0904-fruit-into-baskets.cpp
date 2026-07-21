class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> f;
        int n = fruits.size();
        int res = INT_MIN; //stores result
        int high = 0;
        int low = 0;

        for(high = 0; high<n; high++){
            f[fruits[high]]++; //add frequency of fruits at high in hashmap
            while(f.size() > 2){
                f[fruits[low]]--; //if hashmap size is > 2 remove low 
                if(f[fruits[low]] == 0){ //check if frequency is 0 if yes then remove from hashmap
                    f.erase(fruits[low]);
                }
                low++; //increase low
            }
            int len = high-low+1; //find len
            res = max(len,res); //find max
        }
        return res;
    }
};