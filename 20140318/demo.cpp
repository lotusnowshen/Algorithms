#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> Q;

    Q.push(1);
    Q.push(3);

    cout << Q.front() << endl;
    Q.pop();
    return 0;


}
