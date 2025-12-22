class Solution {
public:
    TreeNode* solve(vector<int>preorder,vector<int>inorder,int start,int end,int& idx){

        if(start>end)return NULL;

        int rootval=preorder[idx];
        int i=start;

        for(;i<=end;i++){
            if(inorder[i]==rootval){
                break;
            }
        }

        idx++;

        TreeNode* root=new TreeNode(rootval);
        root->left=solve(preorder,inorder,start,i-1,idx);

        root->right=solve(preorder,inorder,i+1,end,idx);

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int idx=0;
        return solve(preorder,inorder,0,n-1,idx);
    }
};