class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        start = 0
        max_len = 0
        char_index_map = {} 
        
        for end, char in enumerate(s):            
            if char in char_index_map:
                idx = char_index_map[char]
                
                if idx >= start:
                    start = idx + 1
            
            current_length = end - start + 1
            max_len = max(max_len, current_length)
            
            char_index_map[char] = end
            
        return max_len