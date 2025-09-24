/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "math"

func maxPathSum(root *TreeNode) int {
	maxSumSoFar := -math.MaxInt32

	var dfsHelper func(*TreeNode) int

	dfsHelper = func(root *TreeNode) int {
		if root == nil {
			return 0
		}

		leftGain := dfsHelper(root.Left)
		rightGain := dfsHelper(root.Right)

		leftGain = max(0, leftGain)
		rightGain = max(0, rightGain)

		sum := root.Val + leftGain + rightGain
		maxSumSoFar = max(maxSumSoFar, sum)

		return root.Val + max(leftGain, rightGain)
	}
	dfsHelper(root)

	return maxSumSoFar
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
