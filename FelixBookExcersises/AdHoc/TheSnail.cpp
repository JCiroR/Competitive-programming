#include <iostream>

using namespace std;

int main(void) {

    float height , U, distanceThatSlides,  fatigueFactor, fatiguePerDay, shift;
    int currentDay;

    while(cin >> height >> U >> distanceThatSlides >> fatigueFactor) {
        if(height == 0) break;
        fatiguePerDay = U * (fatigueFactor / 100);
        currentDay = 1;
        shift = 0.0;

        while(true) {
            shift += U;             
            if(shift > height) {
                cout << "success on day " << currentDay << endl;
                break;
            }
            shift -= distanceThatSlides;        
            if(shift < 0) {
                cout << "failure on day " << currentDay << endl;
                break;
            }
            currentDay++;       
            if(U - fatiguePerDay <= 0) U = 0;
            else  U -= fatiguePerDay;   
        }
    }
    return 0;
}
