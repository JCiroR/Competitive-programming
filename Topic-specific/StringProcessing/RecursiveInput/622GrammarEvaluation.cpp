#include <string>
#include <iostream>
#include <cctype>

using namespace std;

/*
< expression > := < component > | < component > + < expression >
< component > := < factor > | < factor > * < component >
< factor > := < positiveinteger > | (< expression >)
*/

string line;
int nextChar = 0;
int open = 0;

// ._.
int expression();
int component();
int factor();
int getNumber();


int getNumber() {
    string number = ""; 
    while(nextChar < line.size() && isdigit(line[nextChar])) {
        number += line[nextChar];
        nextChar++;
    }
    if(number.empty()) return -1;
    else return stoi(number);
}

int factor() {
    if(nextChar >= line.size()) return -1;
    else if(isdigit(line[nextChar])) return getNumber();
    else if(line[nextChar] == '(') {
        nextChar++;
        open++;
        int answ = expression();
        open--;
        if(nextChar >= line.size() || line[nextChar] != ')') return -1;
        nextChar++;
        return answ;
    } else return -1;
}

int component() {
    int answ = factor();
    if(answ == -1 || nextChar >= line.size() || line[nextChar] != '*') return answ;
    else {
        nextChar++;
        int next_comp = component();
        if(next_comp == -1) return -1;
        else return answ *= next_comp;
        return answ;
    }
}

int expression() {
    int answ = component();
    if(answ == -1 || nextChar >= line.size() || line[nextChar] == ')' && open > 0) {
        return answ;
        
    }
    else if(line[nextChar] == '+') {
        nextChar++;
        int next_exp = expression();
        if(next_exp == -1) return -1;
        return answ += next_exp;
    } else return -1;
}

int main(void) {
    int n;
    cin >> n;
    string trash;
    getline(cin, trash);
    while(n--) {
        nextChar = 0; line.clear();
        getline(cin, line);
        int value = expression();
        if(value == -1) cout << "ERROR\n";
        else cout << value << endl;
    }
    return 0;
}