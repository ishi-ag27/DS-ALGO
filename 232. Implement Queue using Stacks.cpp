//Beats 100% CPP users 


class MyQueue {
   stack<int> input;
   stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()==false)
        {
            int ans= output.top();
            output.pop();
            return ans;
        }
        else
        {
            while(input.empty()==false)
            {
                output.push(input.top());
                input.pop();
            }
            int ans= output.top();
            output.pop();
            return ans;
        }
        
    }
    
    int peek() {
        if(output.empty()==false)
        {
            int ans= output.top();
            return ans;
        }
         else
        {
            while(input.empty()==false)
            {
                output.push(input.top());
                input.pop();
            }
            int ans= output.top();
            return ans;
        }
    }
    
    bool empty() {
        if(output.empty()&& input.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
