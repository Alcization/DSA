#include <iostream>
#include <math.h>
using namespace std;

int jumpSearch(int arr[], int x, int n) 
{
    int i = 0;
    int jump = sqrt(n);
    while (i < n)
    {
        cout << i << " ";
        if (arr[i] > x) break;
        else if (arr[i] == x) return i;
        i += jump;
    }
    for (int j = i - jump + 1; j < i; j++)
    {
        cout << j << " ";
        if (arr[j] == x) return j;
    }
    return -1;
}


int main()
{   
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);

    if (index != -1) {
        cout << "\nNumber " << x << " is at index " << index;
    }
    else {
        cout << "\n" << x << " is not in array!";
    }
    return 0;
}

