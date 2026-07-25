class Solution {
public:
    int maxProduct(int n) {
        vector<int>temp;
        int num = n;

        while(num>0)
        {
            temp.push_back(num%10);
            num/=10;
        }

        int maxPro = 0;

        for(int i = 0 ;i<temp.size();i++){
            for(int j = i+1;j<temp.size();j++){
                int pro = temp[i]*temp[j];

                maxPro = max(maxPro, pro);
            }
        }

        return maxPro;
    
        }
};