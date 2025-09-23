/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
    _, maxDiameter := dfs_helper(root)
    return maxDiameter
}


func dfs_helper(root *TreeNode) (int,int){
    if root == nil{
        return 0,0
    }

    Ldepth, Ldiameter := dfs_helper(root.Left)
    Rdepth, Rdiameter := dfs_helper(root.Right)
    depth := 1 + max(Ldepth, Rdepth)

    diameter := Ldepth + Rdepth
    maxDiameter := max(diameter, max(Ldiameter, Rdiameter))


    return depth, maxDiameter
}


func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}