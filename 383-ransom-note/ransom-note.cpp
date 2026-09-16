class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Array to store the frequency of each lowercase letter
        vector<int> charCounts(26, 0);
        
        // Count the occurrences of each character in the magazine
        for (char c : magazine) {
            charCounts[c - 'a']++;
        }
        
        // Check if we have enough characters for the ransom note
        for (char c : ransomNote) {
            charCounts[c - 'a']--;
            
            // If the count drops below 0, we don't have enough of that letter
            if (charCounts[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};