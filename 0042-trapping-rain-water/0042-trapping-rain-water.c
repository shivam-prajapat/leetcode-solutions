int trap(int* heights, int size) {

    int leftPointer = 0;            // Start from the left end of the array
    int rightPointer = size - 1;    // Start from the right end

    int maxLeftHeight = 0;          // Tallest bar encountered so far from the left
    int maxRightHeight = 0;         // Tallest bar encountered so far from the right

    int totalWaterCollected = 0;    // Final result

    // Continue until the pointers meet
    while (leftPointer < rightPointer) {

        // Decide which pointer to move based on height
        if (heights[leftPointer] <= heights[rightPointer]) {

            // If we find a new tallest bar while moving from left, update it
            if (heights[leftPointer] >= maxLeftHeight) {
                maxLeftHeight = heights[leftPointer];
            }
            else {
                // Otherwise water can be trapped here
                totalWaterCollected += maxLeftHeight - heights[leftPointer];
            }

            leftPointer++;   // Move to next bar on the right
        }
        else {

            // If we find a new tallest bar while moving from right, update it
            if (heights[rightPointer] >= maxRightHeight) {
                maxRightHeight = heights[rightPointer];
            }
            else {
                // Otherwise water can be trapped here
                totalWaterCollected += maxRightHeight - heights[rightPointer];
            }

            rightPointer--;  // Move to next bar on the left
        }
    }

    return totalWaterCollected;
}
