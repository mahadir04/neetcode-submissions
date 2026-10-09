class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; 
        
        vector<int> res = nums;
        int lon = 1;
        sort(res.begin(), res.end()); 
        
        int i = 0, count = 1;
        
        while(i + 1 < res.size()) 
        {
            if (res[i+1] - res[i] == 1) 
            {
                count++;
                i++;
            }
            else if (res[i+1]==res[i])
            {
                i++;
            }
            else
            {
                lon = max(lon, count);
                count = 1;
                i++;
            }
        }
        return max(lon,count);
    }
};