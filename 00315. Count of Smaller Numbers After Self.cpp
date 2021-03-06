/*
[Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)



题目大意：给一个整形数组`nums`，你需要返回一个新的数组`counts`： 其中`counts[i]` 表示位于元素`nums[i]`右侧小于`nums[i]`值的个数

解题思路：倒序遍历构造顺序数组 + 二分查找。 手撸二分查找也是可以的，时间复杂度为`NlogN`。STL 中有`lower_bound`直接水过去即可。

*/


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0),tmp;
        
        int n = (int)nums.size();
        
        for(int i=n-1;i>-1;i--){
            auto iter = lower_bound(tmp.begin(), tmp.end(), nums[i]);
            ans[i] = iter - tmp.begin();
            tmp.insert(iter, nums[i]);
        }
        
        return ans;
    }
};


