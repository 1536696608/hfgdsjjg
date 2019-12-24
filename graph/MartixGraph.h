#include"grpAdjMatrix.h"
//1
int DFST(Graph &G,elementType vertex)
{
    int loc = LocateVertex(G,vertex);
    if(!visited[loc])
    {
        
        visit(G,loc);
        int w = firstAdj(G,loc);
        while (w != 0)
        {
            // cout<<G.Data[w]<<endl;
            DFST(G,G.Data[w]);
            w = nextAdj(G,loc,w);
        }
        
    }
    return 1;
}

void DFS(Graph &G)
{
    for (int i = 1; i <= G.VerNum; i++)
    {
        visited[i] = false;
    }
    
     for (int i = 1; i <= G.VerNum; i++)
    {
        if(!visited[i])
        {
            DFST(G,G.Data[i]);
        }
    }
}
void BFST(Graph &G,elementType vertex)
{
    queue <int> q;
    int w,n;
    int loc = LocateVertex(G,vertex);
    visit(G,loc);
    q.push(loc);
    
    while (!q.empty())
    {
        w = q.front();
        //cout<<G.Data[w]<<"1"<<"\t";
        q.pop();
        n = firstAdj(G,w);
        //cout<<G.Data[n]<<"2"<<"\t";
        while (n != 0)
        {
            if(!visited[n])
            {
               
                visit(G,n);
                q.push(n);
               // cout<<G.Data[w]<<"\n";
            }
            n = nextAdj(G,w,n);
        }
        
    }
    
}

void BFS(Graph &G)
{
    for (int i = 1; i <= G.VerNum; i++)
    {
        visited[i] = false;
    }
    
     for (int i = 1; i <= G.VerNum; i++)
    {
        if(!visited[i])
        {
            BFST(G,G.Data[i]);
        }
    }
}
//2
int NumOfEdge(Graph &G)
{
    int edge = 0;
    int i,j;
    return G.ArcNum;
}

//3
void init(Node *&T)
{
    T->firstChild = T->nextSibling = NULL;
}


//BFS生成树
void BFSTree(Graph &G,Node*& Trees,elementType vertex)
{
    Node* temp;
    int w,m;
    bool first = true;
    queue <int> q;
    int loc = LocateVertex(G,vertex);
    q.push(loc);
    visit(G,loc);
    temp = Trees;
    while (!q.empty())
    {
        
        m = q.front();
        q.pop();
        w = firstAdj(G,m);
        first = true;
        while(w != 0)
        {
            if(!visited[w])
            {
                visit(G,w);
                q.push(w);
                Node* T = new Node;
                init(T);
                T->data = G.Data[w];
                if (first)
                {
                    temp->firstChild = T;
                    first = false;
                }
                else
                {
                    temp->nextSibling = T;
                }
                temp = T;
            }
            w = nextAdj(G,m,w);
            //cout<<w<<"hhh"<<endl;
        }
        
    }
    
}

void BFSForests(Graph& G,Node *&T){
    T=NULL;
    //每个顶点的标记为初始化为false
    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;
    }
    Node* q=NULL;
    //遍历每个顶点作为初始点，建立深度优先生成树
    for (int v=1; v<=G.VerNum; v++) {
        //如果该顶点的标记位为false，证明未访问过
        if (!(visited[v])) {
            //新建一个结点，表示该顶点
            Node* p=new Node;
            p->data=G.Data[v];
            p->firstChild=NULL;
            p->nextSibling=NULL;
            //如果树为空，则该顶点作为树的树根
            if (!(T)) {
                (T)=p;
            }
            //该顶点作为树根的兄弟结点
            else{
                q->nextSibling=p;
            }
            //每次都要把q指针指向新的结点，为下次添加结点做铺垫
            q=p;
            //以该结点为起始点，构建深度优先生成树
            BFSTree(G,p,G.Data[v]);
        }
    }
}


//__________________________________________________________________________________________________DFST
void DFSTree(Graph& G,int v,Node *&T){
    //将正在访问的该顶点的标志位设为true
    bool first=true;
    Node* q=NULL;
    visit(G,v);
    //依次遍历该顶点的所有邻接点
    for (int w=firstAdj(G, v); w!=0; w=nextAdj(G, v, w)) {
        //如果该临界点标志位为false，说明还未访问
        if (!visited[w]) {
            //为该邻接点初始化为结点
            Node* p=new Node;
            p->data=G.Data[w];
            p->firstChild=NULL;
            p->nextSibling=NULL;
            
            //该结点的第一个邻接点作为孩子结点，其它邻接点作为孩子结点的兄弟结点
            if (first) {
                T->firstChild=p;
                first=false;
            }
            //否则，为兄弟结点
            else{
                q->nextSibling=p;
            }
            q=p;
            //以当前访问的顶点为树根，继续访问其邻接点
            DFSTree(G,w,q);
        }
    }
}

