func searchMatrix(matrix [][]int, target int) bool {
    //convert to 1d 
    //find mid and find row its in - mid/n
    //find column its in as well - mid % m
    //middle element is matrix[mid/n][mid%n]
    m, n:= len(matrix), len(matrix[0])
    l, r := 0, m*n-1
    for l<=r{
        mid := l+(r-l)/2
        if target == matrix[mid/n][mid%n]{
            return true
        }else if target > matrix[mid/n][mid%n]{
            l = mid + 1
        }else{
            r = mid - 1
        }
    }
    return false
}