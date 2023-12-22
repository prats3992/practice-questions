"""
Given a string, find the longest palindromic contiguous substring. 
If there are more than one with the maximum length, return any one.
For example, the longest palindromic substring of "aabcdcb" is "bcdcb". 
The longest palindromic substring of "bananas" is "anana".
"""

def palindrome(string: str) -> str:
    output = string[::-1]
    return output == string

def longest_palindrome(string: str) -> str:
    output = ""
    for i in range(len(string)):
        for j in range(i+1, len(string)+1):
            if palindrome(string[i:j]) and len(string[i:j]) > len(output):
                output = string[i:j]
    return output

if __name__ == "__main__":
    string = "aabcdcb"
    print(longest_palindrome(string))
    string = "bananas"
    print(longest_palindrome(string))