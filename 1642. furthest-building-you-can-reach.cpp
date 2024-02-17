//Approach 1 : Recursion + Memoization
//However ,if array constraints too long,might give TLE .
class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(int idx,vector<int>&heights,int bricks,int ladders){
        //base case
        if(idx==n-1){
            return 0;
        }
        if(t[bricks][ladders]!=-1){
            return t[bricks][ladders];
        }
        
        if(heights[idx+1]<=heights[idx]){
            return t[bricks][ladders] =1+solve(idx+1,heights,bricks,ladders);
        }
        else{
            //we either need bricks or ladders
            int byBrick=0;
            int byLadder=0;

            if(bricks>=heights[idx+1]-heights[idx]){
                byBrick=1+solve(idx+1,heights,bricks-(heights[idx+1]-heights[idx]),ladders);
            }
            if(ladders >0){
                byLadder=1+solve(idx+1,heights,bricks,ladders-1);
            }
       return t[bricks][ladders]=max(byBrick,byLadder);
    }
    return -1;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n=heights.size();
        t=vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1));
        return solve(0,heights,bricks,ladders);


    }
};

//Approach 2 :Lazy Greedy
//TC O(NlogN) (logn push,pop etc of pq) SC O(N) (Ye toh priority queue banaya thats why)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int>pq; //max-heap

        int i=0;
        //i->i+1
        for(i=0;i<n-1;i++){
            if(heights[i+1]<=heights[i]){
                continue;
            }
            int diff=heights[i+1]-heights[i];
            if(bricks>=diff){
                bricks-=diff;
                pq.push(diff);
            }
            else if(ladders>0){
                if(!pq.empty()){
                    int max_past_bricks=pq.top();
                    if(max_past_bricks>diff){
                    bricks+=max_past_bricks;
                    pq.pop();
                    bricks-=diff;
                    pq.push(diff);
                }
            }
            ladders--;//either used in past or present
        }else{
            break;
        }

    }
    return i;
    }
};
