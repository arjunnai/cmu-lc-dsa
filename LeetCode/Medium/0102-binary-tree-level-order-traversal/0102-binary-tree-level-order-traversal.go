/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	q := []*TreeNode{}
	levelSize := 0
	results := [][]int{}
	if root == nil {
		return [][]int{}
	}
	q = append(q, root)
	for len(q) > 0 {
		levelSize = len(q)
		currentLevelValues := []int{}
		for i := 0; i < levelSize; i++ {
			qVal := q[0]
			q = q[1:]
			currentLevelValues = append(currentLevelValues, qVal.Val)
			if qVal.Left != nil {
				q = append(q, qVal.Left)
			}
			if qVal.Right != nil {
				q = append(q, qVal.Right)
			}
		}
		results = append(results, currentLevelValues)

	}
    return results
}