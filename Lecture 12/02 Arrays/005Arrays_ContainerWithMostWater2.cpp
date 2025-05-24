#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) { // time : O(n)
        int maxsofar = 0;
        int n = height.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int wij = j - i;
            int hij = min(height[i], height[j]);
            int aij = wij * hij;
            maxsofar = max(maxsofar, aij);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
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