//深度优先搜索生成森林并转化为二叉树
void DFSForests(Graph& G,Node *&T){
    T=NULL;
    //每个顶点的标记为初始化为false
    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;
    }
    Node* q=NULL;
    //遍历每个顶点作为初始点，建立深度优先生成树
    for (int v=1; v<=G.VerNum; v++) {
        //如果该顶点的标记位为false，证明未访问过
        if (!(visited[v])) {
            //新建一个结点，表示该顶点
            Node* p=new Node;
            p->data=G.Data[v];
            p->firstChild=NULL;
            p->nextSibling=NULL;
            //如果树为空，则该顶点作为树的树根
            if (!(T)) {
                (T)=p;
            }
            //该顶点作为树根的兄弟结点
            else{
                q->nextSibling=p;
            }
            //每次都要把q指针指向新的结点，为下次添加结点做铺垫
            q=p;
            //以该结点为起始点，构建深度优先生成树
            DFSTree(G,v,p);
        }
    }
}

//前序遍历二叉树
void PreOrderTraverse(Node* T){
    if (T) {
        printf("%c\t",T->data);
        PreOrderTraverse(T->firstChild);
        PreOrderTraverse(T->nextSibling);
    }
    return;
}
//普莱姆算法
void Prime(Graph& G,int least)
{
    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;
    }
    int temp;
    int power[100];
    int parent[100];
    int i;
    for (i = 1; i <= G.VerNum; i++)
    {
        power[i] = INF;
    }
    for (i = 1; i <= G.VerNum; i++)
    {
        parent[i] = INF;
    }
    i = 1;
    //int least = LocateVertex(G,vertex);
    power[least] = 0;
    parent[least] = 0;
    // for (int w = firstAdj(G,least); w != 0;w = nextAdj(G,least,w))
    //     {
    //         if(power[w] > G.AdjMatrix[least][w])
    //         {
    //             power[w] = G.AdjMatrix[least][w];
    //             parent[w] = least;
    //         }
    //     }
    visit(G,least);
    cout<<"first:"<<least<<"-------"<<endl;
    while (i < G.VerNum)
    {
        
        for (int w = firstAdj(G,least); w != 0;w = nextAdj(G,least,w))
        {
            if(power[w] > G.AdjMatrix[least][w]&&!visited[w])
            {
                power[w] = G.AdjMatrix[least][w];
                parent[w] = least;
            }
        }
        for (int  n = 1; n <= G.VerNum; n++)//找到未访问点到已知点的最小值
        {
            if(!visited[n])
            {
                least = n;
                if(power[least] > power[n])
                {
                    least = n;
                }
            }
        }
        visit(G,least);
        cout<<parent[least]<<"-->"<<least<<"  power is : "<<power[least]<<endl;
        i++;
    }
}

//________________________________________________________________________________________________-
//Kruskal算法
void Krusal(Graph &G)
{
    bool visitEdge[100];
    for (int i = 1;i <= G.VerNum; i++)
    {
        visitEdge[i] = false;
        visited[i] = false;
    }
    
    int l,r;
    int m,n;
    int edge;
    int least = INF;//最小边
    for ( edge = 0; edge < G.VerNum-1; edge++)//找到n-1条边结束
    {
        least = INF;
        for ( r = 1; r <= G.VerNum;r++)
        {
            for(l = 1; l <= G.VerNum;l++)
            {
                if(G.AdjMatrix[r][l]!=0)
                {
                    if(!(visited[r]&&visited[l]))
                    {
                        if(least > G.AdjMatrix[r][l])
                        {
                            //cout<<r<<"++++"<<l<<endl;
                            least = G.AdjMatrix[r][l];
                            m = r;
                            n = l;
                        }
                    }
                }
            }
        }
        visit(G,m);
        visit(G,n);
        cout<<m<<"-->"<<n<<"   power is :"<<G.AdjMatrix[m][n]<<endl;
        
    }
    
}

