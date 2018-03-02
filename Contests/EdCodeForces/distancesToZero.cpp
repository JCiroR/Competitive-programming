#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    long n, temp;
    cin >> n;
    vector<int> distancias;
    distancias.reserve(n);
    while(n--) {
        cin >> temp;
        if(temp == 0) distancias.push_back(0);
        else distancias.push_back(-1);
    }
    for(int i = 0; i < distancias.size(); i++) {
        if(distancias[i] == 0) {
            for(int j = i - 1; j >= 0; j--) {
                if(distancias[j] == -1 || i - j < distancias[j]) distancias[j] = i - j;
                else break;
            }
            for(int j = i + 1; j < distancias.size(); j++) {
                if(distancias[j] == -1 || j - i < distancias[j]) distancias[j] = j - i;
                else break;
            }
        }
    }

    for(int i = 0; i < distancias.size(); i++) {
        cout << distancias[i];
        if(i != distancias.size() - 1) cout << " ";
    }
    cout << "\n";
    return 0;
}