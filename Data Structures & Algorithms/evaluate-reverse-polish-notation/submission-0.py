class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for token in tokens:
            if token in {"+", "-", "*", "/"}:
                # The first popped element is the right-hand operand
                b = stack.pop()
                # The second popped element is the left-hand operand
                a = stack.pop()
                
                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                elif token == "/":
                    # int() handles truncation toward zero automatically in Python
                    stack.append(int(a / b))
            else:
                # It's a number, convert string to integer
                stack.append(int(token))
                
        return stack[0]