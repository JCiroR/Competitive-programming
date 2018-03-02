#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

string keyWord;

ll IF();

ll ELSE() {
    ll ways = 1;
    while(cin >> keyWord) {
        if(keyWord == "S") continue;
        else if(keyWord == "IF") ways *= IF();
        else if(keyWord == "END_IF") break;
    }
    return ways;
}

ll IF() {
    ll ways = 1;
    while(cin >> keyWord) {
        if(keyWord == "S") continue;
        else if(keyWord == "IF") ways *= IF();
        else if(keyWord == "ELSE") {
            ways += ELSE();
            break;
        }
    }
    return ways;
}

ll countWays() {
   ll ways = 1;
    while(cin >> keyWord && keyWord != "ENDPROGRAM") {
        if(keyWord == "S") continue;
        else if(keyWord == "IF") {
            ways *= IF();
        }
    }
    return ways;
}

int main(void) {
    int n;
    cin >> n;
    while(n--) {        
        cout << countWays() << endl;
    }
}