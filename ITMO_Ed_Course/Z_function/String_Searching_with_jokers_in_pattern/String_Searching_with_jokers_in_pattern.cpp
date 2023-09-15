#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/C
// Поиск подстроки в строке с джокерами в образце (через наивный алгоритм) 

// Вход: 2 строки -> t - текст, p - паттерн (образец) [он может содержать джокеры - ?]
// '?' кодирует любой символ 
// Выход: найти все вхождения подстроки в строку (образца в текст) [вывести индексы начал]


int main()
{
    int q; // кол-во запросов 
    cin >> q;
    string t, p;
    for (int i = 0; i < q; ++i) {
        cin >> t >> p;
        if (p.size() > t.size()) {
            cout << 0 << endl;
            cout << endl;
        }
        else { // |p| <= |t|
            vector<int> rez;
            for (int j = 0; j <= t.size() - p.size(); ++j) {
                bool f = true;
                for (int k = 0; k < p.size(); ++k) {
                    if (p[k] == '?') continue;
                    if (p[k] != t[j + k]) { // несовпадение символов
                        f = false;
                        break;
                    }
                }
                if (f) {
                    rez.push_back(j);
                }
            }
            cout << rez.size() << endl;
            for (auto& elem : rez) {
                cout << elem << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}

