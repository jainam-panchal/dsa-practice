class Solution {
private:    
    int f(int i,vector<vector<int>> &arr, vector<int>&dp) {
        
        if(i == arr.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        // we start just after the index because it's sorted according to starting time
        int left = i + 1;
        // till the end
        int right = arr.size()-1;
        
        // just to store
        int guessedStart = arr.size();
        
        while(left <= right) {
            int mid = left + (right - left)/2;
            
            // if we can even schedule the new job or not?
            if(arr[mid][0] >= arr[i][1]) {
                
                // save and check if we can find more smaller
                guessedStart = mid;
                right = mid - 1;
            }
            // if not then look for larger
            else {
                left = mid + 1;
            }
        }
        
        // pick or notPick 
        
        // if we pick, start from the new index
        int pick = arr[i][2] + f(guessedStart, arr, dp);
        // if we don't pick, start from just the next index
        int notPick = f(i+1 , arr, dp);
        
        // typical memoization
        return dp[i] = max(pick, notPick);
        
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<int> dp(startTime.size() , -1);
        vector<vector<int>> arr;
        
        
        for(int i=0;i<startTime.size();i++){
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(arr.begin(), arr.end());
        return f(0, arr, dp);
    }
};