class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // double levels[102][102] = {0.0};
        // levels[0][0] = (double)poured;

        // for (int r = 0; r <= query_row; r++) {
        //     for (int c = 0; c <= r; c++) {
        //         if (levels[r][c] > 1.0) {
        //             double next = (levels[r][c] - 1.0) / 2.0;
        //             levels[r][c] = 1.0;
        //             levels[r + 1][c] += next;
        //             levels[r + 1][c+1] += next;
        //         }
        //     }
        // }

        double levels[101][101] = {0.0};
        levels[0][0] = (double)poured;

        for (int r = 0; r < query_row; r++) {
            for (int c = 0; c < r + 1; c++) {
                double next = (levels[r][c] - 1.0) / 2.0;
                if (next > 0.0) {
                    levels[r + 1][c] += next;
                    levels[r + 1][c + 1] += next;
                }
            }
        }

        return min(1.0, levels[query_row][query_glass]);
    }
};