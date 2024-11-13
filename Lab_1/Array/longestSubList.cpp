#include <iostream>
#include <vector>
using namespace std;
int longestSublist(vector<std::string>& words) {
    if (words.empty()) {
        return 0;  
    }
    int longest = 1;
    int current = 1;
    char current_first_letter = words[0][0];  
    for (size_t i = 1; i < words.size(); i++) {
        if (words[i].empty()) {
            continue;  
        }
        char first_letter = words[i][0];
        if (first_letter == current_first_letter) {
            current++;
        } else {
            longest = max(longest, current);
            current = 1;
            current_first_letter = first_letter;
        }
    }
    longest = max(longest, current);
    return longest;
}
int main()
{
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words);
}