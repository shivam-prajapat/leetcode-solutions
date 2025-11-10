class Solution {
public:
    void merge(vector<int>& nums1, int sizeA, vector<int>& nums2, int sizeB) {

        // We start filling nums1 from the END (right side).
        int writeIndex = sizeA + sizeB - 1;  // where next number goes
        int pointerA   = sizeA - 1;          // last valid element in nums1
        int pointerB   = sizeB - 1;          // last element in nums2

        // Compare from the back and place the biggest value at writeIndex
        while (pointerA >= 0 && pointerB >= 0) {

            if (nums1[pointerA] > nums2[pointerB]) {
                nums1[writeIndex] = nums1[pointerA];
                pointerA--;
            } else {
                nums1[writeIndex] = nums2[pointerB];
                pointerB--;
            }

            writeIndex--;  // move left in nums1
        }

        // If nums2 still has elements left, put them in nums1
        while (pointerB >= 0) {
            nums1[writeIndex] = nums2[pointerB];
            pointerB--;
            writeIndex--;
        }
    }
};
