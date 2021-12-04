#include <iostream>
#include <chrono>
#include <time.h>
#include <thread>

using namespace std;


int minDistance(int d[], int S[], int sz){
    int lowest = 999, min_index=0;
    for(int i=0; i<sz; i++){
        if(S[i] == 0 && d[i] <= lowest){
            lowest = d[i];
            min_index= i;
        }
    }
    return min_index;
}


int main()
{
    typedef chrono::high_resolution_clock Clock;
    struct timespec tstart={0, 0}, tend={0, 0};

    //clock_t t;

    int vertices, edges=0, vertex1, vertex2;
    cout << "Enter number of vertices: " << endl;
    cin >> vertices;
    int **adj_matrix = new int*[vertices], d[vertices], pi[vertices], S[vertices];
    for(int i=0; i<vertices; i++){
        adj_matrix[i] = new int[vertices];
    }

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            adj_matrix[i][j] = 0;
        }
        d[i] = 999;
        pi[i] = -1;
        S[i] = 0;
    }

    /*
    while(edges != -1){
        cout << "Enter 2 vertex and weight of edge (-1 to quit)" << endl;
        cin >> vertex1;
        if(vertex1 == -1){
            break;
        }
        cin >> vertex2;
        cin >> edges;

        // The vertex entered +1
        adj_matrix[vertex1-1][vertex2-1] = edges;
    }
    */

    /* AVERAGE CASE
    int edge = 13401998;
    while(edge > 0){
        int v1 = rand()%vertices;
        int v2 = rand()%vertices;
        if(v1 == v2 || adj_matrix[v1][v2] != 0){
            continue;
        }
        adj_matrix[v1][v2] = rand()%100+1;
        edge-=1;
    }
    */

    /*
    for(int i=0; i< vertices; i++){
        for(int j=0; j< vertices; j++){
            if(i != j){
                int val = rand()%100 + 1;
                adj_matrix[j][i] = val;
            }
        }
    }
    */


    // Print Adjacency Matrix
    /*
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices;j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << "" << endl;
    }
    */



    int source_node, temp;
    printf("Enter Source Node:\n");
    scanf("%d", &source_node);

    for(int edge=100; edge<1000 * 999; edge++){

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            adj_matrix[i][j] = 0;
        }
        d[i] = 999;
        pi[i] = -1;
        S[i] = 0;
    }

    int ek = edge;
    while(ek > 0){
        int v1 = rand()%vertices;
        int v2 = rand()%vertices;
        if(v1 == v2 || adj_matrix[v1][v2] != 0){
            continue;
        }
        adj_matrix[v1][v2] = rand()%100+1;
        ek-=1;
    }

    //auto start = chrono::high_resolution_clock::now();
    //t = clock();
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    //std::this_thread::sleep_for(std::chrono::milliseconds(1));

    d[source_node-1] = 0;
    pi[source_node-1] = source_node-1;


    // O(V^2)
    for(int cnt = 0; cnt < vertices; cnt++){
        int u = minDistance(d, S, vertices); // O(V)
        S[u] = 1; // O(1)

        for(int v=0; v<vertices; v++){ // O(V)
            if(S[v] == 0 && adj_matrix[u][v] > 0 && d[u] != 999 && d[u] + adj_matrix[u][v] < d[v]){
                d[v] = d[u] + adj_matrix[u][v];
                pi[v] = u;
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &tend);
    //auto finish = chrono::high_resolution_clock::now();
    //t = clock() - t;

    /*
    for(int i=0; i<vertices; i++){
        cout << i+1 << ": " << d[i] << endl;
    }
    */


    clock_gettime(CLOCK_MONOTONIC, &tend);
    printf("%.10f\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

    }
    //cout << "Time Taken: " << ((double)t)/CLOCKS_PER_SEC << endl;
    //cout << "Time taken: " << chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() - 1000 << endl;


    return 0;
}

void dijkstra(int adj_matrix[][], int d[], int S[]){
    while S has vertices with unfinalized distances:
        int u = minDistance(d, S, vertices);
        set u to be finalized;

        for each v adjacent to u:
            if(d[v] > d[u] + adj_matrix[u][v]){
                set d[v] = d[u] + adj_matrix[u][v]
            }
    return;
}

