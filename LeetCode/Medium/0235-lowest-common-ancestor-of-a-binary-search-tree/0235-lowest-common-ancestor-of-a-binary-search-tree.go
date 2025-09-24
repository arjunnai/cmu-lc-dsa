/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	currentNode := root
	for currentNode != nil {
		if p.Val < currentNode.Val && q.Val < currentNode.Val {
			currentNode = currentNode.Left
		} else if p.Val > currentNode.Val && q.Val > currentNode.Val {
			currentNode = currentNode.Right
		} else {
			return currentNode
		}
	}
	return nil
}