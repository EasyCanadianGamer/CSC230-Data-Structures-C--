#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char c;
    int x;
    int sizeArr = 5;

    char arr[50];
    for (int i = 0; i < sizeArr; i++)
    {
        cin >> c;
        arr[i] = c;
    }

    cin >> x;

    for (int i = x - 1; i < sizeArr - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    sizeArr--;

    for (int i = 0; i < sizeArr; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}