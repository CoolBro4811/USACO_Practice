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

  vector<int> a(length, 0);

  int k = 1;

  for (int i = 0; i < length-2; i++) {
    if (b[i] == 1) {
      a[i] = k;
      a[i+2] = k;
      a[i+1] = k;
    }
    else {
      k++;
    }
  }

  // cout << "\n ";
  // for (auto &c : b) cout << c;
  // cout << " \n";

  // for (auto &c : a) cout << c;
  // cout << "\n";

// verify

  for (int i = 1; i < length-2; i++) {
    if (b[i] == 1) {
      if (a[i] != a[i+1] || a[i] != a[i+2]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  return;
}
