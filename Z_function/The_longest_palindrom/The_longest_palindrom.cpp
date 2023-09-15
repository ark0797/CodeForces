#include <iostream>
using namespace std;

// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/A
// найти длину самого длинного префикса строки s, что будет являться палиндромом 
// (реализация наивного решения) 

bool is_palindrom(const string& s) {
    int n = s.size();
    for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        string tmp = "";
        int mx = 0;
        for (int i = 0; i < s.size(); ++i) {
            tmp += s[i];
            if (is_palindrom(tmp)) {
                if (tmp.size() > mx) {
                    mx = tmp.size();
                }
            }
        }
        cout << mx << endl;
    }
    return 0;
}

