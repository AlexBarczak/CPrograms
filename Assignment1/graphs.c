/**
 * FILE: GRAPHS.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED FOR THE GRAPHS ASSIGNMENT. 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS BY REPLACING THE CURRENT IMPLEMENTATIONS
 * WITH IMPLEMENTATIONS OF YOUR OWN. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THAT THEY REQUIRE. YOU
 * DO NOT NEED TO USE USER INPUT FUNCTIONS SUCH AS SCANF
 * ETC, TO READ IN VALUES. THE GRAPH FUNCTIONS ARE CALLED
 * FROM A SEPARATE FILE (SEE THE TESTER PROGRAM) AND THE
 * INPUTS TO THE FUNCTIONS ARE PROVIDED THERE. 
 *
 * THE FUNCTIONS RETURN VALUES TO REPRESENT SUCCESS, ERROR,
 * OR, IN SOME CASES, DATA THAT HAS TO BE RETURNED. THE CALLER 
 * OF THESE FUNCTIONS WILL EXPECT TO RECEIVE THESE RETURN VALUES 
 * IN ORDER TO VERIFY THE OUTCOME OF THE FUNCTION CALL. 
 *
 * IF THERE AREANY FUNCTIONS THAT YOU DON'T HAVE TIME TO 
 * IMPLEMENT, PLEASE LEAVE THE EMPTY / DO-NOTHING IMPLEMENTATION
 * FOR THEM IN THIS FILE, OTHERWISE YOUR PROGRAM WON'T COMPILE
 * WHEN IT IS FED INTO OUR TESTER PROGRAM.
 * 
 */

/** 
 * ### INCLUDES
 */
#include <stdio.h>  // required for access to file input-output functions in C
#include <stdlib.h> // may be required for access to memory allocation functions
#include "graphs.h" // required, to include the Graph data structures and function declarations

/** #### FUNCTION IMPLEMENTATIONS ## */


/**
 * Create a new, empty Adjacency Matrix, returning a pointer to the newly 
 * allocated matrix OR a value of NULL in the event of error. Ensure that 
 * the matrix is initialised to the defaultEdgeValue provided.
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 *
 */
AdjacencyMatrix* createAdjacencyMatrix(int defaultEdgeValue)
{
    // attempt to allocate memory for the matrix
    AdjacencyMatrix* graph = myMalloc(sizeof(AdjacencyMatrix)); 

    // check if value is null in the case of no memory being available and return error code if so
    if (graph == NULL){
        return NULL;
    }
    
    // assign the default edge value to each position in the matrix
    // as the number of vertices in all the matrixes is a constant this implementation can hold,
    // if the size were dynamic, I'd have to play around with sizeof a whol bunch of time
    // to not go out of bounds
    //
    // for each vertice
    for (int ii = 0; ii < NUMBER_OF_VERTICES; ii++){
        //for each edge from vertice
        for(int jj = 0; jj < NUMBER_OF_VERTICES; jj ++){
            //set edge value to the default value
            graph->matrix[ii][jj] = defaultEdgeValue;
        }
    }

    // returning NOT_IMPLEMENTED until your own implementation is provided
    return graph;
}

/**
 * Add a new edge into the Adjacency Matrix provided, for the
 * relevant source node (src), destination node (dest), and weight
 * of the edge.
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int addEdge(AdjacencyMatrix *pMatrix, int src, int dest, int weight)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pMatrix;
    (void)src;
    (void)dest;
    (void)weight;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}

/**
 * This function should add a collection of new edges into the 
 * AdjacencyMatrix provided, using the input values given. 
 * The function should return SUCCESS, PARTIAL_SUCCESS, or 
 * INVALID_INPUT_PARAMETER. 
 * 
 */
int addEdges(AdjacencyMatrix *pMatrix, Edge edges[], int edgeNum)
{ 
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pMatrix;
    (void)edges;
    (void)edgeNum;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}

/**
 * This function should conduct a depth-first traversal of a graph and record the traversal 
 * sequence into the array provided (traversalOutput). The function expects to receive the 
 * following inputs:
 * - A pointer to an Adjacency Matrix representing the graph to be traversed.
 * - The index of the starting node in the graph where the traversal should commence.
 * - An array which will be used to store the output of the traversal, i.e., the order in 
 *   which the traversal visited the nodes in the graph. The array will store the index of the 
 *   graph nodes which are visited and in the order in which they are visited. The first item of 
 *   the array will show the starting node of the traversal. The last item of the array will be 
 *   the final node that was visited. 
 * 
 * The function should return SUCCESS or a relevant error code.
 *
 */
int doDepthFirstTraversal(AdjacencyMatrix *pMatrix, int startingNode, int traversalOutput[])
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pMatrix;
    (void)startingNode;
    (void)traversalOutput;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;

}

