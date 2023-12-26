/*
Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid 
(i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.
*/

#include <string>
#include <iostream>
using namespace std;
 
// Function to return required minimum number
int minParentheses(string p)
{
 
    // maintain balance of string
    int bal = 0;
    int ans = 0;
 
    for (int i = 0; i < p.length(); ++i) {
 
        bal += p[i] == '(' ? 1 : -1;
 
        // It is guaranteed bal >= -1
        if (bal == -1) {
            ans += 1;
            bal += 1;
        }
    }
 
    return bal + ans;
}
 
// Driver code
int main()
{
 
    string p = "())";
 
    // Function to print required answer
    cout << minParentheses(p);
 
    return 0;
}