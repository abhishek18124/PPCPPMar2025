#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) { // time : O(n^2)
        int maxsofar = 0;
        int n = height.size();
        for (int i = 0; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                int wij = j - i;
                int hij = min(height[i], height[j]);
                int aij = wij * hij;
                maxsofar = max(maxsofar, aij);
            }
        }
        return maxsofar;
    }
};

int main() {

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(height) << endl;

}