#include <iostream>
using namespace std;

void Creat_graph();


int main()
{
   
    Creat_graph();
    
    return 0;
}

void Creat_graph()
{
    int v, mexEdge, source, destination;
    cout<<"Enter number of vertices: ";
    cin>>v;

    mexEdge = v*(v-1);

    int adj [v][v] = {0};


    int edge;
    for (edge = 0; edge < mexEdge; edge++){
        cout<<"Enter edge "<<edge<<" (source, destination) [-1 -1 to stop]: ";
        cin>>source>>destination;

        if (source == -1 && destination == -1)
            break;

        if (source < 0 || source >= v || destination < 0 || destination >= v){
            cout<<"Invalid edge. Please try again"<<endl;
            edge--;
        }

        adj [source] [destination] = 1;
    }
    
    int row, col;

    for (row = 0; row < v; row++){
        for (col = 0; col < v; col++){
            cout<<adj [row][col]<<" ";
        }
        cout<<endl;
    }
}