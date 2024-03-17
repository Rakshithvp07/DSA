#include <stdio.h>

int a[20][20], q[20], visited[20], reach[10], n, i, j, f = 0, r = 0;

void bfs(int v) {
    visited[v] = 1;
    q[++r] = v;
    while (f != r) {
        v = q[++f];
        printf("%d\n", v);
        for (i = 1; i <= n; i++) {
            if (a[v][i] == 1 && visited[i] == 0) {
                q[++r] = i;
                visited[i] = 1;
            }
        }
    }
}

void create() {
    int i;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }
    for (i = 1; i <= n - 1; i++)
        reach[i] = 0;
    printf("\nEnter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}

int main() {
    int v, ch;
    do {
        printf("\n1. CREATE GRAPH\n2. BFS\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                printf("\nEnter the starting vertex: ");
                scanf("%d", &v);
                if ((v < 1) || (v > n))
                    printf("\nBFS is not possible");
                else {
                    printf("\nThe nodes which are reachable from %d:\n", v);
                    bfs(v);
                }
                break;
            default:
                printf("\nINVALID CHOICE\n");
        }
    } while (ch <= 2);
    return 0;
}
