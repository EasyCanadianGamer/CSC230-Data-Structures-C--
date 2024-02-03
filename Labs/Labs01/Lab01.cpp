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
            arr[i][j] = c;
        }
    }

        for( int i = 0; i<x; i++)
    {
        for( int j = 0;j<y;j++)
        {
           
            cout << arr[i][j] << " ";
        }
    }

    


    return 0;
}
