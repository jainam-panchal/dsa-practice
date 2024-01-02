class Solution {
private:
    int findMaxi(vector<int>& piles) {
        int ans = piles[0];
        for(int i=0 ; i<piles.size() ; i++) {
            ans = max(ans, piles[i]);
        }
        return ans;
    }
    long long timeTaken(vector<int>& piles, int speed) {
        long long total = 0;
        for(int i = 0 ; i<piles.size() ; i++) {
            // we take ceil of the value;
            long long currTime = ceil((double)piles[i]/(double)speed);
            total += currTime;
        }
        
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = findMaxi(piles);
        int ans = -1;
        
        while(start <= end) {
            long long mid = start + (end - start)/2;
            long long guess = timeTaken(piles, mid);
            
            if(guess <= h) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};


// BRUTE FORCE SOLUTION - TLE ERROR

// class Solution {
// private:
    
//     // to calculate the time taken on any speed
//     long long timeTaken(vector<int>& piles, int speed) {
//         long long total = 0;
//         for(int i = 0 ; i<piles.size() ; i++) {
//             // we take ceil of the value;
//             long long currTime = ceil((double)piles[i]/(double)speed);
//             total += currTime;
//         }
        
//         return total;
//     }
    
//     // just to find the maximum limit
    // int findMaxi(vector<int>& piles) {
    //     int ans = piles[0];
    //     for(int i=0 ; i<piles.size() ; i++) {
    //         ans = max(ans, piles[i]);
    //     }
    //     return ans;
    // }

// public:
    
//     // basic idea is to start from 1 to maxSpeed, if we can eat all bananas
//     // less than H, we found the ans;
    
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int maxSpeed = findMaxi(piles);
        
//         for(int i=1 ; i<=maxSpeed ; i++) {
//             long long currTimeOnSpeed = timeTaken(piles, i);
//             if(currTimeOnSpeed <= h) {
//                 return i;
//             }
//         }
        
//         // dummy
//         return maxSpeed;
//     }
// };