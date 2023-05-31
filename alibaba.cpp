

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[][] matrix = new String[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = sc.next();
            }
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt() - 1, y = sc.nextInt() - 1;
            if (matrix[t][y].equals("-1")) System.out.println(0);
            else {
                int score = dfs(matrix, t, y, matrix[t][y].charAt(0), n, m);
                updateMatrix(matrix, n, m);
                System.out.println(score);
            }
        }
    }

int dfs(String[][] matrix, int r, int c, char color, int n, int m) {
    if (r < 0 || r >= n || c < 0 || c >= m || matrix[r][c].charAt(0) != color) return 0;
    int score = matrix[r][c].charAt(1) - '0';
    matrix[r][c] = "-1";
    score += dfs(matrix, r + 1, c, color, n, m);
    score += dfs(matrix, r - 1, c, color, n, m);
    score += dfs(matrix, r, c + 1, color, n, m);
    score += dfs(matrix, r, c - 1, color, n, m);
    return score;
}

void updateMatrix(String[][] matrix, int n, int m) {
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = n - 1; i >= 0; ) {
            while (i >= 0 && matrix[i][j].equals("-1")) {
                cnt++;
                i--;
            }
             while (i >= 0 && !matrix[i][j].equals("-1")) {
                matrix[i + cnt][j] = matrix[i][j];
                i--;
            }
        }
        while (--cnt >= 0) {
            matrix[cnt][j] = "-1";
        } 
    }
}