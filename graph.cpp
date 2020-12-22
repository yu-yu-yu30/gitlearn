#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include<queue>
#include "graph.h"
using namespace std;

void Graph_M::create_graph(MGraph& g) {
    g.vexnum = 4;
    g.arcnum = 4;
    g.Vex[0] = 'a';
    g.Vex[1] = 'b';
    g.Vex[2] = 'c';
    g.Vex[3] = 'd';
    for (int i = 0; i < g.vexnum; i++) {
        for (int j = 0; j < g.vexnum; j++) {
            g.Edge[i][j] = 0;
        }
    }
    g.Edge[0][1] = 1;
    g.Edge[0][2] = 1;
    g.Edge[1][2] = 1;
    g.Edge[1][3] = 1;
    g.Edge[1][0] = 1;
    g.Edge[2][0] = 1;
    g.Edge[2][1] = 1;
    g.Edge[3][1] = 1;
//    cout<<"put in vexnum"<<endl;
//    cin>>g.vexnum;
//    cout<<"put in arcnum"<<endl;
//    cin>>g.arcnum;
//    for(int i = 0;i<g.vexnum;i++){
//        cout<<"input num "<<i<<" vertex"<<endl;
//        cin>>g.Vex[i];
//    }
//    for(int i = 0;i<g.arcnum;i++){
//        for(int j = 0;j<g.arcnum;j++){
//            g.Edge[i][j] = INT_MAX;
//        }
//    }
//    for(int i = 0;i<g.arcnum;i++){
//        int j,k,v;
//        cout<<"input arc and value"<<endl;
//        cin>>j>>k>>v;
//        g.Edge[j-1][k-1] = v;
//        g.Edge[k-1][j-1] = v;
//}
}

VertexType Graph_M::get_vertex(MGraph g, EdgeType i) {
    return g.Vex[i];
}

void Graph_M::print_graph(MGraph g) {
    for(int i = 0;i<g.vexnum;i++){
        for(int j = 0;j<=i;j++){
            if(g.Edge[i][j]!=0){
                cout<<Graph_M::get_vertex(g,i)<<"-->"<<Graph_M::get_vertex(g,j)<<endl;
            }
        }
    }
}

bool Graph_M::Adjacent(MGraph g, EdgeType x,EdgeType y) {
    if(g.Edge[x][y]!=0){
        return true;
    }
    return false;
}
bool Graph_M::Addedge(MGraph& g, EdgeType x, EdgeType y) {
    if(x<g.vexnum&&y<g.vexnum) {
        g.Edge[x][y] = 1;
        g.Edge[y][x] = 1;
        g.arcnum++;
        return true;
    }
    return false;
}
bool Graph_M::Removedge(MGraph& g, EdgeType x, EdgeType y) {
    if(x<g.vexnum&&y<g.vexnum) {
        g.Edge[x][y] = 0;
        g.Edge[y][x] = 0;
        g.arcnum--;
        return true;
    }
    return false;
}

bool Graph_M::Deletevertex(MGraph&g, VertexType x) {
    int i = 0;
    for( i = 0;i<g.vexnum;i++) {
        if (g.Vex[i] == x) {
            g.Vex[i] = ' ';
            //g.vexnum--;
            break;
        }
    }
    if(i>=g.vexnum) {
        return false;
    }
    for(int j = 0;j<g.vexnum;j++){
        if(g.Edge[i][j]!=0){
            g.Edge[i][j] = 0;
            g.Edge[j][i] = 0;
            g.arcnum--;
        }
        }
    return true;
}

bool Graph_M::Insertvertex(MGraph& g, VertexType x) {
    if(g.vexnum<MAXSIZE){
    g.Vex[g.vexnum] = x;
    g.vexnum++;
    return true;
    }
    return false;
}

EdgeType Graph_M::Firstneighbor(MGraph g, EdgeType x) {

    if(x<g.vexnum){
        for(int j = 0;j<g.vexnum;j++){
            if(g.Edge[x][j]!=0){
                return j;
            }

        }
    }
    return -1;

}

EdgeType Graph_M::Nextneighbor(MGraph g, EdgeType x, EdgeType y) {
    for(int j = y+1;j<g.vexnum;j++){
        if(g.Edge[x][j]){
            return j;
        }
    }
    return -1;
}

int Graph_M::get_edge_value(MGraph g, EdgeType x, EdgeType y) {
    return g.Edge[x][y];
}

