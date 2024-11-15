#include <iostream>
using namespace std;

const int MAX_N = 100;
int dp[MAX_N + 1][MAX_N + 1];
int tower1[MAX_N], tower2[MAX_N]; 

int LCS(int N1, int N2) {
  for (int i = 0; i <= N1; i++) {
    for (int j = 0; j <= N2; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0; 
      else if (tower1[i - 1] == tower2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1]; 
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
    }
  }
  return dp[N1][N2];
}

int main() {
  int N1, N2, caseNumber = 1;
  while (true) {
    cin >> N1 >> N2;
    if (N1 == 0 && N2 == 0) break;
    for (int i = 0; i < N1; i++) cin >> tower1[i];
    for (int i = 0; i < N2; i++) cin >> tower2[i];
    int result = LCS(N1, N2);
    cout << "Twin Towers #" << caseNumber << endl;
    cout << "Number of Tiles : " << result << endl;
    cout << endl;
    caseNumber++;
  }
  return 0;
}
