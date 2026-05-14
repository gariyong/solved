#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string num = "";
    string temp = "";
    vector<string> str_num = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" 
        , "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            num += s[i];
            continue;
        }

        temp += s[i];
        for (int i = 0; i < 10; i++) {
            if (temp == str_num[i]) {
                num += str_num[10 + i];
                temp.assign("");
                break;
            }
        }
    }

    int result = stoi(num);
    
    return result;
}