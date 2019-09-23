#include <iostream>
#include <algorithm>

using namespace std;

int arr[100010];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> n;
    sort(arr, arr + n);
    for(int i = 1; i < n - 1; i++) 
    {
        if(arr[i-1] + arr[i] > arr[i + 1])
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}