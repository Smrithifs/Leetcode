class Longest {
    public:
        int longestConsecutive(std::vector<int>& nums) {
            std::unordered_set<int> numSet(nums.begin(), nums.end());
            int longest = 0;
    
            for (int num : numSet) {
                // Only start counting if it's the start of a sequence
                if (numSet.find(num - 1) == numSet.end()) {
                    int currentNum = num;
                    int streak = 1;
    
                    while (numSet.find(currentNum + 1) != numSet.end()) {
                        currentNum++;
                        streak++;
                    }
    
                    longest = std::max(longest, streak);
                }
            }
    
            return longest;
        }
    };
    
