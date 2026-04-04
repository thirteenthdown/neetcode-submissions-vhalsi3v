class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_count;
        unordered_map<char, int> t_count;
        for(auto const& i : s){
            s_count[i]++;
        }
        for(auto const& j : t){
            t_count[j]++;
        }
        return s_count == t_count;
    }
};
