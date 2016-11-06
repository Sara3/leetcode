int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k <= 0) return 0;
        unordered_map<char, int> count_map;
        int i = 0, j = 0, max_len = 0;
        while (j < s.size())
        {
            if (count_map.size() > k)
            {
                auto iter = count_map.find(s[i]);
                iter->second --;
                if (iter->second == 0)
                    count_map.erase(iter);
                i ++;
            }else{
                max_len = max(j - i, max_len);
                count_map[s[j]] ++;
                j ++;
            }
        }
        if (count_map.size() <= k)
            max_len = max(j - i, max_len);
        return max_len;
    }

     int main()
    {
        string s = "threre";
        int k=3;
        int res = lengthOfLongestSubstringKDistinct(s, k);
        return 0;
    }