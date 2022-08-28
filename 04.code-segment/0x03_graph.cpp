#include<bits/stdc++.h>
#define MAX 1000
#define INF 10000
using namespace std;
// // 邻接表
// //  节点
// struct edge{
//     int to;
//     int cost;
// };
// vector<edge> graph[MAX];
// int v, e;
// void build() {
//     // 顶点数，边数
//     cin >> v >> e;
//     for (int i = 0; i < e; ++i ) {
//         int to;
//         int from;
//         int cost;
//         cin >> from >> to >> cost;
//         graph[from].push_back({to, cost});
//         // 有向图，则是单向 没有to-->from链路
//         graph[to].push_back({from, cost});
//     }
// }

// 邻接矩阵
vector<vector<int>> graph(MAX, vector<int>(MAX, INF));
int v, e;
void build() {
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        // 对角线初始化
        graph[i][i] = 0;
        int to,
            from,
            cost;
        cin >> from >> to >> cost;
        graph[from][to] = cost;
        // 有向图 
        graph[to][from] = cost;
    }
}
// 这两个算法基于 邻接矩阵。
// 最短路径算法  Floyd
/**********
 * 弗洛伊德算法有些类似于dp
 * 考虑从i-->j的最短路径 则依次增加中间点来间接判断
 * 暴力搜索所有可能的中间量k以求出i ---->j的最小值
 *     0     1     2     3
 *  -------------------------
 * 0|  0  |  2  |  6  |  4  |
 * 1| INF |  0  |  3  | INF |
 * 2|  7  | INF |  0  |  1  |
 * 3|  5  | INF |  9  |  0  |
 *  -------------------------
 * i ----> j 
 * matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j])
 * 当前最短路径 与 i ---> k --->j 对比
 ***************/
void  Floyd() {
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v;++i) {
            for (int j = 0; j < v;++j) {
                if(graph[i][k] < INF && graph[k][j] < INF) { //节点均畅通
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}


// 最短路径算法 Dijkstra
/************
 * 迪杰斯特拉算法
 * 迪杰斯特拉算法的核心是贪心
 * 先把起点到所有点的距离存下来找个最短的。
 * 然后再扩张一次 再找最短的依次寻找。
 *     0     1     2     3
 *  -------------------------
 * 0|  0  |  2  |  6  |  4  |
 * 1| INF |  0  |  3  | INF |
 * 2|  7  | INF |  0  |  1  |
 * 3|  5  | INF |  9  |  0  |
 *  -------------------------
 * dis |  0  |  2  |  6  |  4  | 此时 最近的节点是1号节点 考虑1号节点
 * dis |  0  |  2  |  5  |  4  | 2号节点 通过0-->1-->2到达 耗费 5 < 6
 *                               此时 最近的节点是3号节点 考虑3号节点
 * and so on
 * *******/
vector<bool> Dijkstr_visited(MAX, false);
vector<int> Dijkstra_dist(MAX, INF);
void Dijkstra(int val) {
    int start = val;
    Dijkstr_visited[start] = true; //到达过
    Dijkstra_dist = graph[start];      //初始化为初始行
    for (int i = 1; i < v; ++i) {
        int tmp = INF; //最近点
        for (int j = 0; j < v; ++j) {
            if (!Dijkstr_visited[j] && Dijkstra_dist[j] < tmp) { //未访问过，最小值
                start = j;//下次访问这个数组
                tmp = Dijkstra_dist[j];
            }
        }
        Dijkstr_visited[start] = true;
        for (int j = 0; j < v; ++j) {
            Dijkstra_dist[j] = min(Dijkstra_dist[j], Dijkstra_dist[start] + graph[start][j]);
        }
    }
}


// 最小生成树
/**************
 * Prim算法
 * 清空生成树，任取一个顶点加入生成树
 * 寻找生成树外的端点 与 内部的所有连接 的最小值 连同。
 * 重复上述步骤，直到所有的顶点都进入了生成树为止，此时的生成树就是最小生成树。
 * Prim算法的核心是依次寻找生成树与外部连接的最小值扩充（不成环前提下）
 * 
 **********/

/***
 * visited 存放节点是否访问过（最小生成树内部，外部）
 * lowcost 用于寻找靠近角标点的最小权值（扩展）
 * closecost 保存最靠近角标点的元素
 * lowcost[i] closecost[i]是一对。
 * ***/
vector<bool> Prim_visited(MAX, false);
vector<int> Prim_lowcost(MAX, INF);
vector<int> Prim_closecost(MAX, INF);
void Prim() {
    int res = 0;
    // 初始化为从0节点开始
    Prim_visited[0] = true;
    Prim_lowcost = graph[0];
    cout << "0 ---->";
    for (int i = 0; i < v;++i) {
        // 最小权值，对应的角标
        int index = -1,
            tmp = INF;
        // 寻找lowcost的最小值（下一个目标）
        for (int j = 1; j < v; ++j) {   //0已经访问过了 visited[0]一定不成立 故从1开始
            if (!Prim_visited[j] && Prim_lowcost[j] < tmp) {
                index = j;
                tmp = Prim_lowcost[j];
            }
        }
        // 不可达
        if (index == -1) {
            cout << "cost:" << res << endl;
            return; //找不到节点 不可达
        }
        cout << index << " ---->";
        Prim_visited[index] = true;
        res += Prim_lowcost[index];
        // 更新最小权值表
        for (int j = 1; j < v;++j) {
            if (!Prim_visited[j] && graph[index][j] != INF && graph[index][j] < Prim_lowcost[j]) {
                Prim_lowcost[j] = graph[index][j];
                Prim_closecost[j] = index;
            }
        }
    }
}
/*************
 * Kruskal算法
 * 在初始状态时隐去图中的所有边
 * 对所有的边按边权从小到大进行排序
 * 如果当前测试边的两个顶点不在同一个连通块中
 * 则把这条测试边加入当前最小生成树中；否则，将边舍弃；
 * 重复此过程。
 * *******/
// 鸽了
int main() {
    // 数组名 = 指向数组头部的指针
    build();
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v;++j) {
            cout << (graph[i][j] == INF ? -1 : graph[i][j]) << " ";
        }
        cout << endl;
    }
    return 0;
}