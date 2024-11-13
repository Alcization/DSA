#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> onTheSand(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    queue<pair<int, int>> my_queue;
    queue<pair<int, int>> new_queue;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0) my_queue.push(make_pair(i, j));
            if (matrix[i][j] == 1) matrix[i][j] = -1;
        }
    }
    int count = 1;
    while (true)
    {
        int i = my_queue.front().first;
        int j = my_queue.front().second;
        my_queue.pop();
        if ((i+1) < n && matrix[i+1][j] == -1) 
        {
            matrix[i+1][j] = count;
            new_queue.push(make_pair(i+1, j));
        }
        if ((i-1) >= 0 && matrix[i-1][j] == -1) 
        {
            matrix[i-1][j] = count;
            new_queue.push(make_pair(i-1, j));
        }
        if ((j+1) < m && matrix[i][j+1] == -1) 
        {
            matrix[i][j+1] = count;
            new_queue.push(make_pair(i, j+1));
        }
        if ((j-1) >= 0 && matrix[i][j-1] == -1) 
        {
            matrix[i][j-1] = count;
            new_queue.push(make_pair(i, j-1));
        }
        if (my_queue.size() == 0)
        {
            if (new_queue.size() == 0) break;
            else 
            {
                while (new_queue.size())
                {
                    my_queue.push(new_queue.front());
                    new_queue.pop();
                }
                count++;
            }
        }
    }
    return matrix;
}

int main()
{
    vector<vector<int>> matrix {
	{1, 1, 1},
	{1, 1, 1},
	{0, 1, 0}
    };
    int n = matrix.size();
    int m = matrix[0].size();
    auto res = onTheSand(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}