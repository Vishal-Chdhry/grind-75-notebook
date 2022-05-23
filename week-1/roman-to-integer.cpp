class Solution {
 public:
  int val(char c) {
    if (c == 'I')
      return 1;
    else if (c == 'V')
      return 5;
    else if (c == 'X')
      return 10;
    else if (c == 'L')
      return 50;
    else if (c == 'C')
      return 100;
    else if (c == 'D')
      return 500;
    else if (c == 'M')
      return 1000;
    else
      return -1;
  }
  int romanToInt(string s) {
    int sub = 0, total = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i + 1 < s.size() && val(s[i]) < val(s[i + 1])) {
        sub += val(s[i]);
      } else if (i + 1 < s.size() && sub != 0 && val(s[i]) >= val(s[i + 1])) {
        cout << sub << ' ' << s[i] << endl;
        total += val(s[i]);
        total -= sub;
        sub = 0;
      } else {
        total += val(s[i]);
      }
    }
    if (sub != 0) {
      total -= sub;
    }
    return total;
  }
};