#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    for (int x = 1; x <= 9; x++)
    {
        int n = pow(10, x);
        clock_t startTime = clock();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += i;
        }
        clock_t endTime = clock();
        // cout<<sum<<endl;
        cout << "10^" << x << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
    return 0;
}
