/*
  compile: 
g++ mural.cpp -o mural.out
  run:
./mural.out < mural_cin.txt
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> sum(N+1);
    for (int i = 0; i < N; i++)
      sum[i+1] = sum[i] + (s[i] - '0');
    int l = (N+1)/2; // painted mural lenght (granted)
    int ret = 0;
    for (int i = 0; i < N-l+1; i++)
      ret = max(ret, sum[i+l] - sum[i]);
    cout << "Case #" << tc << ": " << ret << endl;
  }
  return 0;
}
