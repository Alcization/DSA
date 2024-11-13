#include <iostream>
#include <algorithm>
using namespace std;

struct sort_pred
{
    bool operator () (const pair<int, int>& left, const pair<int, int>& right)
    {
        return (left.first > right.first);
    }
};

void sortByFrequency(int arr[], int n)
{
    pair<int, int> p[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {   
        bool found = false;
        if (count == 0)
        {
            p[0].second = arr[i];
            p[0].first = 1;
            count++;
            continue;
        }
        for (int j = 0; j < count; j++)
        {
            if (p[j].second == arr[i])
            {
                p[j].first++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            p[count].second = arr[i];
            p[count].first = 1;
            count++;
        } 
    }
    stable_sort(p, p + count, sort_pred());
    int index = 0;
    for (int j = 0; j < count; j++) 
    {
        for (int i = 0; i < p[j].first; i++)
        {
            arr[index] = p[j].second;
            index++;
        }
    }
}

int main()
{
    int arr[] = {-4, 1, 2, 2, -4, 9, 1, -1};
	int n = sizeof(arr) / sizeof(arr[0]);
	sortByFrequency(arr, n);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "-4 -4 1 1 2 2 9 -1";
    return 0;
}