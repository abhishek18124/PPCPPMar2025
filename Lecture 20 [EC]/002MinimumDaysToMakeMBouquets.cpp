class Solution {
public:

    bool f(vector<int>& bloomDay, int m, int k, int timeLimit) { // time : O(n)

        // check if you can make 'm' bouquets of 'k' adjacent flowers
        // in the given 'timeLimit'

        int bouquetCnt = 0; // to track no. of bouquets of 'k' adj. flowers you've made
        int cnt = 0; // to track no. of bloomed adjacent flowers we've picked

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= timeLimit) {

                // ith flower has bloomed, pick it
                cnt++;
                if (cnt == k) {
                    // you've made a bouquet of k adjacent flowers
                    bouquetCnt++;
                    cnt = 0;
                }


            } else {

                // ith flower is not yet bloomed
                cnt = 0;

            }

        }

        return bouquetCnt >= m;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (s <= e) { // time : O(log(e-s).n) // e-s is the size of the search space

            int mid = s + (e - s) / 2;

            // can I make 'm' bouquets of 'k' adjacent flowers
            // in 'mid' no. of days ?

            if (f(bloomDay, m, k, mid)) {

                // you can make 'm' bouquets of 'k' adjacent
                // flowers in 'mid' no. of days

                ans = mid;
                e = mid - 1;

            } else {

                // you cannot make 'm' bouquets of 'k' adjacent
                // flowers in 'mid' no. of days

                s = mid + 1;

            }

        }

        return ans;
    }
};