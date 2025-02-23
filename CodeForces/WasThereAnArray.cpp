#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
  uint16_t n;
  cin >> n;

  for (int _ = 0; _ < n; _++) {
    getOutput();
  }
  return 0;
}

void getOutput() {
  uint32_t length;
  cin >> length;

  vector<int> b(length-2);

  for (int i = 0; i < length-2; i++) {
    int val;
    cin >> val;
    b[i] = val;
  }

  vector<int> a(length, 1);

  for (int i = 1; i < length-1; i++) {
    if (b[i-1] == 1) {
      a[i] = a[i-1];
      a[i+1] = a[i-1];
      i++;
    }
    else {
      a[i] = (a[i-1] == 1) ? 2 : 1;
    }
  }

  cout << "\n ";
  for (auto &c : b) cout << c;
  cout << " \n";

  for (auto &c : a) cout << c;
  cout << "\n";

// verify

  for (int i = 1; i < length-1; i++) {
    bool actual = (a[i] == a[i-1] && a[i] == a[i+1]);
    if (b[i-1] == 1 && !actual || b[i-1] == 0 && actual) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
  return;
}
