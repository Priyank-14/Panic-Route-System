#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"

/*
==========================================================
                PANIC ROUTE SYSTEM
==========================================================

This program helps in finding the SAFEST route between
two locations using a modified Dijkstra algorithm.

Instead of shortest distance, we calculate:
    cost = distance + (danger × weight)

Higher weight = more importance to safety

==========================================================
*/

/*
    Function: buildGraph

    Purpose:
    --------
    This function takes user input to create a graph.

    It asks for:
    - Number of locations (nodes)
    - Number of roads (edges)
    - Details of each road:
        → source
        → destination
        → distance
        → danger level

    Returns:
    --------
    A pointer to the created graph
*/
Graph* buildGraph() {

    int n, edges;
    int src, dest, distance, danger;

    printf("\nEnter number of locations: ");
    scanf("%d", &n);

    // Create graph
    Graph* graph = createGraph(n);

    printf("Enter number of roads: ");
    scanf("%d", &edges);

    printf("\nEnter road details:\n");
    printf("(Format: source destination distance danger)\n");

    for (int i = 0; i < edges; i++) {

        printf("Road %d: ", i + 1);
        scanf("%d %d %d %d", &src, &dest, &distance, &danger);

        // Basic validation
        if (src < 0 || src >= n || dest < 0 || dest >= n) {
            printf("Invalid nodes! Please re-enter.\n");
            i--;
            continue;
        }

        addEdge(graph, src, dest, distance, danger);
    }

    printf("\nGraph created successfully!\n");

    return graph;
}

/*
    Function: displayMenu

    Purpose:
    --------
    Displays the main menu of the system
*/
void displayMenu() {

    printf("\n==================================================\n");
    printf("              PANIC ROUTE SYSTEM\n");
    printf("==================================================\n");

    printf("1. Create City Map\n");
    printf("2. Display City Map\n");
    printf("3. Find SAFEST Route\n");
    printf("4. Exit\n");

    printf("--------------------------------------------------\n");
    printf("Enter your choice: ");
}

/*
    Function: explainLogic

    Purpose:
    --------
    Explains how the system works (for user understanding)
*/
void explainLogic(int weight) {

    printf("\n==================================================\n");
    printf("                RESULT EXPLANATION\n");
    printf("==================================================\n");

    printf("This system does NOT choose the shortest path.\n");
    printf("It selects the SAFEST path based on risk.\n");
    printf("Formula used:\n");
    printf("      Cost = Distance + (Danger * Weight)\n");

    printf("\nWeight used: %d\n", weight);

    if (weight >= 3)
        printf("Safety was given HIGH importance.\n");
    else
        printf("Distance had more influence.\n");

    printf("==================================================\n");
}

/*
    MAIN FUNCTION

    Purpose:
    --------
    Controls the entire program flow using menu-driven approach
*/
int main() {

    Graph* graph = NULL;   // Initially no graph
    int choice;
    int src, dest, weight;

    do {

        displayMenu();
        scanf("%d", &choice);

        switch (choice) {

        /*
        ------------------------------------------
        OPTION 1: CREATE GRAPH
        ------------------------------------------
        */
        case 1:
            graph = buildGraph();
            break;

        /*
        ------------------------------------------
        OPTION 2: DISPLAY GRAPH
        ------------------------------------------
        */
        case 2:
            if (graph == NULL) {
                printf("\nGraph not created yet!\n");
            } else {
                printf("\nCity Map:\n");
                printGraph(graph);
            }
            break;

        /*
        ------------------------------------------
        OPTION 3: FIND SAFEST ROUTE
        ------------------------------------------
        */
        case 3:
            if (graph == NULL) {
                printf("\nPlease create the graph first!\n");
                break;
            }

            printf("\nEnter source location: ");
            scanf("%d", &src);

            printf("Enter destination location: ");
            scanf("%d", &dest);

            // Validate input
            if (src < 0 || src >= graph->numVertices ||
                dest < 0 || dest >= graph->numVertices) {

                printf("Invalid locations!\n");
                break;
            }

            printf("Enter safety weight (importance of danger): ");
            scanf("%d", &weight);

            printf("\n==================================================\n");
            printf("             FINDING SAFEST ROUTE...\n");
            printf("==================================================\n");

            // Call Dijkstra Algorithm
            dijkstra(graph, src, dest, weight);

            // Explain result
            explainLogic(weight);

            break;

        /*
        ------------------------------------------
        OPTION 4: EXIT
        ------------------------------------------
        */
        case 4:
            printf("\nThank you for using Panic Route System!\n");
            break;

        /*
        ------------------------------------------
        INVALID INPUT
        ------------------------------------------
        */
        default:
            printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}