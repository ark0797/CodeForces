#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/B
// Префиксный и суффиксные подстроки - 1 (реализация наивного решения)

// По заданной строке s определить число подстрок, что сопадают либо только с префиксом,
// либо только с суффиксом (одновременное совпадение не учитываем) 
// [для одинаковых подстрок число тоже увеличиваем]


// получение всех подстрок строки 
vector<string> get_all_substrings(const string& s) {
    int n = s.size();
    vector<string> rez;
    string tmp;
    for (int i = 0; i < n; ++i) {
        tmp = s[i];
        rez.push_back(tmp); // подстрока из одного символа 
        for (int j = i + 1; j < n; ++j) {
            tmp += s[j];
            rez.push_back(tmp);
        }
    }
    return rez;
}

// получение всех префиксов строки 
vector<string> get_all_prefix(const string& s) {
    int n = s.size();
    vector<string> rez;
    string tmp = "";
    for (int i = 0; i < n; ++i) {
        tmp += s[i];
        rez.push_back(tmp);
    }
    return rez;
}

// получение всех суффиксов строки 
vector<string> get_all_suffix(const string& s) {
    int n = s.size();
    vector<string> rez;
    string tmp = "";
    for (int i = n-1; i >= 0; --i) {
        tmp = s[i] + tmp;
        rez.push_back(tmp);
    }
    return rez;
}


int main()
{
    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        // сначала найдем все подстроки строки s (сохраним их в множестве)
        vector<string> substrs = get_all_substrings(s);
        // затем найдем все префиксы строки s
        vector<string> pref= get_all_prefix(s);
        // после находим все суфиксы строки s
        vector<string> suff = get_all_suffix(s);
        int rez = 0;
        for (auto& elem : substrs) {
            if (find(pref.begin(), pref.end(), elem) == pref.end() &&
                find(suff.begin(), suff.end(), elem) != suff.end()) {
                rez++;
            }
            else if (find(pref.begin(), pref.end(), elem) != pref.end() &&
                find(suff.begin(), suff.end(), elem) == suff.end()) {
                rez++;
            }
        }
        cout << rez << endl;
    }
    return 0;
}

