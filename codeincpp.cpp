#include <iostream>
#include <vector>
#include <limits>

#define INF 1e9

struct coordinate {
    int row, col;
};

void pathprinter(coordinate p, coordinate start, coordinate a[10][10]) {
    if (p.row == start.row && p.col == start.col) {
        std::cout << "(" << p.row << ", " << p.col << ")";
        return;
    }
    pathprinter(a[p.row][p.col], start, a);
    std::cout << " ->(" << p.row << ", " << p.col << ")";
}

int main() {
    char maingrid[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cin >> maingrid[i][j];
        }
    }

    std::vector<std::vector<int>> grid(10, std::vector<int>(10));
    std::vector<std::vector<int>> distancegrid(10, std::vector<int>(10, INF));
    std::vector<std::vector<int>> visited(10, std::vector<int>(10, 0));
    coordinate parent[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maingrid[i][j] == '.') grid[i][j] = 1;
            if (maingrid[i][j] == '~') grid[i][j] = 3;
            if (maingrid[i][j] == '^') grid[i][j] = 5;
            if (maingrid[i][j] == '#') grid[i][j] = INF;
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j) {
            visited[i][j] = 0;
            parent[i][j] = { -1, -1 };
        }

    distancegrid[0][0] = 0;
    while (true) {
        int minCost = INF, r = -1, c = -1;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                if (!visited[i][j] && distancegrid[i][j] < minCost) {
                    minCost = distancegrid[i][j];
                    r = i;
                    c = j;
                }
        if (r == -1) break; // No reachable nodes left
        visited[r][c] = 1;
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10) {
                int tileCost = grid[nr][nc];
                if (tileCost == INF) continue;
                int newCost = distancegrid[r][c] + tileCost;
                if (newCost < distancegrid[nr][nc]) {
                    distancegrid[nr][nc] = newCost;
                    parent[nr][nc] = { r, c };
                }
            }
        }
    }

    coordinate start, end;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maingrid[i][j] == 'S') start = { i, j };
            if (maingrid[i][j] == 'G') {
                end = { i, j };
                std::cout << "MINIMUM COST TO REACH END POINT : ";
                std::cout << distancegrid[i][j] << std::endl;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maingrid[i][j] == '#') parent[i][j] = { -1, -1 };
        }
    }

    std::cout << "PATH USED BY ROBOT : ";
    pathprinter(end, start, parent);

    return 0;
}
