
#include"grpAdjMatrix.h"
#include"createGrpAdjMatrix.h" 
#include"MartixGraph.h"
int main()
{
    int p;
    Node* T = new Node;
    init(T);
    //1  2
    char filename1[] = "./data/udg8.grp";
    char filename2[] = "./data/udg115.grp";
    //3 4
    char filename3[] = "./data/udg8.grp";
    char filename4[] = "./data/dg6.grp";
    //5 6 7 8
    char filename5[] = "./data/udn6.grp";
    char filename6[] = "./data/dn8.grp";
    //9 10
    char filename7[] = "./data/top6dg1.grp";
    char filename8[] = "./data/top7dg1.grp";
    //11
    char filename9[] = "./data/dn10.grp";
    Graph G;
    
    while (1)
    {
        printf("**************************************************\n");
        cout<<"邻接矩阵"<<endl;
        printf("1深度优先搜索\n");
        printf("2广度优先搜索\n");
        printf("3图的边数\n");
        printf("4构造深度优先搜索生成树\n");
        printf("5构造广度优先搜索生成树\n");
        printf("6prime算法\n");
        printf("7kruska算法\n");
        printf("8dijsktra算法\n");
        printf("9floyd算法\n");
        printf("10拓扑序列\n");
        printf("11查找AOE关键路径\n");
        printf("**************************************************\n");
        cout<<"请输入选项"<<endl;
        cin>>p;
        switch (p)
        {
        case 1:
            CreateGraphFromFile(filename1,G);
            printGraph(G);
            DFS(G);
            break;
        
        case 2:
            CreateGraphFromFile(filename2,G);
            printGraph(G);
            BFS(G);
            break;
        
        case 3:
            CreateGraphFromFile(filename4,G);
            printGraph(G);
            cout<<NumOfEdge(G);
            break;

        case 4:
            CreateGraphFromFile(filename4,G);
            printGraph(G);
            DFSForests(G,T);
            printf("\n");
            cout<<"先序遍历DFS生成树"<<endl;
            PreOrderTraverse(T);
            printf("\n");
            break;

        case 5:
            CreateGraphFromFile(filename4,G);
            printGraph(G);
            BFSForests(G,T);
            printf("\n");
            cout<<"先序遍历BFS生成树"<<endl;
            PreOrderTraverse(T);
            printf("\n");
            break;

        case 6:
            CreateGraphFromFile(filename5,G);
            printGraph(G);
            Prime(G,1);
            break;

        case 7:
            CreateGraphFromFile(filename5,G);
            printGraph(G);
            Krusal(G);
            break;

        case 8:
            CreateGraphFromFile(filename6,G);
            printGraph(G);
            Dijkstra(G,1);
            break;

        case 9:
            CreateGraphFromFile(filename6,G);
            printGraph(G);
            Floyd(G,1);
            break;
        case 10:
            CreateGraphFromFile(filename7,G);
            printGraph(G);
            Top(G);
            cout<<endl;
            break;

        case 11:
            CreateGraphFromFile(filename9,G);
            printGraph(G);
            AOE(G);
            break;
        default:
            break;
        }
    }
    
    return 0;
}
