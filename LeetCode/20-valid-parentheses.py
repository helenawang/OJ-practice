class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        mapping = {
            ')': '(',
            ']': '[',
            '}': '{'
        }
        for p in s:
            if p not in mapping:
                stack.append(p)
            elif not stack or stack.pop() != mapping[p]:
                return False

        return not stack
