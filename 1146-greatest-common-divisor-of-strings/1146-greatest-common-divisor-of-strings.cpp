class Solution {
public:
    string gcdOfStrings(string firstString, string secondString) {

        // Step 1: Check if they can be formed by the same pattern
        if (firstString + secondString != secondString + firstString) {
            return "";   // No common base pattern
        }

        // Step 2: Find GCD of their lengths
        int len1 = firstString.size();
        int len2 = secondString.size();

        int gcdLength = findGCD(len1, len2);

        // Step 3: The GCD substring from firstString is the answer
        return firstString.substr(0, gcdLength);
    }

private:
    // Helper function to find GCD of two numbers
    int findGCD(int a, int b) {
        if (b == 0) return a;
        return findGCD(b, a % b);
    }
};
