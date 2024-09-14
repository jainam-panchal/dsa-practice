class Solution {
    public int longestPalindrome(String s) {
        
        int n = s.length();
        Boolean isOddPresent = false;
        HashMap<Character, Integer> mp = new HashMap<Character,Integer>();
        
        for(int i=0 ; i<n ; i++) {
            int count = mp.getOrDefault(s.charAt(i) , 0);
            count++;
            mp.put(s.charAt(i) , count);
        }
        
        int ans = 0;
        
        for(Map.Entry<Character , Integer> entry : mp.entrySet()) {
            
            // if it's even
            if(entry.getValue() % 2 == 0) {
                ans += entry.getValue();
            }
            else {
                isOddPresent = true;
                ans += entry.getValue() - 1;
            }
        }
        
        return isOddPresent ?  ans + 1 :  ans;
    }
}