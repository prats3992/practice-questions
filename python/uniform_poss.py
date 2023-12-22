"""
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability,
implement a function rand7() that returns an integer from 1 to 7 (inclusive)
"""
def rand5():
    from random import randint
    return randint(1, 5)
def rand7():
    return (5*rand5()+rand5()-5)%5+1 if (5*rand5()+rand5()-5)< 22 else rand5()
if __name__ == '__main__':
    rand7()