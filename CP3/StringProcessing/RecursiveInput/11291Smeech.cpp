#include <iostream>
#include <cctype>
#include <string>
#include <cstdio>

using namespace std;

int nextC = 0;
string line;

void eraseB() {
    while(isblank(line[nextC])) nextC++;
}

double getReal() {
    string numb = "";
    while(nextC < line.size() && (isdigit(line[nextC]) || line[nextC] == '.' || line[nextC] == '-' )) {
        numb += line[nextC];
        nextC++;
    }
    return stod(numb);
}

double expression() {
    eraseB();
    if(isdigit(line[nextC]) || line[nextC] == '-') return getReal();
    else {
        double p, a, b;
        //remove '('
        nextC++;
        p = getReal();
        a = expression();
        b = expression();
        //remove ')'
        nextC++;
        return p * (a + b) + (1.0 - p) * (a - b);
    }
}

int main(void) {
    while(getline(cin, line)) {
        if(line == "()") break;
        nextC = 0;
        printf("%.2f\n", expression());
    }
}