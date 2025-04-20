class Solution {
    public:
        std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
            if (intervals.empty()) return {};
    
            
            std::sort(intervals.begin(), intervals.end());
    
            std::vector<std::vector<int>> merged;
            merged.push_back(intervals[0]);
    
            for (int i = 1; i < intervals.size(); ++i) {
                std::vector<int>& last = merged.back();
    
                
                if (intervals[i][0] <= last[1]) {
                    last[1] = std::max(last[1], intervals[i][1]); // Merge
                } else {
                    merged.push_back(intervals[i]);
                }
            }
    
            return merged;
        }
    };
    