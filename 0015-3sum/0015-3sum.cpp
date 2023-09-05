class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        // Optimal Solution
        // O(NlogN)+O(N2), where N = size of the array.
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;

        for(int i=0 ; i<arr.size() ; i++) {
            if(i != 0 && arr[i-1] == arr[i]) continue;
            int j = i+1;
            int k = n-1;

            while(j<k) {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {arr[i] , arr[j] , arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    // skipping duplicates
                    while(j<k && arr[j] == arr[j-1]) j++;
                    while(j<k && arr[k] == arr[k+1]) k--;

                }
            }
        }

        return ans;
    }
};


	// BRUTEFORCE
	// set<vector<int>> st;
	// for(int i=0 ; i<arr.size() ; i++) {
	// 	for(int j=i+1 ; j<arr.size() ; j++) {
	// 		for(int k=j+1 ; k<arr.size() ; k++) {

	// 			if(arr[i] + arr[j] + arr[k] == target) {
	// 				vector<int> temp = {arr[i], arr[j] , arr[k]};
	// 				sort(temp.begin(), temp.end());
	// 				st.insert(temp);
	// 			}

	// 		}
	// 	}
	// }

	// vector<vector<int>> ans(st.begin(),st.end());
	// return ans;





	// BETTER
	// trick: arr[i] + arr[j] + arr[k] = k
	// 		  then arr[k] = k - arr[i] - arr[j]
	// 		  to find such arr[k], we use set
	
	// set<vector<int>> tuples;
	// for(int i=0 ; i<n ; i++) {
		
	// 	set<int> st;
	// 	for(int j=i+1 ; j<n ; j++) {
	// 		int k = target-arr[i]-arr[j];
	// 		if( st.find(target-arr[i]-arr[j]) != st.end() ) {
	// 			vector<int> temp = {arr[i] , arr[j] , k};
	// 			sort(temp.begin(), temp.end());
	// 			tuples.insert(temp);
	// 		}
	// 		st.insert(arr[j]);
	// 	}

	// }

	// vector<vector<int>> ans(tuples.begin(), tuples.end());
	// return ans;	