/**
 * This function will receive the name of a file on disk which contains the 
 * data for a graph which has been stored in the form of an adjacency matrix. 
 * The function should read the content from the file and use it to populate 
 * the AdjacencyMatrix provided. The file will be formatted thus:
 * 
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 
 * I.e., assuming a graph with 10 vertices, this will require a 10 x 10 matrix.
 * 
 * Each line in the file represents the next row in matrix, indexed from 0 to 9.
 * 
 * Each line will record the weight of the relevant edge in the graph. This will
 * be a value of zero (no edge) or a value of greater than zero (signifying that
 * an edge does exist, and the weight of that edge).
 * 
 * The function should return SUCCESS or a relevant error code.
 * 
 */
int loadMatrixFromFile(AdjacencyMatrix *pMatrix, char filename[])
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pMatrix;
    (void)filename;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}

/**
 * This function should perform the Dijkstra algorithm. It will receive a 
 * ready-made graph to work with, in the form of an AdjacencyMatrix. It 
 * will also receive an empty DijkstraTable, ready to be initialised and 
 * used. It will also receive the starting node on the graph to commence 
 * the algorithm from. 
 * 
 * This function should implement the algorithm, running it on the graph 
 * provided and updating the DijkstraTable with the outcome. After the function 
 * is called, the DijkstraTable will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int doDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int startNode)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pMatrix;
    (void)pTable;
    (void)startNode;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}


/**
 * This function should determine the shortest path that exists on a graph 
 * from a given starting node (nodeFrom) to a given end node (nodeTo). 
 * The function will be provided with a pre-populated DijkstraTable which already 
 * contains the outcome of running the Dijkstra algorithm on a graph. It will 
 * also be provided with an array (pathFound) into which the shortest path should 
 * be recorded. The path should be recorded in reverse order; showing, from the 
 * end node, the predecessors that lead us there from the start node. 
 * For example, if the shortest path on graph from node 2 to node 8 was found 
 * to be 2 -> 4 -> 5 -> 8. The content that would be recorded in the ‘pathFound’ 
 * variable would be as follows: [8][5][4][2]. I.e., it shows the relevant nodes 
 * in the path, in reverse order. This includes the start and end node too. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int findShortestPathTo(DijkstraTable *pTable, int nodeFrom, int nodeTo, int pathFound[])
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pTable;
    (void)nodeFrom;
    (void)nodeTo;
    (void)pathFound;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}


/**
 * This function should add a new edge into the AdjacencyList provided, based on 
 * a starting vertex (src), destination vertex (dest), and weight of the edge. 
 * 
 * The function should return SUCCESS or an error code. 
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 */
int addEdgeToAdjacencyList(AdjacencyList *pList, int src, int dest, int weight)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pList;
    (void)src;
    (void)dest;
    (void)weight;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}


/**
 * This function should populate the AdjacencyList provided. The list can be 
 * populated by examining the content of a corresponding adjacency matrix which
 * is also provided. By examining the adjacency matrix, the necessary edges on 
 * the graph can be ascertained and then added into the adjacency list at the 
 * appropriate locations. 
 * 
 * NOTE: when you are traversing the adjacency matrix, you must do it in the order
 * intimated below:
 * 
 * for i is 0 to number of rows in matrix
 *    for j is 0 to number of cols in matrix
 *        next element to process is at [i][j]
 * 
 * If you do not process the matrix in this order, your adjacency list will not
 * be populated in the correct order and will fail tests that run on it. 
 * 
 * The function should return SUCCESS or an error code. 
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 */
int populateAdjacencyList(AdjacencyList *pList, AdjacencyMatrix *pMatrix)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pList;
    (void)pMatrix;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}

/**
 * In the lectures, we looked at how to use an AdjacencyMatrix representation
 * of a graph as a basis for completing Dijkstra's algorithm. For this function, 
 * see if you can implement the algorithm using an AdjacencyList representation
 * of a graph instead. The AdjacencyList has the exact same content as the 
 * AdjacencyMatrix: it represents all of the nodes on a graph and the edges between 
 * them. It just represents these in a different way. 
 * 
 * To implement this function, you just need to review how you were using the 
 * AdjacencyMatrix during specific stages of the Dijkstra algorithm, and think about
 * how you could swap the AdjacencyList into these stages instead. The main difference
 * is likely to be related to how the edges that are emanating from the 'current'
 * node in the traversal are discovered. With the AdjacencyMatrix, we simply went
 * through the relevant row in the matrix, examining each column one at a time.
 * A similar approach can be taken for the AdjacencyList, but requiring a
 * different form of traversal for the relevant 'row' in the list.
 * 
 * The function will receive a ready-made graph to work with, in the form of 
 * an AdjacencyList. It will also receive an empty DijkstraTable, ready to be 
 * populated. It will also receive the starting node on the graph to 
 * commence the algorithm from. This function should implement the algorithm, 
 * running it on the graph provided and updating the DijkstraTable with the 
 * outcome. After the function is called, the DijkstraTable will be inspected to 
 * determine whether the algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or an error code.
 */
int doDijsktraAlgorithmOnAdjacencyList(AdjacencyList *pList, DijkstraTable *pTable, int startNode)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pList;
    (void)pTable;
    (void)startNode;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}