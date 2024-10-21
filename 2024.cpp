#include "2024.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 11

typedef struct {             // 图的类型定义
  int numVertices, numEdges; // 图的顶点数和有向边数
  char VerticesList[MAXV];   // 顶点表，MAXV为已定义常量
  int Edge[MAXV][MAXV];      // 邻接矩阵
} MGraph;

// 拓扑序列是否唯一
int uniquely(MGraph G) {
  int n = G.numVertices;
  // 初始化入度
  int indegree[n];
  memset(indegree, 0, sizeof(indegree));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (G.Edge[i][j]) {
        indegree[j]++;
      }
    }
  }

  int queue[n];
  int front = 0, rear = 0;
  int count = 0; //拓扑排序执行次数
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      // 入度为0的点入队
      queue[rear++] = i;
    }
    if (rear - front > 1)
      return 0;
  }
  // 队列非空
  while (front < rear) {
    int x = queue[front++];
    // 拓扑序列的长度和点的长度相同
    count++;
    for (int j = 0; j < n; j++) {
      // 如果存在边，则对应的入度--
      if (G.Edge[x][j]) {
        indegree[j]--;
        if (indegree[j] == 0) {
          queue[rear++] = j;
        }
        if (rear - front > 1) {
          return 0; //序列不唯一
        }
      }
    }
  }
  return count == n;
}

//测试用例
void run() {
  int result[] = {0, 0, 0, 0};
  // 以图(a)为例
  MGraph Ga;
  Ga.numEdges = 3;
  Ga.numVertices = 4;
  memset(Ga.VerticesList, 0, sizeof(Ga.numVertices));
  char Va[4] = {'a', 'b', 'c', 'd'};
  for (int i = 0; i < Ga.numVertices; i++) {
    Ga.VerticesList[i] = Va[i];
  }
  memset(Ga.Edge, 0, sizeof(Ga.numVertices));
  int Ma[4][4] = {{0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}};
  for (int i = 0; i < Ga.numVertices; i++) {
    for (int j = 0; j < Ga.numVertices; j++) {
      Ga.Edge[i][j] = Ma[i][j];
    }
  }
  if (uniquely(Ga)) {
    result[0]++;
  }

  // 以图(b)为例
  MGraph Gb;
  Gb.numEdges = 5;
  Gb.numVertices = 4;
  memset(Gb.VerticesList, 0, sizeof(Gb.numVertices));
  char Vb[4] = {'a', 'b', 'c', 'd'};
  for (int i = 0; i < Gb.numVertices; i++) {
    Gb.VerticesList[i] = Vb[i];
  }
  memset(Gb.Edge, 0, sizeof(Gb.numVertices));
  int Mb[4][4] = {{0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}};
  for (int i = 0; i < Gb.numVertices; i++) {
    for (int j = 0; j < Gb.numVertices; j++) {
      Gb.Edge[i][j] = Mb[i][j];
    }
  }
  if (uniquely(Gb)) {
    result[1]++;
  }

  // 以图(c)为例
  MGraph Gc;
  Gc.numEdges = 2;
  Gc.numVertices = 4;
  memset(Gc.VerticesList, 0, sizeof(Gc.numVertices));
  char Vc[4] = {'a', 'b', 'c', 'd'};
  for (int i = 0; i < Gc.numVertices; i++) {
    Gc.VerticesList[i] = Vc[i];
  }
  memset(Gc.Edge, 0, sizeof(Gc.numVertices));
  int Mc[4][4] = {{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}};
  for (int i = 0; i < Gc.numVertices; i++) {
    for (int j = 0; j < Gc.numVertices; j++) {
      Gc.Edge[i][j] = Mc[i][j];
    }
  }
  if (!uniquely(Gc)) {
    result[2]++;
  }

  // 以图(d)为例
  MGraph Gd;
  Gd.numEdges = 2;
  Gd.numVertices = 4;
  memset(Gd.VerticesList, 0, sizeof(Gd.numVertices));
  char Vd[4] = {'a', 'b', 'c', 'd'};
  for (int i = 0; i < Gd.numVertices; i++) {
    Gd.VerticesList[i] = Vd[i];
  }
  memset(Gd.Edge, 0, sizeof(Gd.numVertices));
  int Md[4][4] = {{0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}};
  for (int i = 0; i < Gd.numVertices; i++) {
    for (int j = 0; j < Gd.numVertices; j++) {
      Gd.Edge[i][j] = Md[i][j];
    }
  }
  if (!uniquely(Gd)) {
    result[3]++;
  }
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (result[i] == 0) {
      printf("测试用例%d错误\n", i);
    } else {
      count++;
    }
  }
  if (count == 4) {
    printf("Accepted");
  } else {
    printf("WA");
  }
}