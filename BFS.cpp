#include <iostream>
using namespace std;

#define white 1
#define gray 2
#define black 3
#define nil -1
#define inf 1000

int vertex, rear = -1, front = 0;
int G [100][100], color[100], pprev[100], d[100], queue[100];

void Creat_graph();
void BFS();
void printPath(int s, int v);
void printBFStable ();

void Enqueue(int vertex);
int Dequeue();
bool isEmptyQueue();

int main()
{
   
    Creat_graph();
    BFS();
    
    return 0;
}

void Creat_graph()
{
    int mexEdge, source, destination;
    cout<<"Enter number of vertices: ";
    cin>>vertex;

    mexEdge = vertex*(vertex-1);


    int edge;
    for (edge = 0; edge < mexEdge; edge++){
        cout<<"Enter edge "<<edge<<" (source, destination) [-1 -1 to stop]: ";
        cin>>source>>destination;

        if (source == -1 && destination == -1)
            break;

        if (source < 0 || source >= vertex || destination < 0 || destination >= vertex){
            cout<<"Invalid edge. Please try again"<<endl;
            edge--;
        }

        G [source] [destination] = 1;
    }
    
    // int row, col;

    // for (row = 0; row < vertex; row++){
    //     for (col = 0; col < vertex; col++){
    //         cout<<G [row][col]<<" ";
    //     }
    //     cout<<endl;
    //}
}

void BFS()
{
    int u, v, s;

    for (u = 0; u < vertex; u++){
        color[u] = white;
        pprev[u] = nil;
        d[u] = inf;
    }
    
    cout<<"\nEnter sourec vertex for BFS: ";
    cin>>s;

    color[s] = gray;
    d[s] = 0;
    pprev[s] = nil;
    Enqueue(s);

    while (!isEmptyQueue()){
        u = Dequeue();

        for (v = 0; v < vertex; v++){
            if (G[u][v] == 1 && color[v] == white){
                color[v] = gray;
                d[v] = d[u]+1;
                pprev[v] = u;
                Enqueue(v);
            }
        }
        color[u] = black;
    }

    // void printBFStable ();
    
    cout<<"\nEnter Destination vertex for BFS: ";
    cin>>v;

    cout<<"\nThe path from vertex "<<s<<" to vertex "<<v<<" is: ";
    printPath(s, v);

    cout<<"\n\n";
}

void Enqueue(int vertex)
{
    if (rear == 100-1)
        cout<<"\nQueue is Full. There limit of queue\n";
    else{
        rear += 1;
        queue[rear] = vertex;
    }
}

int Dequeue()
{
    int deleteV;
    
    if (front > rear){
        cout<<"\nThere's no vertex. Queue is Empty\n";
        exit(1);
    }

    deleteV = queue[front];
    front += 1;

    return deleteV;
}

bool isEmptyQueue()
{
    if (front > rear)
        return true;
    else 
        return false;
}

void printPath(int s, int v)
{
    if (v == s)
        cout<<s<<" ";
    else if (pprev[v] == nil)
        cout<<"No path\n";
    else{
        printPath(s, pprev[v]);
        cout<<v<<" ";
    }
}

void printBFStable ()
{

}