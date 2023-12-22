"""
The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
"""

def power_set(given_set:list)->list:
    output=[[]]
    for i in range(len(given_set)):
        output.append([given_set[i]])
        for j in range(i+1,len(given_set)):
            output.append([given_set[i],given_set[j]])
            for k in range(j+1,len(given_set)):
                output.append([given_set[i],given_set[j],given_set[k]])
    return output

if __name__=="__main__":
    given_set=[1,2,3]
    print(power_set(given_set))
    