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
 * Author:                  Aleksander Barczak
 * Matriculation Number:    2497555
 * Date:                    21/10/2023
*/

/** 
 * ### INCLUDES
 */
#include <stdio.h>  // required for access to file input-output functions in C
#include <stdlib.h> // may be required for access to memory allocation functions
#include <string.h> // used for the strtok function
#include "graphs.h" // required, to include the Graph data structures and function declarations

// I wanted to do depth traversal using recursion but later noticed that you have made it
// state mandated to ues your method which i find unpleasant
//#define RECURSIVE_DEPTH_TRAVERSAL

#ifdef RECURSIVE_DEPTH_TRAVERSAL
void recDepthFirstTraversal(AdjacencyMatrix *pMatrix, int currentNode, int visitedNodes[]);
#endif
int isInArray(int value, int* array, int arraySize);

void recDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int currentNode);


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
    AdjacencyMatrix* pGraph = myMalloc(sizeof(AdjacencyMatrix)); 

    // check if value is null in the case of no memory being available and return error code if so
    if (pGraph == NULL){
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
            pGraph->matrix[ii][jj] = defaultEdgeValue;
        }
    }

    // returning NOT_IMPLEMENTED until your own implementation is provided
    return pGraph;
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
    // perform input validation
    //
    //validate pMatrix is a valid pointer
    if (pMatrix == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    // validate src and dest as not being greater than the vertice count or less than 0
    if (src > NUMBER_OF_VERTICES || src < 0){
        return INVALID_INPUT_PARAMETER;
    }
    if (dest > NUMBER_OF_VERTICES || dest < 0){
        return INVALID_INPUT_PARAMETER;
    }

    // weight should not need validation, it's completely up to the user what they
    // set the weight to and there's no limit spoken of
    
    pMatrix->matrix[src][dest] = weight;

    return SUCCESS;
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
    // perform input validation
    //
    // pMatrix must be a valid pointer and not null
    if (pMatrix == NULL){
        return INVALID_INPUT_PARAMETER;
    }
    
    // edges must not be a null pointer to an array
    if (edges == NULL){
        return INVALID_INPUT_PARAMETER;
    }
    
    // if edges is valid, so is edgenum, therefore don't need to validate it

    // if all the edges are added successfully, return success
    // if some are added successfully and others not, return partial success
    // if none are added successfully, return invalid input
    //
    // to know which of these is the case we need to keep track of the number of 
    // successful (or unsuccessful) operations made

    int successful_edge_additions = 0;


    // make a for loop going through the edges array and attempt to add them
    // to the matrix provided
    for (int ii = 0; ii < edgeNum; ii++){
        int result = addEdge(pMatrix, edges[ii].src, edges[ii].dest, edges[ii].weight);
        
        // if the addition of the edge went fine, add it to the count
        if (result == SUCCESS){
            successful_edge_additions++;
        }
    }

    // now all the valid edges should be added and we can check 
    // if the number of edges added succesfully equals the number of edges
    if (successful_edge_additions == edgeNum){
        // all the additions were successful
        return SUCCESS;
    }

    // if none of the edges were added successfully
    if (successful_edge_additions == 0)
    {
        // input was invalid
        return INVALID_INPUT_PARAMETER;
    }

    // otherwise it means some edges were valid and some were not
    return PARTIAL_SUCCESS;
    
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
    // perform input validation
    //
    // pMatrix must be a valid pointer and not null
    if (pMatrix == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    // starting node must be a node within the graph
    if (startingNode > NUMBER_OF_VERTICES){
        return INVALID_INPUT_PARAMETER;
    }
    
    // traversal output must not be a null pointer
    if (traversalOutput == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    for (int ii = 0; ii < NUMBER_OF_VERTICES; ii++){
        traversalOutput[ii] = -1;
    }    
    //record the starting node as traversed
    traversalOutput[0] = startingNode;
    

    #ifdef RECURSIVE_DEPTH_TRAVERSAL
    recDepthFirstTraversal(pMatrix, startingNode, traversalOutput);
    #endif

    // NOTE: I hate the following implementation, I find it despicable
    // its only merit is that it has linear space complexity. Aside from that it is an ugly
    // implementation that performs repeated comparisons when backtracking.
    // I also despise the idea of manually altering loop variable from within 
    // I wish this would have just been the recursive implementation I've made here

    #ifndef RECURSIVE_DEPTH_TRAVERSAL
    //define our stack to backtrack and a variable to keep track of the top 
    int stack[NUMBER_OF_VERTICES];
    int top = -1;

    // current node is index of what we're starting with
    int current_node = startingNode;

    // loop through the current node's row in the adjacency list
    for (int ii = 0; ii < NUMBER_OF_VERTICES; ii++){
        // is there an edge to node ii in the graph
        if(pMatrix->matrix[current_node][ii] != 0){
            // if there is an edge to node ii
            // has that node ii been visited
            if (isInArray(ii, traversalOutput, NUMBER_OF_VERTICES) == 1){
                //nothing to do
            }else{
                //get ready to mode to node i in graph
                //push current node onto the stack in case we need to backtrack
                top++;
                stack[top] = current_node;
                //modify the current node to be node i one the graph (the new node / edge found above)
                current_node = ii;
                //record this new current node as being visited 
                for (int jj = 1; jj < NUMBER_OF_VERTICES; jj++){
                    if (traversalOutput[jj] == -1){
                        traversalOutput[jj] = current_node;
                        break;
                    }
                }
            }
        }else{
            // have we reached the final element in this adjacency row?
            if (ii == NUMBER_OF_VERTICES - 1){
                // do we need to backtrack anywhere?
                if (top != -1){
                    // pop from stack and make it the current node
                    current_node = stack[top];
                    top--;
                    // reset the loop
                    // ii will be immediately incremented to 0
                    ii = -1;
                }
            }
        }
    } 
    #endif

    return SUCCESS;
}

#ifdef RECURSIVE_DEPTH_TRAVERSAL
void recDepthFirstTraversal(AdjacencyMatrix *pMatrix, int currentNode, int visitedNodes[]){
    // all passed in values have already been checked for validity in doDepthFirstTraversal
    // therefore validation not necessary

    // start looping through the node's adjacency row
    for (int ii = 0; ii < NUMBER_OF_VERTICES; ii++){
        // check if node is not connected to node ii
        if(pMatrix->matrix[currentNode][ii] == 0){
            continue;
        }

        // if the node is connected then check if it has been visited   
        if (isInArray(ii, visitedNodes, NUMBER_OF_VERTICES) == 1){
            continue;
        }

        // if you reach here then node ii has not been visited and is connected to the current node
        // meaning we can add it to teh traversed nodes and then call the recursion function again
        for (int jj = 1; jj < NUMBER_OF_VERTICES; jj++){
            if (visitedNodes[jj] == -1){
                visitedNodes[jj] = ii;
                recDepthFirstTraversal(pMatrix, ii, visitedNodes);
                break;
            }
        }
    }
}
#endif

// function simply checks for the presence of a value in the array and returns true or false
int isInArray(int value, int* array, int arraySize){
    for (int ii = 0; ii < arraySize; ii++)
    {
        if (value == array[ii]){
            // item is in array
            return 1;
        }
    }
    // item not in array
    return 0;    
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
    // perform input validation
    //
    // validate pMatrix is a valid pointer
    if (pMatrix == NULL){
        return INVALID_INPUT_PARAMETER;
    }
    
    // try to open the file
    FILE *fp;
    // open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL){
        // throw error if filename is invalid
        return FILE_IO_ERROR;
    }

    // set variables for strtok function
    char line[256];
    char delimiter[] = " ";
    char *sWeight;

    // which row do we write to
    int srcIndex = 0;
    int destIndex = 0;
    

    while (fgets(line, 256, fp) != NULL){
        // get the first value
        sWeight = strtok(line, delimiter);
        // convert the value from char[] format to int
        int weight = atoi(sWeight);

        while(sWeight != NULL){
            // get the next value
            
            // convert the value from char[] format to int
            int weight = atoi(sWeight);

            pMatrix->matrix[srcIndex][destIndex] = weight;

            sWeight = strtok(NULL, delimiter);

            // increment the index of the destination
            destIndex++;
        }
        // increment the index of the src and reset dest
        srcIndex++;
        destIndex = 0;
    }

    fclose(fp);

    return SUCCESS;
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
    // perform input validation
    //
    // validate pMatrix is a valid pointer
    if (pMatrix == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    // validate pTable is a valid pointer
    if (pTable == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    //start node must be between 0 and the number of vertices 
    if (startNode < 0 || startNode > NUMBER_OF_VERTICES){
        return INVALID_INPUT_PARAMETER;
    }
    
    // initialise our Dijlstra table
    for (int i = 0; i < NUMBER_OF_VERTICES; i++){
        pTable->table[i].visited = false;
        pTable->table[i].distance = VERY_LARGE_NUMBER;
        pTable->table[i].predecessor = -1;
    }

    int currentNode = startNode;
    
    // initialise distance to starting node as 0
    pTable->table[currentNode].distance = 0;

    // use recursion to fill the table
    recDijsktraAlgorithm(pMatrix, pTable, startNode);

    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}

void recDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int currentNode){

    // loop throught the adjacency row to see all adjacent nodes
    for(int ii = 0; ii < NUMBER_OF_VERTICES; ii++){
        // if there is no edge to the node ii, ignore it
        int edgeToII = pMatrix->matrix[currentNode][ii];
        if(edgeToII == 0){
            continue;
        }
        // if there is an edge check if it has been visited, if it has been, ignore it
        if(pTable->table[ii].visited == true){
            continue;
        }

        // process the edge
        //
        // if the distance across the edge + the distance to the current node is longer than the recorded distance
        int distanceToII = pTable->table[currentNode].distance + edgeToII;
        if( distanceToII < pTable->table[ii].distance){
            pTable->table[ii].distance = distanceToII;
            pTable->table[ii].predecessor = currentNode;
        }
    }

    // mark this node as visited
    pTable->table[currentNode].visited = true;
    
    // find the next node to process, by searching the table and picking the unvisited node with the shortest distance
    // if all nodes have been visited then all connections have been processed and we can let the recursion collapse
    int shortestDistance = VERY_LARGE_NUMBER;
    int closestNode = -1;
    for (int ii = 0; ii < NUMBER_OF_VERTICES; ii++){
        // find the closest unvisited node
        if (pTable->table[ii].visited == true){
            continue;
        }
        if (pTable->table[ii].distance < shortestDistance)
        {
            // node found, set closest node to this and update shortest distance
            shortestDistance = pTable->table[ii].distance;
            closestNode = ii;
        }
        
    }

    // if call this function on the closest node
    if (closestNode != -1){
        recDijsktraAlgorithm(pMatrix, pTable, closestNode);
    }
    return;
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