bool Graph_M::set_edge_value(MGraph& g, EdgeType x, EdgeType y, int v) {
    if(x<g.vexnum&&y<g.vexnum){
        g.Edge[x][y] = v;
        return 1;
    }
    return 0;

}
vector<bool>visited;
void Graph_M::BFS(MGraph g, EdgeType v) {
    cout<<v<<' ';
    visited[v] = true;
    queue<EdgeType>que;
    que.push(v);
    while(!que.empty()) {
        v = que.front();
        que.pop();
        int i = Firstneighbor(g,v);
        while(i>=0) {
            if(!visited[i]){
                cout<<i<<' ';
                visited[i] = true;
                que.push(i);
            }
            i = Nextneighbor(g,v,i);
        }
    }

}
void Graph_M::BFStravel(MGraph g) {
    for(int i = 0;i<g.vexnum;i++){
        visited.push_back(false);
    }
    for(int i = 0;i<g.vexnum;i++){
        if(visited[i]==false){
            BFS(g,i);
        }
    }
    cout<<endl;

}

void Graph_M::BFS_min_dis(MGraph g, EdgeType v) {
    vector<bool> visited;
    vector<int>dis;
    queue<EdgeType> que;
    for(int i = 0;i<g.vexnum;i++){
        visited.push_back(false);
        dis.push_back(MAXSIZE);
    }
    dis[v] = 0;
    que.push(v);
    visited[v] = true;
    while(!que.empty()) {
        v = que.front();
        que.pop();
        for (int i = Firstneighbor(g, v); i >= 0; i = Nextneighbor(g, v, i)) {
            if(!visited[i]) {
                dis[i] = dis[v] + 1;
                visited[i] = true;
                que.push(i);
            }
        }
    }
    for(int i = 0;i<dis.size();i++){
        cout<<dis[i]<<' ';
    }

}

vector<bool>visit;
void Graph_M::DFStravel(MGraph g) {
    for(int i = 0;i<g.vexnum;i++){
        visit.push_back(false);
    }
    for(int i = 0;i<g.vexnum;i++){
        if (!visit[i]){
            DFS(g,i);
        }
    }
}

void Graph_M::DFS(MGraph g, int v) {
    visit[v] = true;
    cout<<v<<' ';
    for(int i = Firstneighbor(g,v);i>=0;i = Nextneighbor(g,v,i)){
        if(!visit[i]){
            DFS(g,i);
        }
    }

}

bool Graph_M::istree(MGraph &g) {
    int visited[MAXSIZE];
    for(int i = 0;i<g.vexnum;i++){
        visited[i] = false;
    }
    int enume = 0;
    int vum = 0;
    dfs(g,0,vum,enume,visited);
    if(vum==g.vexnum&&enume==2*(g.vexnum-1)){
        return true;
    }
    return false;
}

void Graph_M::dfs(MGraph &g, int v, int &vum, int &enume, int visited[]) {
    visited[v] = true;
    vum++;
    for(int i = Firstneighbor(g,v);i>=0;i = Nextneighbor(g,v,i)) {
        enume++;
        if (!visited[i]) {
            dfs(g, i, vum, enume, visited);
        }
    }
}

void Graph_A::create_graph(AGraph& g) {
    g.vexnum = 4;
    g.arcnum = 4;
    g.vertices[0].data = 'a';
    g.vertices[1].data = 'b';
    g.vertices[2].data = 'c';
    g.vertices[3].data = 'd';
    Arcnode *p = new Arcnode;
    Arcnode *q = new Arcnode;
    Arcnode *n = new Arcnode;
    Arcnode *r = new Arcnode;
    Arcnode *a = new Arcnode;
    Arcnode *b = new Arcnode;
    Arcnode *c = new Arcnode;
    Arcnode *d = new Arcnode;
    p->adjvex = 1;
    q->adjvex = 2;
    g.vertices[0].first = p;
    p->next = q;
    q->next = NULL;
    n->adjvex = 0;
    g.vertices[1].first = n;
    r->adjvex = 2;
    n->next = r;
    a->adjvex = 3;
    r->next = a;
    a->next = NULL;
    b->adjvex = 0;
    g.vertices[2].first = b;
    c->adjvex = 1;
    b->next = c;
    c->next = NULL;
    d->adjvex = 1;
    g.vertices[3].first = d;
    d->next = NULL;




//    cout<<"input vex num"<<endl;
//    cin>>g.vexnum;
//    cout<<"input arc num"<<endl;
//    cin>>g.arcnum;
//    for(int i = 0;i<g.vexnum;i++){
//        cout<<"input vex value"<<endl;
//        cin>>g.vertices[i].data;
//        g.vertices[i].first =NULL;
//    }
//    for(int j = 0;j<g.arcnum;j++){
//        VertexType x,y;
//        Arcnode *c = new Arcnode;
//        Arcnode*d = new Arcnode;
//        int p,q;
//        cout<<"input vetex values"<<endl;
//        cin>>x>>y;
//        p = Graph_A::get_edge(g,x);
//        q = Graph_A::get_edge(g,y);
//        if(p!=-1&&q!=-1){
//            c->adjvex = q;
//            c->next = g.vertices[p].first;
//            g.vertices[p].first = c;
//            d->adjvex = p;
//            d->next = g.vertices[q].first;
//            g.vertices[q].first = d;
//        }
//    }
}



