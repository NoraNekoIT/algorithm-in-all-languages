import java.lang.*;   
import java.util.*;   
import java.io.*;   
  
//creating MinimumSpanningTreeExample class to implement Prim's algorithm in Java     
class MinimumSpanningTreeExample{   
    // Define the count of vertices available in the graph  
    private static final int countOfVertices = 7;   
    
    // create findMinKeyVertex() method for finding the vertex v that has minimum key-value and that is not added MST yet  
    int findMinKeyVertex(int keys[], Boolean MST[])   
    {   
        // Initialize min value and its index  
        int minimum_index = -1;   
        int minimum_value = Integer.MAX_VALUE;  
          
        //iterate over all vertices to find minimum key-value vertex  
        for (int vertex = 0; vertex < countOfVertices; vertex++)   
            if (MST[vertex] == false && keys[vertex] < minimum_value) {   
                minimum_value = keys[vertex];   
                minimum_index = vertex;   
            }   
    
        return minimum_index;   
    }   
    
    // create showMinimumSpanningTree for printing the constructed MST stored in mstArray[]   
    void showMinimumSpanningTree(int mstArray[], int graphArray[][])   
    {   
        System.out.println("Edge \t\t Weight");   
        for (int j = 1; j < countOfVertices; j++)   
            System.out.println(mstArray[j] + " <-> " + j + "\t \t" + graphArray[j][mstArray[j]]);   
    }   
    
    // create designMST() method for constructing and printing the MST. The graphArray[][] is an adjacency matrix that defines the graph for MST.  
    void designMST(int graphArray[][])   
    {   
        // create array of size total number of vertices, i.e., countOfVertices for storing the MST  
        int parent[] = new int[countOfVertices];   
    
        // create keys[] array for selecting an edge having minimum weight in cut   
        int key[] = new int[countOfVertices];   
    
        // create setOfMST array of type boolean for representing the set of vertices included in MST   
        Boolean MST[] = new Boolean[countOfVertices];   
    
        // set the value of the keys to infinite   
        for (int j = 0; j < countOfVertices; j++) {   
            key[j] = Integer.MAX_VALUE;   
            MST[j] = false;   
        }   
    
        // set value 0 to the 1st vertex because first vertexs always include in MST.   
        key[0] = 0; // it select as first vertex   
        parent[0] = -1; // set first value of mstArray to -1 to make it root of MST   
    
        // The vertices in the MST will be equal to the countOfVertices   
        for (int i = 0; i < countOfVertices - 1; i++) {   
            // select the vertex having minimum key and that is not added in the MST yet from the set of vertices   
            int edge = findMinKeyVertex(key, MST);   
    
            // Add the selected minimum key vertex to the setOfMST   
            MST[edge] = true;   
    
            // change the key value and the parent index of all the adjacent vertices of the selected vertex. The vertices that are not yet included in Minimum Spanning Tree are only considered.   
            for (int vertex = 0; vertex < countOfVertices; vertex++)   
    
                // The value of the graphArray[edge][vertex] is non zero only for adjacent vertices of m setOfMST[vertex] is false for vertices not yet included in Minimum Spanning Tree   
                // when the value of the graphArray[edge][vertex] is smaller than key[vertex], we update the key  
                if (graphArray[edge][vertex] != 0 && MST[vertex] == false && graphArray[edge][vertex] < key[vertex]) {   
                    parent[vertex] = edge;   
                    key[vertex] = graphArray[edge][vertex];   
                }   
        }   
    
        // print the constructed Minimum Spanning Tree   
        showMinimumSpanningTree(parent, graphArray);   
    }   
    //main() method start  
    public static void main(String[] args)   
    {   
          
        MinimumSpanningTreeExample mst = new MinimumSpanningTreeExample();   
        int graphArray[][] = new int[][]{   { 0, 2, 0, 1, 4, 0, 0 },   
                                            { 2, 0, 5, 0, 0, 0, 0 },   
                                            { 0, 5, 0, 2, 0, 4, 0 },   
                                            { 1, 0, 2, 0, 0, 0, 0 },   
                                            { 4, 0, 0, 0, 0, 3, 6 },  
                                            { 0, 0, 4, 0, 3, 0, 2 },  
                                            { 0, 0, 0, 0, 6, 2, 0 }};   
    
        // Print the Minimum Spanning Tree solution   
        mst.designMST(graphArray);   
    }   
}  
