class Solution {
public:
    string firstPalindrome(vector<string>& words){
        int i,j;
        int f=0;
        for(i=0;i<words.size();i++)
        {   
            f=0;
            for(j=0;words[i][j]!='\0';j++)
            {  
                if(words[i][j]!=words[i][words[i].size()-1-j])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                return words[i];
            }
        }
       return ""; 
    }
};
