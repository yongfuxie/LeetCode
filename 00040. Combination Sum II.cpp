
//Accepted	92 ms	cpp
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> tmp;
        S.clear();
        sort(num.begin(),num.end());
        memset(vis,false,sizeof(vis));
        dfs(ans,num,tmp,0,0,0,target);
        return ans;
    }
    void dfs(vector<vector<int> >& ans,vector<int>& num,vector<int>& tmp,int star,int step,int sum,int target)
    {
        if(sum == target)
        {
            if(!S.count(tmp))
            {
                ans.push_back(tmp);
                S.insert(tmp);
            }
            return ;
        }
        for(int i=star;i<(int)num.size();i++)
        {
            if(!vis[i] && sum+num[i] <= target)
            {
                vis[i] = true;
                tmp.push_back(num[i]);
                dfs(ans,num,tmp,i+1,step+1,sum+num[i],target);
//                if(i+1 < (int)num.size() && num[i] == num[i+1] ) i++;
                vis[i] = false;
                tmp.erase(--tmp.end());
            }
            else return ;
        }
    }
private:
    bool vis[10240];
    set<vector<int> > S;
};

