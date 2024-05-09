class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s,int count,int n){
        if(count==n/2){
            s.pop();
            return;
        }
        int num=s.top();
        s.pop();
        
        //recursive call
        solve(s,count+1,n);
        
        s.push(num);
        
        
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count=0;
        solve(s,count,sizeOfStack);
    }
