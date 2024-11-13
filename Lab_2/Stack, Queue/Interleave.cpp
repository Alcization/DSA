#include <iostream>
#include <stack>
#include <queue>
using namespace std;


void interleaveQueue(queue<int>& q){
    queue<int> first;
    queue<int> last;
    int count = 0;
    while (!q.empty())
    {
        first.push(q.front());
        last.push(q.front());
        q.pop();
        count++;
    }
    count = count / 2;
    for (int i = 0; i < count; i++)
    {
        last.pop();
    }
    while (count > 0)
    {
        q.push(first.front());
        first.pop();
        q.push(last.front());
        last.pop();
        count--;
    }
}



int main()
{
    queue<int> q;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int element; cin >> element;
        q.push(element);
    }
    interleaveQueue(q);
    while (!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}