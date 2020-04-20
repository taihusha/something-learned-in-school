/* 
你现在手里有一份大小为 N x N 的「地图」（网格） grid，

上面的每个「区域」（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，

请你找出一个海洋区域，这个海洋区域到离它最近的陆地区域的距离是最大的。

我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。

如果我们的地图上只有陆地或者海洋，请返回 -1。
 */
/* 思路: BFS, 所有陆地入队列, 然后依次出队 */
/* 出队时, 将四周元素入队, 最后一层即为答案 */
typedef struct {
    int x;
    int y;
    int lev;
} Queue;

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    Queue *Q = (Queue*)malloc(sizeof(Queue) * n * n);
    int front = 0;
    int rear  = 0;
    int i, j, xx, yy, x, y, lev;
    int findWater = 0;
    int xShift[] = {-1, 1,  0, 0};
    int yShift[] = { 0, 0, -1, 1};
    /* 找到陆地入队 */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                Q[rear].x     = i;
                Q[rear].y     = j;
                Q[rear++].lev = 0;
            }
        }
    }

    /* 出队列, 将四周元素入队 */
    while (rear != front) {
        x   = Q[front].x;
        y   = Q[front].y;
        lev = Q[front++].lev;
        for (i = 0; i < 4; i++) {
            xx = x + xShift[i];
            yy = y + yShift[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == 0) {
                findWater    = 1;
                grid[xx][yy] = 2; /* 后入队的标记为2 */
                Q[rear].x     = xx;
                Q[rear].y     = yy;
                Q[rear++].lev = lev + 1;
            }
        }
    }
    /* 没有找到陆地或水返回-1, 找到返回lev */
    return findWater == 0 ? -1 : lev;
}

