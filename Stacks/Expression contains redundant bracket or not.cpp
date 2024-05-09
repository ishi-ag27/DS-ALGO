class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            
            if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' ){
                st.push(ch);
            }
            else{
                bool isRedundant=true;
                
                if(ch==')'){
                    while(st.top()!='('){
                        char top=st.top();
                        if(top=='+'|| top=='-'||top=='*' ||top=='/'){
                            isRedundant=false;
                        }
                    st.pop();
                    }
                
                if(isRedundant==true){
                    return true;
                }
                st.pop();  //opening bracket ko pop kia jo closing bracket ke corresponding tha
            }
            }
            
        }
        return false;
    }
};