EdgeType Graph_A::get_edge(AGraph g, VertexType x) {
    for(int i = 0;i<g.vexnum;i++){
        if(g.vertices[i].data==x){
            return i;
        }
    }
    return -1;
}

VertexType Graph_A::get_vex(AGraph g, EdgeType x) {
    if(x<g.arcnum){
        return g.vertices[x].data;
    }
    return ' ';


}


void Graph_A::print_graph(AGraph g) {
    char a;
    Arcnode*p;
    vector<bool>visited;
    for (int i = 0;i<g.vexnum;i++){
        visited.push_back(false);
    }
    for(int i = 0;i<g.vexnum;i++){
        a = g.vertices[i].data;
        visited[a] = true;
        p =g.vertices[i].first;
        while(p!=NULL){
            if(!visited[p->adjvex]){
                visited[p->adjvex] = true;
            cout<<a<<"-->"<<Graph_A::get_vex(g,p->adjvex)<<endl;}
            p = p->next;
        }
    }
}

bool Graph_A::Adjacent(AGraph g, EdgeType x,EdgeType y){
    char a,b;
    Arcnode*p;
    a = Graph_A::get_vex(g,x);
    b = Graph_A::get_vex(g,y);
    for(int i = 0;i<g.vexnum;i++){
        if(g.vertices[i].data==a){
            p = g.vertices[i].first;
            while(p){
                if(p->adjvex==y){
                    return true;
                }
                p = p->next;
            }
        }
        if(g.vertices[i].data==b){
            p = g.vertices[i].first;
            while(p){
                if(p->adjvex==x){
                    return true;
                }
                p = p->next;
            }
        }
    }
    return false;
}

EdgeType Graph_A::Firstneighbor(AGraph g, EdgeType x) {
    Arcnode*p;
    p = g.vertices[x].first;
        if(p!=NULL){
            return p->adjvex;
        }
    return -1;
}

EdgeType Graph_A::Nextneighbor(AGraph g, EdgeType x, EdgeType y) {
    Arcnode*p = g.vertices[x].first;
    while(p!=NULL){
        if(p->adjvex==y){
            if(p->next!=NULL){
                return p->next->adjvex;
            } else{
                return -1;
            }
        }
        p = p->next;
    }
    return -1;
}

void Graph_A::Neighbors(AGraph g, VertexType x) {
    Arcnode*p = g.vertices[x].first;
    while(p){
        cout<<Graph_A::get_vex(g,x)<<"-->"<<Graph_A::get_vex(g,p->adjvex)<<endl;
        p = p->next;
    }

}

bool Graph_A::Insertvertex(AGraph& g, VertexType x) {
    if(g.vexnum<MAXSIZE) {
        g.vertices[g.vexnum].data = x;
        g.vexnum++;
        return true;
    }
    return false;
}


bool Graph_A::Deletevertex(AGraph &g, VertexType x) {
    if(Graph_A::get_edge(g,x)!=-1){
        int edge_num = get_edge(g,x);
        g.vertices[edge_num].data = ' ';
        g.vertices[edge_num].first = NULL;

        return true;
    }
    return false;
}

bool Graph_A::Removedge(AGraph& g, EdgeType x, EdgeType y) {
    int flag = 0;
    Arcnode*p,*q;
    p=g.vertices[x].first;
    q = p->next;
    if(g.vertices[x].first->adjvex==y){
        g.vertices[x].first = q;
        flag = 1;
    }
    while(q){
        if(q->adjvex==y){
            p->next =q->next;
            flag = 1;
            break;
        }
        p = q;
        q = q->next;
    }
    p=g.vertices[y].first;
    q = p->next;
    if(g.vertices[y].first->adjvex==x){
        g.vertices[y].first = q;
        flag = 1;
    }
    while(q){
        if(q->adjvex==x){
            p->next =q->next;
            flag = 1;
            break;
        }
        p = q;
        q = q->next;
    }
    if(flag==0){
        return false;
    }
    return true;
}


bool Graph_A::Addedge(AGraph& g, EdgeType x, EdgeType y) {
    if(x>=g.vexnum||y>=g.vexnum){
        return false;
    }
    Arcnode *p;
    p = g.vertices[x].first;
    if(p==NULL){
        p = new Arcnode;
        p->adjvex = y;
    }
    else {
        while (p->next != NULL) {
            if(p->adjvex==y){
                return false;
            }
            p = p->next;
        }
        Arcnode*q = new Arcnode;
        q->adjvex = y;
        p->next = q;
        q->next = NULL;
    }
    p = g.vertices[y].first;
    if(p==NULL){
        p = new Arcnode;
        p->adjvex = x;
    }
    else {
        while (p->next != NULL) {
            p = p->next;
            if(p->adjvex==x){
                return false;
            }
        }
        Arcnode*q = new Arcnode;
        q->adjvex = x;
        p->next = q;
        q->next = NULL;
    }
    return true;
}

