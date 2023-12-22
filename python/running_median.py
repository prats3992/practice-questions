"""
Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2
"""
def running_median(numbers: list[int]) -> list:
    output=[]
    for i in range(len(numbers)):
        holder=sorted(numbers[:i+1])
        print(output)
        middle_index = len(holder) // 2
        if i%2==0:
            middle_element = holder[middle_index]
            output.append(middle_element)
            
        else:
            middle_average = (holder[middle_index - 1] + holder[middle_index]) / 2
            output.append(middle_average)
    return [int(x) if str(x).endswith(".0") else x for x in output]

def main():
    numbers = [2, 1, 5, 7, 2, 0, 5]
    result = running_median(numbers)
    for median in result:
        print(median)

if __name__ == '__main__':
    main()
