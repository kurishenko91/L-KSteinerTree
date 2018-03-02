#include <iostream>
#include <fstream>

using namespace std;

//#define DEBUG

int N, E, T;
int **G;
int *Ts;

const int inf = INT_MAX;

void readFile(char *name)
{
    ifstream input;

    input.open(name);

    string line;
    bool eof = false;
    getline(input, line);
    #ifdef DEBUG
    if (line == "SECTION Graph") {
        cout << "OK";
    }
    else
        cout << "FAILED BEGIN OF GRAPH";
    #endif

    //now expect Nodes #nodes
    char c;
    for (int i = 0; i < 5; i++)
        input >> c;
    input >> N;

    //now expect Edges #edges
    for (int i = 0; i < 5; i++)
        input >> c;
    input >> E;

    G = new int*[N];
    for (int i = 0; i < N; i++)
        G[i] = new int[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        if (i == j)
            G[i][j] = 0;
        else
            G[i][j] = inf;
    }



    int a, b, w;
    for (int i = 0; i < E; i++) {
        input >> c;
        input >> a >> b >> w;
        G[a - 1][b - 1] = w;
        G[b - 1][a - 1] = w;
    }

    #ifdef DEBUG
    cout << endl << N << " " << E << " " << a << " " << b << " " <<  w << endl;
    #endif

    //now expect END
    getline(input, line);
    getline(input, line);
    #ifdef DEBUG
    if (line == "END") {
        cout << "OK";
    }
    else
        cout << line << " " << "FAILED END AFTER GRAPH";
    #endif

    //now expect empty line
    getline(input, line);
    #ifdef DEBUG
    if (line == "") {
        cout << "OK";
    }
    else
        cout << "FAILED EMPTY LINE AFTER END OF GRAPH";
    #endif

    //now expect terminals section
    getline(input, line);
    #ifdef DEBUG
    if (line == "SECTION Terminals") {
        cout << "OK";
    }
    else
        cout << "FAILED BEGIN OF TERMINALS";
    #endif

    //now expect Terminals #terminals
    for (int i = 0; i < 9; i++)
        input >> c;
    input >> T;

    Ts = new int[N];

    for (int i = 0; i < N; i++)
        Ts[i] = 0;

    for (int i = 0; i < T; i++) {
        input >> c;
        input >> a;
        Ts[a - 1] = 1;
    }

    //now expect end of this section
    getline(input, line);
    getline(input, line);
    #ifdef DEBUG
    if (line == "END") {
        cout << "OK";
    }
    else
        cout << "FAILED END OF TERMINALS";
    #endif

    //now expect empty line
    getline(input, line);
    #ifdef DEBUG
    if (line == "") {
        cout << "OK";
    }
    else
        cout << "FAILED EMPTY LINE AFTER END OF TERMINALS";
    #endif


    //now expect EOF
    getline(input, line);
    #ifdef DEBUG
    if (line == "EOF") {
        cout << "OK";
    }
    else
        cout << "FAILED EOF";

    cout << "Success!!";
    #endif

    input.close();
}

int main(int argc, char** argv)
{

    if (argc > 3)
        readFile(argv[3]);
    else {
        cout << "Input string format error" << endl;
        return 1;
    }

    return 0;
}
