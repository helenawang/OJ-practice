# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def print(self):
        p = self
        while p:
            print(p.val, ' ')
            p = p.next
        print('\n')

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cur, prev = head, None
        while cur:
            # 这个写法，对于从编译型语言转过来的人有些误导性。
            # 注意是等号右面的都算完然后批量赋值给等号左面的变量
            # cur.next, prev, cur = prev, cur, cur.next

            # 我更习惯下面这个写法。其实上面的写法就是省了一个tmp变量
            # 提交后发现，下面的写法比上面的快8ms，这不是运气吧。另外，同样的代码，在中国版上运行的时间比美国版慢20%左右，不知道是不是网站的原因
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp
        return prev

if __name__ == '__main__':
    head = None
    for j in range(1, 6):
        i = 6 - j
        p = ListNode(i)
        p.next = head
        head = p
    head.print()
    new_head = Solution().reverseList(head)
    new_head.print()
