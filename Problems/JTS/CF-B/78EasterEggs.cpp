#include <iostream>

using namespace std;

char color[] = {'R','O','Y','G','B','I','V'};
int eggs[110];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) eggs[i] = i % 7;
    if(eggs[n-1-2] == 0) eggs[n-1-2] = eggs[n-1-2-4];
    if(eggs[n-1-1] == 0 || eggs[n-1-1] == 1) eggs[n-1-1] = eggs[n-1-1-4];
    if(eggs[n-1] == 0 || eggs[n-1] == 1 || eggs[n-1] == 2) eggs[n-1] = eggs[n-1-4]; 
    for(int i = 0; i < n; i++) cout << color[eggs[i]];
    cout << endl;
}