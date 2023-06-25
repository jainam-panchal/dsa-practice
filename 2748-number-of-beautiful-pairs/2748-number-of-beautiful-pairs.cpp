class Solution {
  public: bool coprime(int a, int b) {
    return (__gcd(a, b) == 1);
  }

  int countBeautifulPairs(vector < int > & arr) {
    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        int first = arr[i];
        while (first >= 10) first /= 10;
        int second = arr[j] % 10;
        if (coprime(first, second))
          count++;
      }
    }

    return count;
  }
};