/* 
   compile: g++ diwali_lightings.cpp -o diwali.out
   run:     ./diwali.out < diwali_cin.txt
   runtime error happened, maybe the main function can be improved to a cp standard later
*/


#include <bits/stdc++.h>
#include <cstring>

int light(std::string str, int a_, int b_){
  int len = str.length();
  int diff = (b_-a_)/len;
  int a = a_%len;
  int b = b_%len;
  
  int complete_cnt = 0, cnt = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == 'B') {
      complete_cnt++;
      if (a <= b) {
        if (i >= a && i <= b)
          cnt++;
      } else {
        if (i <= b || i >= a)
          cnt++;
      }
    }
  }
  return diff*complete_cnt + cnt;
}

int main(){
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::string s;
    int a,b;
    std::cin >> s >> a >> b;
    std::cout << "Case #" << i+1 << ": " << light(s,a-1,b-1) << std::endl;
  }
  return 0;
}
