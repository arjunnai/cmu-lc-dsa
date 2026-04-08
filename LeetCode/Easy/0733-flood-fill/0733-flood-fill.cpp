class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int startColor = image[sr][sc];
        if (startColor == color) {
            return image;
        }
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color,
             int newColor) {
        // base case edge conditions
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ||
            image[sr][sc] != color) {
            return;
        }
        image[sr][sc] = newColor;
        //move in all 4 directions
        dfs(image, sr + 1, sc, color, newColor);
        dfs(image, sr, sc + 1, color, newColor);
        dfs(image, sr - 1, sc, color, newColor);
        dfs(image, sr, sc - 1, color, newColor);
    }
};