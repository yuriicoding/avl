#include "BinarySearchTree.h"
#include "AvlTree.h"
#include <time.h>
#include <float.h>
#include <iostream>
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

    int nodes[nodeNum];

    for (int i = 0; i < nodeNum; i++)
    {
        nodes[i] = i;
    }

    random_shuffle(nodes, nodes + nodeNum/2);

    BinarySearchTree<int> BST;
    
    clock_t start1, finish1 ;// used for getting the time. 
    start1 = clock(); 
    /* stuff to time here */
    
    for (int i = 0; i < nodeNum; i++)
    {
        BST.insert(nodes[i]);
    }
       
    finish1 = clock(); 
    double BSTinsertion = elapsed_time(start1,finish1);
    cout << "BST average insertion time: " << BSTinsertion/nodeNum << endl;
    cout << "BST height: " << BST.height() << endl;
    
    double BSTdepthSum = 0;
    for (int i = 0; i < nodeNum; i++)
    {
        BSTdepthSum += BST.depth(i);
    }
    double BSTaveDepth = BSTdepthSum/nodeNum;
    cout << "BST average depth: " << BSTaveDepth << endl;

    double BSTmin_check = DBL_MAX;
    double BSTmax_check = -1;
    double BSTsum_check = 0;
    int BSTmin_depth = INT16_MAX;
    int BSTmax_depth = -1;
    double BSTsum_depth = 0;

    int depth = 0;
    double time = 0;

    clock_t start2, finish2;
    
    for (int i = 0; i < search; i++)
    {
        start2 = clock();
        depth = BST.depth(searchArr[i]);
        finish2 = clock();
        time = elapsed_time(start2,finish2);

        BSTsum_depth += depth;
        BSTsum_check += time;

        if (depth > BSTmax_depth) BSTmax_depth = depth;
        if (depth < BSTmin_depth) BSTmin_depth = depth;
        if (time > BSTmax_check) BSTmax_check = time;
        if (time < BSTmin_check) BSTmin_check = time;
    }

    cout << "BST min depth: " << BSTmin_depth << endl;
    cout << "BST max depth: " << BSTmax_depth << endl;
    cout << "BST mean depth: " << BSTsum_depth/search << endl;
    cout << "BST min membership check time: " << BSTmin_check << endl;
    cout << "BST max membership check time: " << BSTmax_check << endl;
    cout << "BST mean membership check time: " << BSTsum_check/search << endl;



    AvlTree<int> Avl;
    
    clock_t start3, finish3 ;// used for getting the time. 
    start3 = clock(); 
    /* stuff to time here */
    
    for (int i = 0; i < nodeNum; i++)
    {
        Avl.insert(nodes[i]);
    }
       
    finish3 = clock(); 
    double Avlinsertion = elapsed_time(start3,finish3);
    cout << "Avl average insertion time: " << Avlinsertion/nodeNum << endl;
    cout << "Avl height: " << Avl.height() << endl;
    
    double AvldepthSum = 0;
    for (int i = 0; i < nodeNum; i++)
    {
        AvldepthSum += Avl.depth(i);
    }
    double AvlaveDepth = AvldepthSum/nodeNum;
    cout << "Avl average depth: " << AvlaveDepth << endl;

    double Avlmin_check = DBL_MAX;
    double Avlmax_check = -1;
    double Avlsum_check = 0;
    int Avlmin_depth = INT16_MAX;
    int Avlmax_depth = -1;
    double Avlsum_depth = 0;

    int depth1 = 0;
    double time1 = 0;

    clock_t start4, finish4;
    
    for (int i = 0; i < search; i++)
    {
        start4 = clock();
        depth1 = Avl.depth(searchArr[i]);
        finish4 = clock();
        time1 = elapsed_time(start4,finish4);

        Avlsum_depth += depth1;
        Avlsum_check += time1;

        if (depth1 > Avlmax_depth) Avlmax_depth = depth1;
        if (depth1 < Avlmin_depth) Avlmin_depth = depth1;
        if (time1 > Avlmax_check) Avlmax_check = time1;
        if (time1 < Avlmin_check) Avlmin_check = time1;
    }

    cout << "Avl min depth: " << Avlmin_depth << endl;
    cout << "Avl max depth: " << Avlmax_depth << endl;
    cout << "Avl mean depth: " << Avlsum_depth/search << endl;
    cout << "Avl min membership check time: " << Avlmin_check << endl;
    cout << "Avl max membership check time: " << Avlmax_check << endl;
    cout << "Avl mean membership check time: " << Avlsum_check/search << endl;
}
