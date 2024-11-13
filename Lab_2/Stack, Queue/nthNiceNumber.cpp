#include <iostream>
#include<queue>
using namespace std;

long long nthNiceNumber(int n) {
    queue<long long> q;
	q.push(2);
	q.push(5);
	n--;  
	while(n--)
    {
	    long long x = q.front();
	    q.pop();    
	    q.push(x*10+2);
	    q.push(x*10+5);
	}   
    return q.front();
}

int main() {
    int n = 10000;
    cout << nthNiceNumber(n) << endl;
	return 0;
}