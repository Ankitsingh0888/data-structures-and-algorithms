class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string val=strs[i];
            sort(val.begin(),val.end());
            mp[val].push_back(strs[i]);
        }
        for (auto &[key, group] : mp) {
            ans.push_back(group);
        }
        return ans;

    }
};