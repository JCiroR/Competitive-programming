#include <bits/stdc++.h>
using namespace std;

const int N = 20010;
string day[N];
int curr = 0;

string getDay(int day) {
    switch(day) {
        case 0:
            return "Friday";
        case 1:
            return "Saturday";
        case 2:
            return "Sunday";
        case 3: 
            return "Monday";
        case 4:
            return "Tuesday";
        case 5:
            return "Wednesday";
        case 6:
            return "Thursday";
    }
}

bool leap(int year) {
    if((year % 400) == 0) return true;
    else if((year % 100) == 0) return false;
    else if((year % 4) == 0) return true;
    return false;
}

int main() {
    curr = 2;
    for(int i = 1867; i <= 1867 + 10010; i++) {
        day[i] = getDay(curr);
        curr++;
        curr %= 7;
        if(leap(i)) curr++;
        curr %= 7;
    }
    int n;
    cin >> n;
    cout << day[n + 1867] << endl;
}