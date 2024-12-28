#include <stdio.h>
#include <string.h>

int garden[50][50], m, n;

void DFS(int x, int y) {
    // 범위를 벗어나거나, 방문하지 않은 위치라면 리턴
    if (x < 0 || x >= m || y < 0 || y >= n || garden[x][y] == 0) return;

    // 방문 처리
    garden[x][y] = 0;

    // 상하좌우 탐색
    DFS(x + 1, y);
    DFS(x - 1, y);
    DFS(x, y + 1);
    DFS(x, y - 1);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int k, x, y, cnt = 0;

        memset(garden, 0, sizeof(garden));

        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y);
            garden[x][y] = 1;
        }

        // 지렁이 수 계산
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (garden[i][j] == 1) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
