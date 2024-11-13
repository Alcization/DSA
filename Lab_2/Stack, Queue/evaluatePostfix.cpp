#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string expr){
    /*TODO*/
    stack<int> st;
    int n = expr.length();
    for (int i = 0; i < n; i++)
    {
        if (isdigit(expr[i])) 
        {
            int val = 0;
            while (i < n && isdigit(expr[i]))
            {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            st.push(val);
        }
        if (expr[i] == '+' or expr[i] == '-' or expr[i] == '*' or expr[i] == '/' )
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (expr[i] == '+') st.push(a + b);
            else if (expr[i] == '-') st.push(b - a); 
            else if (expr[i] == '*') st.push(a * b); 
            else if (expr[i] == '/') st.push(b / a); 
        } else continue;
    }
    return st.top();
}

int main()
{
    cout << evaluatePostfix("2 3 1 * + 9 -") << endl;
    cout << evaluatePostfix("100 200 + 2 / 5 * 7 +");
    return 0;
}

