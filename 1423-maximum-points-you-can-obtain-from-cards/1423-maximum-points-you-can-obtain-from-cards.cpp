class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0;
        int maxSum = 0;
        int rightsum = 0;
        
        for(int i = 0 ;i < k;i++){
            leftsum += cardPoints[i];
        }
        maxSum = leftsum;

        int rightInd = cardPoints.size()-1;

        for(int i = k - 1 ; i >= 0 ;i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rightInd];
            rightInd -= 1;
            maxSum = max(maxSum , leftsum + rightsum);
        }

        return maxSum;
    }
};