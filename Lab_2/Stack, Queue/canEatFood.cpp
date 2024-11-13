#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;
        dir = 0;
    }
};



bool canEatFood(int maze[5][5], int fx, int fy)
{
    bool visited[5][5] = {
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };
	int i = 0, j = 0;
	stack<node> s;
	node temp(i, j);
	s.push(temp);
	while (!s.empty()) {
		temp = s.top();
		int d = temp.dir;
		i = temp.x, j = temp.y;
		temp.dir++;
		s.pop();
		s.push(temp);
		if (i == fx and j == fy) return true;
		if (d == 0) {
			if (i - 1 >= 0 and maze[i - 1][j] and visited[i - 1][j]) 
            {
				node temp1(i - 1, j);
				visited[i - 1][j] = false;
				s.push(temp1);
			}
		}
		else if (d == 1) 
        {
			if (j - 1 >= 0 and maze[i][j - 1] and visited[i][j - 1]) 
            {
				node temp1(i, j - 1);
				visited[i][j - 1] = false;
				s.push(temp1);
			}
		}
		else if (d == 2) 
        {
			if (i + 1 < 5 and maze[i + 1][j] and visited[i + 1][j]) 
            {
				node temp1(i + 1, j);
				visited[i + 1][j] = false;
				s.push(temp1);
			}
		}
		else if (d == 3) 
        {
			if (j + 1 < 5 and maze[i][j + 1] and visited[i][j + 1]) 
            {
				node temp1(i, j + 1);
				visited[i][j + 1] = false;
				s.push(temp1);
			}
		}
		else 
        {
			visited[temp.x][temp.y] = true;
			s.pop();
		}
	}
	return false;
}




int main()
{
    // Maze matrix
    int maze[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 1, 0 }
    };

    // Food coordinates
    int fx = 1, fy = 4;

    cout << canEatFood(maze, fx, fy);
    return 0;
}