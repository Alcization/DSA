#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stock_span(const vector<int>& ns) {
    // STUDENT ANSWER
    vector<int> output;
    for(int i = 0; i < int(ns.size()); i++){
        int count = 1;
        if(i == 0) output.push_back(count);
        else{
            for(int j = i - 1; j >= 0; j--){
                if(ns[i] > ns[j]) count++;
                else break;
            }
            output.push_back(count);
        }
    }
    return output;
}

vector<int> stock_span(const vector<int>& ns) {
    // STUDENT ANSWER
    stack<int> s;
    vector<int> ans = {};
    for (unsigned int i = 0; i < ns.size(); i++) {
        while (!s.empty() && ns[s.top()] < ns[i]) 
            s.pop();
        if (s.empty()) {
            ans.push_back(1 + i);
        } else {
            ans.push_back(i - s.top());
        }
        s.push(i);
    }
    return ans;
}