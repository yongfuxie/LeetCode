
//Accepted	4 ms	cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        vector <string> nums;
        if(root){
            dfs(root,"0",nums);
        }
        
        for_each(nums.begin(),nums.end(),[&](const string str){
            ans += atoi(str.c_str());
        });
        
        return ans;
        
    }
    
    void dfs(TreeNode* root,string str,vector<string>& nums){
        
        if(!root->left && !root->right){
            nums.push_back(string(str + ( to_string(root->val) )));
            return ;
        }
        
        if(root->left){
            dfs(root->left,str + ( to_string(root->val) ),nums);
        }
        
        if(root->right){
            dfs(root->right,str + ( to_string(root->val) ),nums);
        }
    }
};
