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


//BFS������
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
    //ÿ������ı��Ϊ��ʼ��Ϊfalse
    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;
    }
    Node* q=NULL;
    //����ÿ��������Ϊ��ʼ�㣬�����������������
    for (int v=1; v<=G.VerNum; v++) {
        //����ö���ı��λΪfalse��֤��δ���ʹ�
        if (!(visited[v])) {
            //�½�һ����㣬��ʾ�ö���
            Node* p=new Node;
            p->data=G.Data[v];
            p->firstChild=NULL;
            p->nextSibling=NULL;
            //�����Ϊ�գ���ö�����Ϊ��������
            if (!(T)) {
                (T)=p;
            }
            //�ö�����Ϊ�������ֵܽ��
            else{
                q->nextSibling=p;
            }
            //ÿ�ζ�Ҫ��qָ��ָ���µĽ�㣬Ϊ�´���ӽ�����̵�
            q=p;
            //�Ըý��Ϊ��ʼ�㣬�����������������
            BFSTree(G,p,G.Data[v]);
        }
    }
}


//__________________________________________________________________________________________________DFST
void DFSTree(Graph& G,int v,Node *&T){
    //�����ڷ��ʵĸö���ı�־λ��Ϊtrue
    bool first=true;
    Node* q=NULL;
    visit(G,v);
    //���α����ö���������ڽӵ�
    for (int w=firstAdj(G, v); w!=0; w=nextAdj(G, v, w)) {
        //������ٽ���־λΪfalse��˵����δ����
        if (!visited[w]) {
            //Ϊ���ڽӵ��ʼ��Ϊ���
            Node* p=new Node;
            p->data=G.Data[w];
            p->firstChild=NULL;
            p->nextSibling=NULL;
            
            //�ý��ĵ�һ���ڽӵ���Ϊ���ӽ�㣬�����ڽӵ���Ϊ���ӽ����ֵܽ��
            if (first) {
                T->firstChild=p;
                first=false;
            }
            //����Ϊ�ֵܽ��
            else{
                q->nextSibling=p;
            }
            q=p;
            //�Ե�ǰ���ʵĶ���Ϊ�����������������ڽӵ�
            DFSTree(G,w,q);
        }
    }
}

//���������������ɭ�ֲ�ת��Ϊ������
void DFSForests(Graph& G,Node *&T){
    T=NULL;
    //ÿ������ı��Ϊ��ʼ��Ϊfalse
    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;
    }
    Node* q=NULL;
    //����ÿ��������Ϊ��ʼ�㣬�����������������
    for (int v=1; v<=G.VerNum; v++) {
        //����ö���ı��λΪfalse��֤��δ���ʹ�
        if (!(visited[v])) {
            //�½�һ����㣬��ʾ�ö���
            Node* p=new Node;
            p->data=G.Data[v];
            p->firstChild=NULL;
            p->nextSibling=NULL;
            //�����Ϊ�գ���ö�����Ϊ��������
            if (!(T)) {
                (T)=p;
            }
            //�ö�����Ϊ�������ֵܽ��
            else{
                q->nextSibling=p;
            }
            //ÿ�ζ�Ҫ��qָ��ָ���µĽ�㣬Ϊ�´���ӽ�����̵�
            q=p;
            //�Ըý��Ϊ��ʼ�㣬�����������������
            DFSTree(G,v,p);
        }
    }
}

//ǰ�����������
void PreOrderTraverse(Node* T){
    if (T) {
        printf("%c\t",T->data);
        PreOrderTraverse(T->firstChild);
        PreOrderTraverse(T->nextSibling);
    }
    return;
}
//����ķ�㷨
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
        for (int  n = 1; n <= G.VerNum; n++)//�ҵ�δ���ʵ㵽��֪�����Сֵ
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
//Kruskal�㷨
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
    int least = INF;//��С��
    for ( edge = 0; edge < G.VerNum-1; edge++)//�ҵ�n-1���߽���
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
//Floyd�㷨
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
//��������
void Top(Graph& G)
{
    int dgree[100];//����
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
        for (int j = 1; j <= G.VerNum; j++)//�ҵ���Ϊ0�ĵ�
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

//����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
//AOE���ؼ�·��
void AOE(Graph& G)
{
    int dgree[100];//�������
    int dest[100];//����·��
    int parent[100];//���游�׽��
    int n = 1;
    int temp;
    int max = 0,m;//��Ǹ��ڵ�
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
            cout<<"ִ��"<<G.Data[i]<<"\t"<<endl;
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
                    
                     cout<<G.Data[parent[w]]<<"����֮��"<<"    ִ��"<<G.Data[w]<<"\t"<<dest[w]<<endl;
                    visit(G,w);
                    q.push(w);
                }
                
            }
        }
    }
    
}