# 参照课程讲的实现，push O(1), pop 均摊O(1)。我觉得相当于惰性处理push
# leetcode solution里还有一种是push O(n), pop O(1)的，每次push都把输入栈的内容利用输出栈调个顺序
class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.in_stack = []
        self.out_stack = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.in_stack.append(x)

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if self.out_stack: # 优先输出out_stack中的内容
            return self.out_stack.pop()
        else: # out_stack为空时，把in_stack的元素转入
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
            return self.out_stack.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if self.out_stack: # 优先输出out_stack中的内容
            return self.out_stack[len(self.out_stack)-1]
        else: # out_stack为空时，把in_stack的元素转入
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
            return self.out_stack[len(self.out_stack)-1]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        if len(self.in_stack) == 0 and len(self.out_stack) == 0:
            return True
        return False

# Your MyQueue object will be instantiated and called as such:

if __name__ == '__main__':
    x = 1
    obj = MyQueue()
    obj.push(x)
    param_2 = obj.pop()
    param_3 = obj.peek()
    param_4 = obj.empty()
