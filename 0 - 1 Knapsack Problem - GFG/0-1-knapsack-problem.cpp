//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


int dp[1002][1002] = {-1};
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int fun(int w, int wt[], int val[], int n, vector<vector<int>> &t){
        // BASE CONDITION
       if(n <= 0 || w <= 0) {
           return 0;
       }
       
       if(t[n][w] != -1) {
           return t[n][w];
       }
       else {
            // CHOICE DIAGRAM
           if(wt[n-1] > w) {
                // do not select it
                t[n][w] = fun(w, wt, val, n-1,t);
                return t[n][w];
           }
           
           if(wt[n-1] <= w) {
                // select it or don't
                t[n][w] = max(
                        (val[n-1] + fun(w-wt[n-1] , wt , val , n-1,t)),
                        fun(w,wt,val,n-1,t)
                    );
                return t[n][w];
           }
       }
    }
    
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int> > t(n+1, vector<int>(w+1, -1));
        return fun(w, wt, val, n, t);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends