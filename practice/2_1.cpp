#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int even_sum = 0, odd_sum = 0;
        int new_even_sum = 0, new_odd_sum = 0;
        for (int j = 0; j < n; j++) 
        {
            if (j % 2 == 0) {
                even_sum += arr[j];
            } else {
                odd_sum += arr[j];
            }
        }

        for (int j = 0; j < n; j++) 
        {
            if (j != i) {
                if (j % 2 == 0) 
                {
                    if (j > i) 
                    {
                        new_odd_sum += arr[j];
                    } 
                    else 
                    {
                        new_even_sum += arr[j];
                    }
                } 
                else 
                {
                    if (j > i) 
                    {
                        new_even_sum += arr[j];
                    } 
                    else 
                    {
                        new_odd_sum += arr[j];
                    }
                }
            }
        }

        if (new_even_sum == new_odd_sum) {
            ans++;
        }
    }

    cout << "Output is: " << ans << endl;
    return 0;
}
