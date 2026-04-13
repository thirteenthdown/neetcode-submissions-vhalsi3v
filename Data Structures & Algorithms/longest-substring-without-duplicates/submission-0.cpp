class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_set<char> char_set;
        int max_len = 0;
        int left = 0;
        for(int right=0; right<s.size(); right++){
            while(char_set.count(s[right])){
                char_set.erase(s[left]);
                left++;
            }
            char_set.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
