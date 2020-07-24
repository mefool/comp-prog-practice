#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 * Kinda disgusting, edge cases are dumb or maybe it's just me.
 */
string timeConversion(string s) {
    s.pop_back();
    if (s[s.size()-1] == 'P' && !(s[0] == '1' && s[1] == '2')){
        int tens = 1;
        int hour = 2;
        if (s[1] > '8'){
            tens++;
            hour -= 10;
        }
        s[0] += tens;
        s[1] += hour;
    } else if(s[s.size()-1] == 'A')
        if (s[0] == '1' && s[1] == '2'){
            s[0] = '0';
            s[1] = '0';
        }
    
    s.pop_back();
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
