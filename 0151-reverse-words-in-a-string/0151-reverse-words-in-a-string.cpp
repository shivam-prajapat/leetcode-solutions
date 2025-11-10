class Solution {
public:
    string reverseWords(string sentence) {

        vector<string> collectedWords;    // stores each extracted word
        string buildingWord = "";         // used to build a word character by character

        // STEP 1: Read the sentence and collect words manually
        for (char letter : sentence) {

            if (letter == ' ') {
                // When we hit a space, check if we have built a word
                if (!buildingWord.empty()) {
                    collectedWords.push_back(buildingWord);
                    buildingWord = "";  // reset to start capturing new word
                }
            } 
            else {
                // add characters to build a word
                buildingWord += letter;
            }
        }

        // Add the last word if it exists (sentence may not end with space)
        if (!buildingWord.empty()) {
            collectedWords.push_back(buildingWord);
        }


        // STEP 2: Now reverse the order of words
        reverse(collectedWords.begin(), collectedWords.end());


        // STEP 3: Join the words back into a sentence with single spaces
        string finalSentence = "";

        for (int index = 0; index < collectedWords.size(); index++) {
            finalSentence += collectedWords[index];

            // Add a space only between words, not after the last one
            if (index != collectedWords.size() - 1) {
                finalSentence += " ";
            }
        }

        return finalSentence;
    }
};
