#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int cnt = 0, level = 0;
    for (const auto& c:s){
        if (c == 'D')
            level--;
        else if (c == 'U'){
            level++;
            /* a valley (...) ends up at sea level */
            if (level == 0) 
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
