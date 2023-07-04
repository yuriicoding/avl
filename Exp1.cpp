#include <time.h>
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
   
double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 
   
int main (int argc, char * const argv[]) {

    const int nodeNum = 50000;
    const int search = 10000;

    srand(time(NULL));
    int searchArr[search];
    for (int i = 0; i < search; i++)
    {
        int nodeVal = rand()%nodeNum;
        searchArr[i] = nodeVal;
    }

    BinarySearchTree<int> T1;
    for (int i = 0; i < nodeNum; i++)
    {
        T1.insert(i);
    }
    
    int depthSum1 = 0;

    clock_t start, finish ;// used for getting the time. 
    start = clock(); 
    /* stuff to time here */
    for (int i = 0; i < search; i++)
    {
        depthSum1 += T1.depth(searchArr[i]);
    }
       
    finish = clock(); 
    double time_taken1 = elapsed_time(start,finish);
    
    cout << "Average membership test time for T1: " << time_taken1/search << endl;
    cout << "Average depth for T1: " << depthSum1/search << endl;

    BinarySearchTree<int> T2;
    int T2nodes[nodeNum];

    for (int i = 0; i < nodeNum; i++)
    {
        T2nodes[i] = i;
    }

    random_shuffle(T2nodes, T2nodes + nodeNum);

    for (int i = 0; i < nodeNum; i++)
    {
        T2.insert(T2nodes[i]);
    }

    int depthSum2 = 0;
    
    clock_t start2, finish2;
    start2 = clock();
    /* stuff to time here */
    for (int i = 0; i < search; i++)
    {
        depthSum2 += T2.depth(searchArr[i]);
    }

    finish2 = clock();
    double time_taken2 = elapsed_time(start2,finish2);
    
    cout << "Average membership test time for T2: " << time_taken2/search << endl;
    cout << "Average depth for T2: " << depthSum2/search << endl;

}
