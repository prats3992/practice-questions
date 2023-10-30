"""
Given a array of numbers representing the stock prices of a company in chronological order, 
write a function that calculates the maximum profit you could have made from buying and selling that stock once. 
You must buy before you can sell it.
For example, given [9, 11, 8, 5, 7, 10], you should return 5, 
since you could buy the stock at 5 dollars and sell it at 10 dollars.
"""


def max_profit(arr: list[int]) -> int:
    min_price = arr[0]
    max_profit = 0
    for i in range(1, len(arr)):
        if arr[i] < min_price:
            min_price = arr[i]
        elif arr[i] - min_price > max_profit:
            max_profit = arr[i] - min_price
    return max_profit


if __name__=="__main__":
    arr = [9, 11, 8, 5, 7, 10]
    print(max_profit(arr))
