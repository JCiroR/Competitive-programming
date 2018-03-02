#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
    int tests;
    string current;
    string lastPrint;
    cin >> tests;
    while(tests--) {
        cin >> current;
        if(current == "1" || current == "4" || current == "78") cout << "+\n";
        else if(current.find("35") == current.size() - 2) cout << "-\n"; 
        else if(current.find("9") == 0 && current.rfind("4") == current.size() - 1) cout << "*\n";
        else if(current.find("190") == 0)  cout << "?\n";
        else cout << "+\n";
    }
       return 0;
}