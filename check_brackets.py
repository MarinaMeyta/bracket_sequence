import sys

def check_brackets(str):
    stack = []
    brackets = {'{', '(', '['}
    for char in str:
        if char in brackets:
            stack.append(char)
        elif not stack:
            return False
        else:
            top = stack.pop()
            if (top is '[' and char is not ']') or \
                    (top is '(' and char is not ')' ) or \
                    (top is '{' and char is not '}'):
                return False
    return not stack


if __name__ == '__main__':
    print(check_brackets(sys.argv[1]))