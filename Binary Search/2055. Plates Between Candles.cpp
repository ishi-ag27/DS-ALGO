#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Approach 1: Prefix Sum & Binary Search

Intuition:
Idea here is to pre-compute and store the count of | (candles) & * (plates) for every index from i = 0 to current.

Now, we process each query. Since we need the closest candle from start towards right and the closest candle from end towards left.

Ex:
  start                         end
    *    *    |    *    |    *   |
    
-> Closest `|` from start is at (start + 2)
-> Closest `|` from end is at end itself

As we have pre-computed count of candles | and plates *, we can easily search the index of the next plate to the left and right from the current index.

Since the count is monotonically increasing, we can perform binary search.

Ex: s = `**|*|*|`, here count = [ (0, 1), (0, 2), (1, 2), (1,3), (2, 3), (2,4), (3, 4)]

-> say start = 1, end = 6
-> next candle from start is at i = 2 -> count[2] = (1,2).
-> Clearly we can see the count of candles at i = 2 is one greater than at i = start i.e 0

Similarly, we can do for end, just in the backward direction.
And with the count of candles one lesser than the value at current i.e end.

Thus, if we have a candle at start/end, no need to search.
Else, we search for the closest candle using binary search,
with the count of candles one greater than current, for start
with the count of candles one lesser than current, for end
lower_bound in case of start
upper_bound in case of end

Let's do a dry run on a test case:

Ex: s = "* * | * * | * * * |", query = [[2,5], [5,9]]

index     :   0  1  2  3  4  5  6  7  8  9
s         :   '*  *  |  *  *  |  *  *  |  *'

candles   :   0  0  1  1  1  2  2  2  3  3
plates    :   1  2  2  3  4  4  5  6  6  7

0. query[0] : [2, 5]
   => start = 2, next candle at i = 2
   => end = 5, prev candle at i = 5
   Thus, count of plates from start to end = plates[5] - plates[2] = 2

1. query[1] : [5, 9]
   => start = 5, next candle at i = 5
   => end = 9, prev candle at i = 8
   Thus, count of plates from start to end = plates[8] - plates[5] = 2

Code:

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = s.size();

    // Here count[i][0] -> count of candles from 0 -> i
    // and count[i][1] -> count of plates from 0 -> i
    vector<vector<int>> count(n, vector<int>(2));

    count[0] = s[0] == '*' ? vector<int>{0, 1} : vector<int>{1, 0};
    for(int i=1; i<n; i++) {
        count[i] = s[i] == '*' ? vector<int>{count[i-1][0], count[i-1][1] + 1} : vector<int>{count[i-1][0] + 1, count[i-1][1]};
    }

    vector<int> res;

    for(auto& query : queries) {
        int lo = query[0];
        int hi = query[1];

        if(s[lo] == '*') {
            lo = lower_bound(count.begin() + lo, count.begin() + hi, vector<int>{count[lo][0]+1, -1}) - count.begin();
        }

        if(s[hi] == '*') {
            hi = upper_bound(count.begin() + lo, count.begin() + hi - 1, vector<int>{count[hi][0], -1}) - count.begin();
        }

        res.push_back(count[hi][1] - count[lo][1]);
    }

    return res;
}

Complexity:

Time: O(N + Q * log N), N: size of string s, Q: number of queries
Space: O(N), size of count vector

This approach is good, but we can do much better.
*/

int main() {
    // Example usage
    string s = "* * | * * | * * * |";
    vector<vector<int>> queries = {{2, 5}, {5, 9}};

    // Get the result using the platesBetweenCandles function
    vector<int> result = platesBetweenCandles(s, queries);

    // Display the result
    cout << "Result: ";
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
