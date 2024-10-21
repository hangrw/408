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

int uniquely(MGraph G) { return 1; }

int main() {
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
    printf("There is a unique topological sequence in Graph a.\n");
  } else {
    printf("There is no unique topological sequence in Graph a.\n");
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
    printf("There is a unique topological sequence in Graph b.\n");
  } else {
    printf("There is no unique topological sequence in Graph b.\n");
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
  if (uniquely(Gc)) {
    printf("There is a unique topological sequence in Graph c.\n");
  } else {
    printf("There is no unique topological sequence in Graph c.\n");
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
  if (uniquely(Gd)) {
    printf("There is a unique topological sequence in Graph d.\n");
  } else {
    printf("There is no unique topological sequence in Graph d.\n");
  }

  return 0;
}