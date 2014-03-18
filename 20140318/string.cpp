#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    int a[10] = {1, 4, 3, 5, 0, -1};
    sort(a, a+6);

    for(int ix=0; ix!= 6; ++ix)
    {
        cout << a[ix] << " ";
    }

    cout << endl;

    return 0;
}
