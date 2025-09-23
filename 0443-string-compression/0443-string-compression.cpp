class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; // position to write compressed result
        
        for (int i = 0; i < n; ) {
            char currentChar = chars[i];
            int count = 0;
            
            // Count consecutive same chars
            while (i < n && chars[i] == currentChar) {
                i++;
                count++;
            }
            
            // Write the char
            chars[index++] = currentChar;
            
            // Write the count if > 1
            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[index++] = c;
                }
            }
        }
        
        return index;
    }
};
