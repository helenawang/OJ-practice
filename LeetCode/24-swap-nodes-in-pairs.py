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
    # 我的是把pre->cur->tmp变成了cur->pre->tmp
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None: # len <= 1
            return head

        prev = head
        cur = prev.next
        new_head = head.next
        while prev and cur:
            tmp = cur.next
            cur.next = prev
            if tmp is None: # 到达了最后一个节点，且链表长度为偶数。返回当前的cur
                prev.next = None
                return new_head
            if tmp.next is None:
                prev.next = tmp # 到达了最后一段，且链表长度为奇数
                return new_head
            # 未到达最后一段，正常以步长为2更新
            prev.next = tmp.next
            prev = tmp
            cur = tmp.next
        return new_head

    # 它这个是把pre->a->b变成了pre->b->a
    def swapPaisrQ(self, head):
        dummy = ListNode(0)
        pre, pre.next = dummy, head
        while pre.next and pre.next.next:
            a = pre.next
            b = a.next
            pre.next, b.next, a.next = b, a, b.next
            pre = a
        return dummy.next

if __name__ == '__main__':
    head = None
    MAX = 8
    for j in range(1, MAX):
        i = MAX - j
        p = ListNode(i)
        p.next = head
        head = p
    head.print()
    new_head = Solution().swapPairs(head)
    new_head.print()
