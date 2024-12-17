#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    cin >> a;

    const char *s = a.c_str();
    size_t len = a.length();

    bool carry = true;
    for (int i = 1; i < len; i++) {
        if (s[i-1] != s[i]) carry = false;
    }
    if (carry) {
        for (int i = 0; i < len; i++) {
            cout << len-i << " ";
        }
        return 0;
    }

    for (int i = 0; i < len; i++) {
        int count = 0;
        for (int j = i, c = 0; j < len; j++) {
            if (s[j] == s[c]) count++;
            else break;
            c++;
        }
        cout << count << " ";
    }
}