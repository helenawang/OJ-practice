from collections import deque

class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.in_q = deque()
        self.out_q = deque()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: void
        """
        self.in_q.append(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        while len(self.in_q) > 1:
            self.out_q.append(self.in_q.popleft())
        result = self.in_q.popleft() # 取最后一个元素，即为栈顶
        while len(self.out_q) > 0:
            self.in_q.append(self.out_q.popleft()) # 原样放回
        return result

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        while len(self.in_q) > 1:
            self.out_q.append(self.in_q.popleft())
        result = self.in_q.popleft() # 取最后一个元素，即为栈顶
        while len(self.out_q) > 0:
            self.in_q.append(self.out_q.popleft()) # 原样放回
        self.in_q.append(result)
        return result

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.in_q) == 0:
            return True
        return False

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
