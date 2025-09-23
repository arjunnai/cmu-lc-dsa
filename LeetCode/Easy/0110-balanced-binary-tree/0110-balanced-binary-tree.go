/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
    _, bal := dfs_helper(root)
    return bal
}

func dfs_helper(root *TreeNode) (int,bool){
    if root == nil{
        return 0, true
    }

    leftHeight, Lbalance := dfs_helper(root.Left)
    rightHeight, Rbalance := dfs_helper(root.Right)

    isNodeBalance := Lbalance && Rbalance && (math.Abs(float64(leftHeight-rightHeight)) <=1)
    height := 1 + max(leftHeight, rightHeight)

    if isNodeBalance{
        return height, true
    }else{
        return -1, false
    }
}

func max(a,b int) int{
    if a > b {
        return a
    } 
    return b
}