class Solution {
public:
    string mergeAlternately(string firstWord, string secondWord) {

        string mergedWord = "";               // final result
        int pointerA = 0;                    // tracks position in firstWord
        int pointerB = 0;                    // tracks position in secondWord

        // Continue until both strings are fully processed
        while (pointerA < firstWord.length() || pointerB < secondWord.length()) {

            // If characters are still left in firstWord, take the next one
            if (pointerA < firstWord.length()) {
                mergedWord += firstWord[pointerA];
                pointerA++;
            }

            // If characters are still left in secondWord, take the next one
            if (pointerB < secondWord.length()) {
                mergedWord += secondWord[pointerB];
                pointerB++;
            }
        }

        return mergedWord;
    }
};
