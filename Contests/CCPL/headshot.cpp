#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(void) {
    string temp;
    while(cin >> temp) {
        int next0 = 0;
        int next1 = 0;
    
        int numZs = 0;
        for(int i = 0; i < temp.size(); i++)
            if(temp[i] == '0') numZs++;
        for(int i = 0; i < temp.size() - 1; i++) {
            if(temp[i] == '0') {
                if(temp[i + 1] == '1') next1++;
                else next0++;
            }
        }
        if(temp[temp.size()-1] == '0') {
            if(temp[0] == '1') next1++;
            else next0++;
        }
        
        int probShoot = next0 * temp.size();
        int probRotat = numZs * numZs;

        if(probShoot == probRotat) cout << "EQUAL\n";
        else if(probShoot > probRotat) cout << "SHOOT\n";
        else cout << "ROTATE\n";
    }
    return 0;
}