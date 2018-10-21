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
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None: # len <= 0
            return False
        slow = head.next
        fast = head.next.next
        while slow != fast:
            if fast is None or fast.next is None or fast.next.next is None:
                return False
            slow = slow.next
            fast = fast.next.next
        return True

    def hasCycleQ(self, head):
        fast = slow = head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                return True
        return False

if __name__ == '__main__':
    head = ListNode(1)
    last = ListNode(3)
    p = ListNode(2)
    head.next = p
    # p.next = last
    # last.next = head

    # head.print()
    print(Solution().hasCycleQ(head))
