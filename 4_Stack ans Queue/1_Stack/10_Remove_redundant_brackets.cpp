#include <bits/stdc++.h>
using namespace std;
 
// This function checks redundant brackets in a
// balanced expression
bool checkRedundantBracket(string& str){
    // create a stack of characters
    stack<char> character;
 
    // Iterate through the given expression
    for (auto& ch : str) {
 
        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = character.top();
            character.pop();
 
            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;
 
            while (!character.empty() and top != '(') {
 
                // Check for operators in expression
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;
 
                // Fetch top element of character
               // back
                top = character.top();
                character.pop();
            }
 
            // If operators not found
            if (flag == true)
                return true;
        }
 
        else
            character.push(ch); // push open parenthesis '(',
                  // operators and operands to stack
    }
    return false;
}
 

int main(){
    string str = "((a+b+c))";

    if(checkRedundantBracket(str)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

    return 0;
}