class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        stringstream ss(s);  // stream helps split by spaces

        while (ss >> word) {  // automatically ignores multiple spaces
            words.push_back(word);
        }

        reverse(words.begin(), words.end()); // reverse the word order

        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " "; // add space except after last word
        }

        return result;
    }
};
