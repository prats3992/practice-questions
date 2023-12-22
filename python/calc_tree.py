r"""
an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '-', '*', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).
"""

class Node:
    def __init__(self, val: str, left: 'Node' = None, right: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
    
    def evaluate(self) -> int:
        if self.val.isdigit():
            return int(self.val)
        elif self.val in ["+", "-", "*", "/"]:
            left_val = self.left.evaluate()
            right_val = self.right.evaluate()
            print(f"{left_val} {self.val} {right_val}")
            if self.val == "+":
                return left_val + right_val
            elif self.val == "-":
                return left_val - right_val
            elif self.val == "*":
                return left_val * right_val
            elif self.val == "/":
                if right_val == 0:
                    raise ValueError("Division by zero")
                return left_val / right_val
        else:
            raise ValueError(f"Invalid operator: {self.val}")

if __name__ == "__main__":
    tree = Node("*", Node("+", Node("3"), Node("2")), Node("+", Node("4"), Node("5")))
    print(tree.evaluate())
