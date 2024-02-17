class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        std::priority_queue<int> pq;

        int i = 0;

        for (i = 0; i < n - 1; i++) {

            // we go down together
            if (heights[i] >= heights[i + 1]) {
                continue;
            }

            int diff = heights[i + 1] - heights[i];

            // if we have bricks, use it
            if (diff <= bricks) {
                pq.push(diff);
                bricks -= diff;
            }

            // can we look at the past and change the decision?
            else if (ladders > 0) {
                if (!pq.empty()) {
                    int maxUsedTillNow = pq.top();
                    // can we benefit?
                    if (diff < maxUsedTillNow) {
                        bricks += maxUsedTillNow;
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            // no choice. exit the game
            else {
                break;
            }
        }

        return i;
    }
};
