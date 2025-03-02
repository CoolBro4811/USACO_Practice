#include <bits/stdc++.h>

using namespace std;

bool f(const string& t) {
    return t == "SQRT";
}

bool o(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int p(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 3;
    if (op == '+' || op == '-') return 2;
    return 0;
}

queue<string> sy(const string& s) {
    stack<string> ops;
    queue<string> out;
    string buf;

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (c == '-' && (i == 0 || s[i - 1] == '(' || o(s[i - 1]))) {
            if (s.substr(i + 1, 4) == "SQRT") {
                ops.push("NEG");
                i += 4; 
                ops.push("SQRT");
                continue;
            } else {
                buf += c;
                continue;
            }
        }

        if (isdigit(c) || c == '.') {
            buf += c;
        } else {
            if (!buf.empty()) {
                out.push(buf);
                buf.clear();
            }

            if (s.substr(i, 4) == "SQRT") {
                ops.push("SQRT");
                i += 3;
            } else if (o(c)) { // for exp
                while (!ops.empty() && o(ops.top()[0]) && 
                       (p(ops.top()[0]) > p(c) || (p(ops.top()[0]) == p(c) && c != '^'))) {
                    out.push(ops.top());
                    ops.pop();
                }
                ops.push(string(1, c));
            } else if (c == '(') {
                ops.push(string(1, c));
            } else if (c == ')') {
                while (!ops.empty() && ops.top() != "(") {
                    out.push(ops.top());
                    ops.pop();
                }
                if (ops.empty()) {
                    throw runtime_error("Mismatched ()");
                }
                ops.pop();
            } else if (c != ' ') {
                throw runtime_error("Bad char");
            }
        }
    }

    if (!buf.empty()) {
        out.push(buf);
    }

    while (!ops.empty()) {
        if (ops.top() == "(" || ops.top() == ")") {
            throw runtime_error("Mismatched ()");
        }
        out.push(ops.top());
        ops.pop();
    }

    return out;
}

long double e(queue<string>& q) {
    stack<long double> s;

    while (!q.empty()) {
        string t = q.front();
        q.pop();

        if (isdigit(t[0]) || (t.size() > 1 && t[0] == '-')) {
            s.push(stod(t));
        } else if (f(t)) {
            if (s.empty()) {
                throw runtime_error("Bad expr");
            }
            long double a = s.top(); s.pop();
            if (t == "SQRT") {
                if (a < 0) {
                    throw runtime_error("sqrt(-)");
                }
                s.push(sqrt(a));
            }
        } else if (t == "NEG") {
            if (s.empty()) {
                throw runtime_error("Bad expr");
            }
            long double a = s.top(); s.pop();
            s.push(-a);
        } else if (o(t[0])) {
            if (s.size() < 2) {
                throw runtime_error("Bad expr");
            }
            long double b = s.top(); s.pop();
            long double a = s.top(); s.pop();

            switch (t[0]) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': 
                    if (b == 0) throw runtime_error("/0");
                    s.push(a / b); 
                    break;
                case '^': s.push(pow(a, b)); break;
                default: throw runtime_error("Bad op");
            }
        } else {
            throw runtime_error("Bad token");
        }
    }

    if (s.size() != 1) {
        throw runtime_error("Bad expr");
    }

    return s.top();
}

void solve() {
    string s;
    getline(cin, s);
    string r = s.substr(s.find('=') + 1);
    s = s.substr(0, s.find('='));

    try {
        queue<string> q = sy(s);

        // queue<string> debugQ = q;
        // while (!debugQ.empty()) {
        //     cout << debugQ.front() << " ";
        //     debugQ.pop();
        // }
        // cout << endl;

        long double res = e(q);

        res = round(res * 1000.0) / 1000.0;

        stringstream ss;
        if (round(res) == res) {
            ss << static_cast<int>(res);
        } else {
            ss << fixed << setprecision(3) << res;
        }

        string formattedRes = ss.str();

        long double expected = stod(r);

        double epsilon = 1e-9;
        if (abs(res - expected) < epsilon) {
            cout << "Correct" << endl;
        } else {
            cout << formattedRes << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string l;
    getline(cin, l);
    int n = stoi(l);

    while (n--) solve();
}
