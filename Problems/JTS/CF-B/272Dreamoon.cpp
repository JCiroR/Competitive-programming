#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

string sent, received;
int correct = -1;
double favorable = 0;
vector<int> options;

void findCorrect() {
    int pos = 0;
    for(int i = 0; i < sent.size(); i++) {
        if(sent[i] == '+') pos++;
        else if(sent[i] == '-') pos--;
    }
    correct = pos;
}

void check(int index, int currPos) {
    for(int i = index; i < received.size(); i++) {
        if(received[i] == '+') currPos++;
        else if(received[i] == '-') currPos--;
        else if(received[i] == '?') {
            check(i + 1, currPos - 1);
            check(i + 1, currPos + 1);
            return;
        }
    }
    if(currPos == correct) favorable += 1;
    options.push_back(currPos);
}

int main() {
    cin >> sent;
    cin >> received;
    findCorrect();
    check(0, 0);
    double ans = favorable / ((double)options.size());
    printf("%.12f\n", ans);
}
