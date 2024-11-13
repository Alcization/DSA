#include <iostream>
#include <string>
using namespace std;


string repeat(string t, int rt){
    if(rt == 0){
        return "";
    }
    return t + repeat(t,rt-1);
}

void tem(string s, string &temp, int &countO, int &j, int &i){
     if(s[j] == ')'){
        countO--;
     }else if(s[j] == '('){
        countO++;
      }
      if(countO == 0) return;
      temp += s[j];
      j++;
      i++;
      tem(s, temp, countO, j, i);
}

void expand(string s, string &ans, string &temp, int rt, int &countO, int i, int n){
    if(i == n) return;
    else{
        if(isdigit(s[i])){
            rt = s[i] - '0';
        }else if(s[i] == '('){
            countO++;
            int j = i + 1;
            tem(s, temp, countO, j, i);

            ans += repeat(temp, rt);
            temp = "";
        }else if(isalpha(s[i])){
            ans += s[i];
        }
    }
    expand(s, ans, temp, rt, countO, i+1, n);
}

string expand(string s){
    int rt = 0, countO = 0, n = s.length(), i = 0;
    string ans = "";
    string temp = "";
    expand(s, ans, temp, rt, countO, i, n);
    int f = ans.find('(');
    if( f != -1){
        ans = expand(ans);
    }
    return ans;
}
