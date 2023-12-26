"""
Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid 
(i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.
"""
def minParentheses(p):
     
    # maintain balance of string 
    bal=0
    ans=0
    for i in range(0,len(p)):
        if(p[i]=='('):
            bal+=1
        else:
            bal+=-1
             
        # It is guaranteed bal >= -1
        if(bal==-1):
            ans+=1
            bal+=1
    return bal+ans
 
# Driver code
if __name__=='__main__':
    p = ")("
     
# Function to print required answer 
    print(minParentheses(p))