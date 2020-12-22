#ifndef T1_GRAPH_H
#define T1_GRAPH_H

#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
using namespace std;

#define MAXSIZE 100
typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType Vex[MAXSIZE];
    EdgeType Edge[MAXSIZE][MAXSIZE];
    int vexnum,arcnum;
}MGraph;

typedef struct Arcnode{
    EdgeType adjvex;
    struct Arcnode*next;
}Arcnode;

typedef struct Vnode{
    VertexType data;
    Arcnode*first;
}Vnode,Adjlist[MAXSIZE];

typedef struct{
    Adjlist vertices;
    int vexnum,arcnum;
}AGraph;

class Graph_M{
//private:
//    MGraph g;
public:
    void create_graph(MGraph& g);
    bool Neighbors(MGraph g,VertexType x);
    bool Insertvertex(MGraph& g,VertexType x);
    bool Deletevertex(MGraph& g,VertexType x);
    bool Addedge(MGraph& g,EdgeType x,EdgeType y);
    bool Removedge(MGraph& g,EdgeType x,EdgeType y);
    EdgeType Firstneighbor(MGraph g,EdgeType x);
    EdgeType Nextneighbor(MGraph g,EdgeType x,EdgeType y);
    int get_edge_value(MGraph g,EdgeType x,EdgeType y);
    bool set_edge_value(MGraph& g,EdgeType x,EdgeType y,int v);
    bool Adjacent(MGraph g,EdgeType x,EdgeType y);
    void print_graph(MGraph g);
    VertexType get_vertex(MGraph g,EdgeType i);
    void BFStravel(MGraph g);
    void BFS(MGraph g,int v);
    void BFS_min_dis(MGraph g,int v);
    void DFStravel(MGraph g);
    void DFS(MGraph g,int v);
    bool istree(MGraph&g);
    void dfs(MGraph&g,int v,int &vum,int& enume,int visited[]);
};

class Graph_A{
public:
    void create_graph(AGraph& g);
    void Neighbors(AGraph g,VertexType x);
    bool Insertvertex(AGraph& g,VertexType x);
    bool Deletevertex(AGraph& g,VertexType x);
    bool Addedge(AGraph& g,EdgeType x,EdgeType y);
    bool Removedge(AGraph& g,EdgeType x,EdgeType y);
    EdgeType Firstneighbor(AGraph g,EdgeType x);
    EdgeType Nextneighbor(AGraph g,EdgeType x,EdgeType y);
    bool Adjacent(AGraph g,EdgeType x,EdgeType y);
    EdgeType get_edge(AGraph g,VertexType x);
    VertexType get_vex(AGraph g,EdgeType x);
    void print_graph(AGraph g);
    void convert_a_m(AGraph g,int arcs[MAXSIZE][MAXSIZE]);
    void dfs_no(AGraph g,EdgeType i,int visited[]);
    void dfs(AGraph g);
    int exist_path_dfs(AGraph g,EdgeType i,EdgeType j);
    int exist_path_bfs(AGraph g,EdgeType i,EdgeType j);
    void find(AGraph g,EdgeType u,EdgeType v,vector<int>path);
    void test();
    //int get_edge_value(AGraph g,EdgeType x,EdgeType y);
    //bool set_edge_value(AGraph g,EdgeType x,EdgeType y,int v);
};


#endif //T1_GRAPH_H
