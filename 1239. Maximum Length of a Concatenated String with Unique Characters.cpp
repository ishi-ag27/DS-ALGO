class Solution {
public:
    int maxi = 0;
    int maxLength(vector<string>& arr) {
        dfs(0, arr, "");
        return maxi;
    }
    
    void dfs(int start, vector<string> &arr, string s){
        //add all string one by one and see what the largets unique can be made
        if(!isUnique(s)) return;
        maxi = max(maxi, (int)s.size());
        
        for(int i=start; i<arr.size();i++){
            string temp = arr[i];
            dfs(i+1, arr, s+temp);
        }
    }
    
    bool isUnique(string &str){
        unordered_set<char> s;
        for(auto ch: str){
            s.insert(ch);
        }
        
        return str.size() == s.size();
    }
};
