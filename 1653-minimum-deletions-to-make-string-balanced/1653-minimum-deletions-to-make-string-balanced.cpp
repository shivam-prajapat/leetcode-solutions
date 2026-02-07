class Solution {
public:
    int minimumDeletions(std::string s) {
        int deletions = 0;
        int b_count = 0;
        
        for (char c : s) {
            if (c == 'b') {
                // Keep track of 'b's encountered so far
                b_count++;
            } else {
                // We found an 'a'. If there are 'b's before it, 
                // we must decide to delete either this 'a' or one of the 'b's.
                if (b_count > 0) {
                    deletions = std::min(deletions + 1, b_count);
                }
            }
        }
        
        return deletions;
    }
};