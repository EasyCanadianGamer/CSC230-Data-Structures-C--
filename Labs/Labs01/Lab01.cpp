#include <iostream>

using namespace std;

int main()
{
    int x, y;
    char c;
    cin >> x;
    cin >> y;

    char arr[x][y];

    for( int i = 0; i<x; i++)
    {
        for( int j = i;j<y;j++)
        {
            cin >> c;
            arr[x][y] = c;
        }
    }

        for( int i = 0; i<x; i++)
    {
        for( int j = 0;j<y;j++)
        {
           
            cout << arr[x][y] << " ";
        }
    }

    


    return 0;
}