# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    def print(self):
        p = self
        while p:
            print(p.val, ' ')
            p = p.next
        print('\n')

class Solution(object):
    # 参考了https://blog.csdn.net/xy010902100449/article/details/48995255 的思路，图非常清晰，喜欢这种几何式的解法
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fast = slow = head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast: # 有环，快慢指针一定在环内相遇
                outer = head # 环外指针置回起点head
                inner = slow # 环内指针从相遇点开始
                while outer is not inner:
                    outer = outer.next
                    inner = inner.next
                return outer # 一定会在环起点相遇，因两段路径等长
        return None

if __name__ == '__main__':
    head = ListNode(1)
    last = ListNode(3)
    p = ListNode(2)
    head.next = p
    p.next = last
    # last.next = head

    # head.print()
    print(Solution().detectCycle(head).val)
