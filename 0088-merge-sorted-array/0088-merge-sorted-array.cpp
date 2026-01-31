class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i =0 ;
        int j =0;
        vector<int> unionArr;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                unionArr.push_back(nums1[i]);
                i++;
            }else{
                unionArr.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            unionArr.push_back(nums1[i++]);
        }
        while(j<n){
            unionArr.push_back(nums2[j++]);
        }
        for(int i =0 ;i< unionArr.size();i++){
            nums1[i]=unionArr[i];
        }

        
    }
};