/*
  compile: g++ number_guessing.cpp -o number_guessing.out
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  string s;
  for (int tc = 1; tc <= T; tc++) {
    long long A, B;
    int N;
    cin >> A >> B >> N;
    A++;

    while (A <= B) {
      long long num = A + (B-A)/2;
      cout << num << endl;
      cin >> s;
      if (s == "CORRECT")
        break;
      if (s == "TOO_BIG")
        B = num - 1;
      else
        A = num + 1;
    }
  }
  return 0;
}
