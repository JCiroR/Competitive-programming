#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    int n, B, SG, SB, temp;
    cin >> n;
    while(n--) {
        cin >> B >> SG >> SB;
        multiset<int> greenSoldiers, blueSoldiers;
        while(SG--) {
            cin >> temp;
            greenSoldiers.insert(temp);
        }
        while(SB--) {
            cin >> temp;
            blueSoldiers.insert(temp);
        }
        
        while(!greenSoldiers.empty() && !blueSoldiers.empty()) {
            vector<int> blueSurvivors, greenSurvivors;
            for(int i = 0; i < B; i++) {
                if(greenSoldiers.empty() || blueSoldiers.empty()) break;
                auto greenAux = greenSoldiers.end(), blueAux = blueSoldiers.end(); greenAux--; blueAux--;
                int blue = *blueAux;
                int green = *greenAux;
                greenSoldiers.erase(greenAux);
                blueSoldiers.erase(blueAux);
                
                if(blue > green) blueSurvivors.push_back(blue - green);
                else if (green > blue) greenSurvivors.push_back(green - blue);
            }
            for(auto i : greenSurvivors) greenSoldiers.insert(i);
	        for(auto i : blueSurvivors) blueSoldiers.insert(i);
        }
        
        multiset<int> winner;
        if(greenSoldiers.empty() && blueSoldiers.empty())
            cout << "green and blue died\n";
        else if (greenSoldiers.empty()) {
            cout << "blue wins\n";
            winner = blueSoldiers;
        } else {
            cout << "green wins\n";
            winner = greenSoldiers;
        }
        for(multiset<int>::reverse_iterator rit = winner.rbegin(); rit != winner.rend(); ++rit)
            cout << *rit << "\n";
        if(n != 0) cout << "\n";
    }
    return 0;
} 