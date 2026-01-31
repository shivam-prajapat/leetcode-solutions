class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        // If the target is greater than or equal to the last character,
        // the answer wraps around to the first character.
        if (target >= letters.back()) {
            return letters[0];
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If mid is greater than target, it could be the answer,
            // but we look left to see if there is a smaller one.
            if (letters[mid] > target) {
                right = mid - 1;
            } else {
                // If mid is <= target, we must look to the right.
                left = mid + 1;
            }
        }

        // 'left' will point to the smallest element greater than target
        return letters[left];
    }
};