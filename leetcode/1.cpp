#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<vector<int>>> table(31);
        for(int i=0;i<candidates.size();i++) table[candidates[i]].push_back({candidates[i]});

        for(int i=2;i<=target;i++){
            for(int j=0;j<candidates.size();j++){
                int num=candidates[j];
                if(num>i/2) break;

                //combine num and table[i-num]
                for(int k=0;k<table[i-num].size();k++){
                    if(num>table[i-num][k].back()) continue;
                    table[i].push_back(table[i-num][k]);
                    table[i][table[i].size()-1].push_back(num);
                }
            }

            cout<<i<<":"<<endl;
            for(int k=0;k<table[i].size();k++){
                for(int t=0;t<table[i][k].size();t++){
                    cout<<table[i][k][t]<<" ";
                }
                cout<<endl;
            }

            cout<<endl;
        }


        return table[target]; 
    }
};

int main()
{
    Solution S;
    vector<int> nums={2,3,5};
    vector<vector<int>> ans;
    ans=S.combinationSum(nums, 8);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
