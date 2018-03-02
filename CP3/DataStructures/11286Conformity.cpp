#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n, max, affected = 0;
    string maxKey = "", currCourse, currKey;

    while(cin >> n) {
        if(n == 0) break;
        max = 0;
        maxKey = "";
        map<string, int> schedules;
        while(n--) {
            int temp;
            vector<string> machete;
            currKey = "";
            
            //Machete
            for(int i = 0; i < 5; i++) {
                cin >> currCourse;
                machete.push_back(currCourse);
            }
            sort(machete.begin(), machete.end());
            for(int i = 0; i < 5; i ++) currKey += machete[i];
            // Fin del machete

            if(schedules.count(currKey) > 0) {
                schedules[currKey]++;
                temp = schedules[currKey];
            } else temp = schedules[currKey] = 1;
            

            if(temp > max) {
                    max = temp;
                    maxKey = currKey;
                    affected = max;
            } else if (temp == max) affected += temp;
            
        }
        cout << affected << "\n";
    }
    return 0;
}
