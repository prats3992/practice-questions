# Algorithm 5: Find(x, left,right)
# Input: A search key x and two indices, left and right of the sorted list L.
# Output: 0 or an integer value between left and right
# if left = right then
# if L[left] = x then
# return left;
# end
# else
# return 0 ; // Unsuccessful
# end
# end
# else
#  middle = d(left + right)/2e;
#  if x < L[middle] then
#  return Find(x, left, middle − 1);
#  end
#  else
#  return Find(x, middle,right);
#  end
#  end

L = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
def Find(x, left, right):
    if left == right:
        if L[left] == x:
            return left
        else:
            return 0
    else:
        middle = (left + right) // 2
        if x < L[middle]:
            return Find(x, left, middle - 1)
        else:
            return Find(x, middle, right)
        
print(Find(5, 0, len(L) - 1))

# Algorithm 4: Find(x, left,right)
# Input: A search key x and two indices, left and right of a sorted list L.
# Output: 0 or an integer value between left and right
# if left > right then
# return 0 ; // Unsuccessful
# end
# else
# middle = d(left + right)/2e;
# if x < L[middle] then
# return Find(x, left, middle − 1);
# end
# else
#  if x > L[middle] then
#  return Find(x, middle + 1,right);
#  end
#  else
#  return middle;
#  end
#  end

def Find(x, left, right):
    if left > right:
        return 0
    else:
        middle = (left + right) // 2
        if x < L[middle]:
            return Find(x, left, middle - 1)
        elif x > L[middle]:
            return Find(x, middle + 1, right)
        else:
            return middle
        
print(Find(5, 0, len(L) - 1))