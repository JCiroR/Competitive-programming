#include <iostream>
#include <vector>
#include <utility>
#include <cctype>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

vector<pair<double, double> > shifts;

char kb[31][31];
bool lower[50];
bool upper[50];

int eval(char s) {
    if(islower(s)) {
        if(lower[s - 'a']) return 0;
        else return -1;
    } else if(isupper(s)) {
        if(upper[s - 'A']) return 0;
        else if(lower[tolower(s) - 'a'] && !shifts.empty()) return 1;
        else return -1;
    } else return -1;
}

double distance(double x1, double y1, double x2, double y2) {
    x1 += 0.5; y1 += 0.5;
    x2 += 0.5; y2 += 0.5;
    return hypot(fabs(x1 - x2), fabs(y1 - y2));
}

int main() {
    memset(lower, false, sizeof lower);
    memset(upper, false, sizeof upper);
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> kb[i][j];
            if(kb[i][j] == 'S') shifts.push_back(make_pair((double)i , (double)j));
            else if(islower(kb[i][j])) lower[kb[i][j] - 'a'] = true;
        }
    double dis = x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char c = kb[i][j];
            if(c == 'S' || upper[toupper(c) - 'A']) continue;
            else {
                for(int k = 0; k < shifts.size(); k++)
                    if(distance(shifts[k].first, shifts[k].second, (double)i, (double)j) <= dis) {
                        upper[toupper(c) - 'A'] = true;
                        break;
                    }
            }
        }
    int q;
    string T;
    cin >> q;
    cin >> T;
    int extraH = 0;
    for(int i = 0; i < q; i++) {
        int cost = eval(T[i]);
        if(cost == -1) {
            extraH = -1;
            break;
        }
        extraH += cost;
    }
    cout << extraH << endl;
} 