/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// find middle (fast slow problem)
// split the list first
// reverse second half (iterative reversal)
// merge 2 halves
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}
     
	fast, slow := head, head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
    second := slow.Next
	slow.Next = nil
    var prev *ListNode = nil
    for curr := second; curr != nil; {
        tempNext := curr.Next
        curr.Next = prev
        prev = curr
        curr = tempNext
    }

    head1, head2 := head, prev
    for head2 != nil {
        tempNext1 := head1.Next
        tempNext2 := head2.Next
        head1.Next = head2
        head2.Next = tempNext1
        head1 = tempNext1
        head2 = tempNext2
    }
}