//________________________________________________________________________________________________________________
//dijkstra
void Dijkstra(Graph G,elementType vertex)
{
    //int loc = LocateVertex(G,vertex);
    int loc = 1;
    int i,j;
    int dist[100];
    int parent[100];
    int min = INF;
    int m;
    queue <int> q;
    for (i = 1; i <= G.VerNum; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    for (i = 1; i <= G.VerNum; i++)
    {
        parent[i] = -1;
    }
    dist[loc] = 0;
    q.push(loc);
    visit(G,loc);
    while (!q.empty())
    {
        min = INF;
        int temp = q.front();
        q.pop();
        for (int w = firstAdj(G,temp); w != 0;w = nextAdj(G,temp,w))
        {
            if(!visited[w])
            {
                if(dist[w] > dist[temp] + G.AdjMatrix[temp][w])
                {
                    dist[w] = dist[temp] + G.AdjMatrix[temp][w];
                    parent[w] = temp;
                    if(min > dist[w])
                    {
                        min = dist[w];
                        m = w;
                    }
                }
            }
        }
        if(!visited[m])
        {
            q.push(m);
            visit(G,m);
        }
        
    }

    for(i = 1;i <= G.VerNum;i++)
    {
        j = i;
        int son = j;
        // while (parent[j] != -1)
        // {
        //     cout<<parent[j]<<"--->"<<j<<"\t";
        //     j = parent[j];
            
        // }
        while (son != loc&&son != -1)
        {
            cout<<son<<"<--"<<parent[son]<<"\t";
            son = parent[son];
        }
        cout<<"result:"<<endl;
        cout<<loc<<"-->"<<i<<"="<<dist[i]<<endl;
    }
    
    
}


//_______________________________________________________________________________________________
//Floyd算法
void Floyd(Graph& G,elementType vertex)
{
    // int loc = LocateVertex(G,vertex);
    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;
    }
    int loc = 1;
    int Edge[100][100];
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            Edge[i][j] = G.AdjMatrix[i][j];
            if (i == j)
            {
                Edge[i][j] = 0;
            }
            
        }
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            for (int k = 1; k <= G.VerNum; k++)
            {
                if((Edge[j][k] > Edge[j][i] + Edge[i][k]))
                {
                    Edge[j][k] = Edge[j][i] + Edge[i][k];
                }
            }
        }
    
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            if(1)
            {
                cout<<i<<"-->"<<j<<"\t"<<Edge[i][j]<<endl;
            }
        }
    }
    
    
}

//____________________________________________________________________________________________________________________
//拓扑序列
void Top(Graph& G)
{
    int dgree[100];//度数
    int n = 1;
    int temp;
    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        dgree[i] = 0;
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            if(G.AdjMatrix[j][i] != 0)
            {
                dgree[i]++;
            }
        }
    }
    while (n <= G.VerNum)
    {
        for (int j = 1; j <= G.VerNum; j++)//找到度为0的点
        {
            if(!visited[j]&&dgree[j] == 0)
            {
                temp = j;
            }
        }
        visit(G,temp);
        for (int w = firstAdj(G,temp); w != 0; w = nextAdj(G,temp,w))
        {
            if (!visited[w])
            {
                dgree[w]--;
            }
            
        }
        n++;
    }
    
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//AOE网关键路径
void AOE(Graph& G)
{
    int dgree[100];//保存度数
    int dest[100];//保存路径
    int parent[100];//保存父亲结点
    int n = 1;
    int temp;
    int max = 0,m;//标记父节点
    queue <int> q;
    for (int i = 1; i <= G.VerNum; i++)
    {
        dgree[i] = 0;
        dest[i] = 0;
        parent[i] = -1;
        visited[i] = false;
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            if(G.AdjMatrix[j][i] != INF)
            {
                dgree[i]++;
            }
        }
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        if(dgree[i] == 0)
        {
            q.push(i);
            dest[i] = 0;
            visit(G,i);
            cout<<"执行"<<G.Data[i]<<"\t"<<endl;
        }
    }
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int w = firstAdj(G,temp);w!=0;w = nextAdj(G,temp,w))
        {
            if(!visited[w])
            {
                if(dest[w] < dest[temp] + G.AdjMatrix[temp][w]&&G.AdjMatrix[temp][w]!=INF)
                {

                    dest[w] = dest[temp] + G.AdjMatrix[temp][w];
                    parent[w] = temp;
                }
                dgree[w]--;
                if (dgree[w] == 0)
                {
                    
                     cout<<G.Data[parent[w]]<<"结束之后"<<"    执行"<<G.Data[w]<<"\t"<<dest[w]<<endl;
                    visit(G,w);
                    q.push(w);
                }
                
            }
        }
    }
    
}