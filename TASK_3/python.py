import sys
from collections import deque

INF = float('inf')

class Coordinate:
    def __init__(self, row, col):
        self.row = row
        self.col = col

def main():
    maingrid = [list(filter(lambda x: x != ' ', input().strip())) for _ in range(10)]

    grid = [[0 for _ in range(10)] for _ in range(10)]
    distancegrid = [[INF for _ in range(10)] for _ in range(10)]
    visited = [[0 for _ in range(10)] for _ in range(10)]
    parent = [[Coordinate(-1, -1) for _ in range(10)] for _ in range(10)]

    for i in range(10):
        for j in range(10):
            if maingrid[i][j] == '.':
                grid[i][j] = 1
            elif maingrid[i][j] == '~':
                grid[i][j] = 3
            elif maingrid[i][j] == '^':
                grid[i][j] = 5
            elif maingrid[i][j] == '#':
                grid[i][j] = INF

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    distancegrid[0][0] = 0
    queue = deque([(0, 0)])
    visited[0][0] = 1

    while queue:
        r, c = queue.popleft()
        for d in range(4):
            nr, nc = r + dr[d], c + dc[d]
            if 0 <= nr < 10 and 0 <= nc < 10:
                tile_cost = grid[nr][nc]
                if tile_cost == INF:
                    continue
                new_cost = distancegrid[r][c] + tile_cost
                if new_cost < distancegrid[nr][nc]:
                    distancegrid[nr][nc] = new_cost
                    parent[nr][nc] = Coordinate(r, c)
                    if not visited[nr][nc]:
                        visited[nr][nc] = 1
                        queue.append((nr, nc))

    start = end = None
    for i in range(10):
        for j in range(10):
          
            if maingrid[i][j] == 'S':
                start = Coordinate(i, j)
            elif maingrid[i][j] == 'G':
                end = Coordinate(i, j)
                print(f"MINIMUM COST TO REACH END POINT : {distancegrid[i][j]}")
       

    for i in range(10):
        for j in range(10):
            if maingrid[i][j] == '#':
                parent[i][j] = Coordinate(-1, -1)

    print("PATH USED BY ROBOT : ", end="")
    def path_printer(p, start, parent):
        if p.row == start.row and p.col == start.col:
            print(f"({p.row}, {p.col})", end="")
            return
        path_printer(parent[p.row][p.col], start, parent)
        print(f"->({p.row}, {p.col})", end="")

    path_printer(end, start, parent)

if __name__ == "__main__":
    main()