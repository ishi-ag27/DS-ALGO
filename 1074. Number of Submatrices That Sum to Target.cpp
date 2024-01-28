class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // implement 2d sum query
        vector<vector<int>> sums(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        for (int i = 0; i < matrix.size(); ++i)
            for (int y = 0; y < matrix[0].size(); ++y)
                sums[i + 1][y + 1] = matrix[i][y] + sums[i + 1][y] + sums[i][y + 1] -
                    sums[i][y];
        // iterate thru upper and lower right corner possibilities
        int ans = 0;
        for (int i = 0; i < matrix.size(); ++i){
            for (int y = 0; y < matrix[0].size(); ++y){
                for (int x = 0; x + i < matrix.size(); ++x){
                    for (int z = 0; y + z < matrix[0].size(); ++z){
                        int s = 0;
                        // add current corner
                        s += sums[i + x + 1][y + z + 1];
                        // subtract rectangle above the current box
                        s -= sums[i][y + z + 1];
                        // subtract rectange on the left
                        s -= sums[i + x + 1][y];
                        // add rectangle on the left upper corner
                        s += sums[i][y];
                        ans += s == target;
                    }
                }
            }
        }
        return ans;
    }
};
