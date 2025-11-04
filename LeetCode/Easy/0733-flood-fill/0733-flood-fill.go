func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
    if image[sr][sc] == newColor{
        return image
    }
    dfs_helper(image, sr, sc, image[sr][sc], newColor)
    return image
}

func dfs_helper(image [][]int, sr int, sc int, color int, newColor int){
    if sc < 0 || sr < 0 || sr >= len(image) || sc > len(image[0]) || image[sr][sc] != color {
        return
    }
    image[sr][sc] = newColor
    dfs_helper(image, sr-1, sc, color, newColor)
    dfs_helper(image, sr+1, sc, color, newColor)
    dfs_helper(image, sr, sc-1, color, newColor)
    dfs_helper(image, sr, sc+1, color, newColor)
}