void Graph_A::convert_a_m(AGraph g, int arcs[100][100]) {
    Arcnode*p;
    for (int i = 0;i<g.vexnum;i++){
        p = g.vertices[i].first;
        while(p!=NULL){
            arcs[i][p->adjvex] = 1;
            arcs[p->adjvex][i] = 1;
            p = p->next;
        }
    }
}
void Graph_A::dfs(AGraph g) {
    int visited[MAXSIZE];
    for(int i = 0;i<g.vexnum;i++){
        visited[i] = 0;
    }
    for(int i = 0;i<g.vexnum;i++){
        if(!visited[i]) {
            dfs_no(g, i,visited);
        }
    }

}
void Graph_A::dfs_no(AGraph g, EdgeType i,int visited[]) {
    stack<EdgeType> temp_stack;
    visited[i] = 1;
    temp_stack.push(i);
    while(!temp_stack.empty()){
        i = temp_stack.top();
        temp_stack.pop();
        cout<<i<<' ';
        for(int v = Firstneighbor(g,i);v>=0;v = Nextneighbor(g,i,v)) {
        if(!visited[v]){
            temp_stack.push(v);
            visited[v] = 1;
        }
    }
    }
}

int visite[MAXSIZE] = {0};
int Graph_A::exist_path_dfs(AGraph g,EdgeType i,EdgeType j)
{
    if(i==j){
        return 1;
    }
    else{
        visite[i] = 1;
        int p = Firstneighbor(g,i);
        while(p!=-1)
        {
            if(!visite[p]&&exist_path_dfs(g,p,j)==1){
                return 1;
            }
            p = Nextneighbor(g,i,p);
        }
    }
    return 0;
}


int Graph_A::exist_path_bfs(AGraph g,EdgeType i,EdgeType j){
    stack<EdgeType>temp_stack;
    Arcnode*q;
    vector<bool>visited;
    for(int i = 0;i<g.vexnum;i++){
        visited.push_back(false);
    }
    temp_stack.push(i);
    q = g.vertices[i].first;
    while(!temp_stack.empty()){
        int i = temp_stack.top();
        temp_stack.pop();
        visited[i] = 1;
        for(int p = Firstneighbor(g,i);p>=0;p = Nextneighbor(g,i,p)){
            if(!visited[p]&&p==j){
                return true;
            }
            if(!visited[p]){
                temp_stack.push(p);
            }

        }

    }
    return 0;
}
int visits[MAXSIZE];
void Graph_A::find(AGraph g, EdgeType u, EdgeType v, vector<int>path) {
    int w,i;
    Arcnode*p;
    path.push_back(u);
    visits[u] = 1;
    if(u==v){
        for(int i = 0;i<path.size();i++){
            cout<<path[i]<<' ';
        }
        cout<<endl;
    }
    p = g.vertices[u].first;
    while(p!=NULL){
        w = p->adjvex;
        if(visits[w]==0){
            find(g,w,v,path);
        }
        p = p->next;
    }
    visits[u] =  0;
}

int main(){
    MGraph g;
    Graph_M m;
    m.create_graph(g);
    //m.print_graph(g);
    cout<<endl;
    m.Removedge(g,0,1);
    m.BFStravel(g);
    m.BFS_min_dis(g,3);
    m.DFStravel(g);
    cout<<endl;
    cout<<m.istree(g)<<endl;
    //m.Deletevertex(g,'a');
    //m.print_graph(g);
    //cout<<m.Firstneighbor(g,'a')<<endl;
    AGraph p;
    Graph_A a;
    a.create_graph(p);
    //a.Removedge(p,0,1);
    a.print_graph(p);
    //a.Removedge(p,1,2);

    a.dfs(p);
    //cout<<a.exist_path_dfs(p,0,3)<<endl;
    //cout<<a.exist_path_bfs(p,0,3)<<endl;
    cout<<endl;
    vector<int>path;
    a.find(p,1,3,path);
//    int arcs[MAXSIZE][MAXSIZE];
//    a.convert_a_m(p,arcs);
//    for(int i = 0;i<p.vexnum;i++){
//        for(int j = 0;j<=i;j++){
//            if(arcs[i][j]!=0){
//                cout<<i<<' '<<j<<endl;
//            }
//        }
//    }
//    a.print_graph(p);
//    a.Addedge(p, 2,3);
//    //a.Deletevertex(p,'a');
//    a.Removedge(p,1,2);
//    a.print_graph(p);
//    cout<<a.Firstneighbor(p,'a');
    return 0;
}