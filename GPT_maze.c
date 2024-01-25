#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 50
#define MAX_WIDTH 50

typedef struct {
    int row;
    int col;
} State;

typedef struct Node {
    State state;
    struct Node* parent;
    char* action;
} Node;

typedef struct {
    Node* frontier[MAX_HEIGHT * MAX_WIDTH];
    int size;
} StackFrontier;

typedef struct {
    Node* frontier[MAX_HEIGHT * MAX_WIDTH];
    int front;
    int rear;
    int size;
} QueueFrontier;

typedef struct {
    int height;
    int width;
    State start;
    State goal;
    char walls[MAX_HEIGHT][MAX_WIDTH];
    Node* solution;
    int num_explored;
} Maze;

Node* createNode(State state, Node* parent, const char* action) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Failed to allocate memory for Node\n");
        exit(EXIT_FAILURE);
    }
    
    node->state = state;
    node->parent = parent;
    node->action = (action != NULL) ? strdup(action) : NULL; // Check for action validity

    return node;
}

void printMaze(const Maze* maze) {
    printf("Maze:\n");
    for (int i = 0; i < maze->height; i++) {
        printf("%s\n", maze->walls[i]);
    }
}

void printSolution(const Maze* maze) {
    printMaze(maze);

    if (maze->solution == NULL) {
        printf("No solution found\n");
        return;
    }

    printf("Solution:\n");
    Node* node = maze->solution;
    while (node != NULL) {
        printf("(%d, %d) - %s\n", node->state.row, node->state.col, (node->action != NULL) ? node->action : "(null)");
        node = node->parent;
    }
}

void stackFrontierAdd(StackFrontier* stackFrontier, Node* node) {
    stackFrontier->frontier[stackFrontier->size++] = node;
}

Node* stackFrontierRemove(StackFrontier* stackFrontier) {
    if (stackFrontier->size == 0) {
        fprintf(stderr, "Empty frontier\n");
        exit(EXIT_FAILURE);
    } else {
        return stackFrontier->frontier[--stackFrontier->size];
    }
}

int stackFrontierEmpty(const StackFrontier* stackFrontier) {
    return stackFrontier->size == 0;
}

void queueFrontierAdd(QueueFrontier* queueFrontier, Node* node) {
    queueFrontier->frontier[queueFrontier->rear++] = node;
    queueFrontier->size++;
}

Node* queueFrontierRemove(QueueFrontier* queueFrontier) {
    if (queueFrontier->size == 0) {
        fprintf(stderr, "Empty frontier\n");
        exit(EXIT_FAILURE);
    } else {
        Node* node = queueFrontier->frontier[queueFrontier->front++];
        queueFrontier->size--;
        return node;
    }
}

int queueFrontierEmpty(const QueueFrontier* queueFrontier) {
    return queueFrontier->size == 0;
}

int stackFrontierContainsState(const StackFrontier* stackFrontier, State state) {
    for (int i = 0; i < stackFrontier->size; i++) {
        if (stackFrontier->frontier[i]->state.row == state.row &&
            stackFrontier->frontier[i]->state.col == state.col) {
            return 1;  // State found in the stack
        }
    }
    return 0;  // State not found in the stack
}

int queueFrontierContainsState(const QueueFrontier* queueFrontier, State state) {
    for (int i = queueFrontier->front; i < queueFrontier->rear; i++) {
        if (queueFrontier->frontier[i]->state.row == state.row &&
            queueFrontier->frontier[i]->state.col == state.col) {
            return 1;  // State found in the queue
        }
    }
    return 0;  // State not found in the queue
}

void initializeMaze(Maze* maze, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read maze dimensions
    fscanf(file, "%d %d", &maze->height, &maze->width);

    // Initialize start and goal positions
    maze->start.row = maze->start.col = maze->goal.row = maze->goal.col = 0;

   // Read maze layout
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (fscanf(file, " %c", &maze->walls[i][j]) != 1) {
                fprintf(stderr, "Error reading maze layout from file: %s\n", filename);
                exit(EXIT_FAILURE);
            }
            // Set start and goal positions
            if (maze->walls[i][j] == 'A') {
                maze->start.row = i;
                maze->start.col = j;
            } else if (maze->walls[i][j] == 'B') {
                maze->goal.row = i;
                maze->goal.col = j;
            }
        }   
    }
    // Check if start and goal positions are initialized
    if (maze->start.row == -1 || maze->start.col == -1 || maze->goal.row == -1 || maze->goal.col == -1) {
        fprintf(stderr, "Failed to initialize start or goal positions\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void freeMaze(Maze* maze) {
    if (maze->solution != NULL) {
        Node* node = maze->solution;
        while (node != NULL) {
            Node* temp = node;
            node = node->parent;
            free(temp->action);
            free(temp);
        }
    }
}

void solveMaze(Maze* maze, int useQueue) {
    if (useQueue) {
        QueueFrontier queueFrontier;
        queueFrontier.front = queueFrontier.rear = queueFrontier.size = 0;

        queueFrontierAdd(&queueFrontier, createNode(maze->start, NULL, NULL));

        while (!queueFrontierEmpty(&queueFrontier)) {
            Node* node = queueFrontierRemove(&queueFrontier);
            maze->num_explored++;

            // Check if the goal is reached
            if (node->state.row == maze->goal.row && node->state.col == maze->goal.col) {
                maze->solution = node;
                return;
            }

            // Explore neighbors
            int row = node->state.row;
            int col = node->state.col;

            // Move up
            if (row > 0 && maze->walls[row - 1][col] == ' ' && !queueFrontierContainsState(&queueFrontier, (State){row - 1, col})) {
                queueFrontierAdd(&queueFrontier, createNode((State){row - 1, col}, node, "up"));
            }
            // Move down
            if (row < maze->height - 1 && maze->walls[row + 1][col] == ' ' && !queueFrontierContainsState(&queueFrontier, (State){row + 1, col})) {
                queueFrontierAdd(&queueFrontier, createNode((State){row + 1, col}, node, "down"));
            }
            // Move left
            if (col > 0 && maze->walls[row][col - 1] == ' ' && !queueFrontierContainsState(&queueFrontier, (State){row, col - 1})) {
                queueFrontierAdd(&queueFrontier, createNode((State){row, col - 1}, node, "left"));
            }
            // Move right
            if (col < maze->width - 1 && maze->walls[row][col + 1] == ' ' && !queueFrontierContainsState(&queueFrontier, (State){row, col + 1})) {
                queueFrontierAdd(&queueFrontier, createNode((State){row, col + 1}, node, "right"));
            }
        }
    } else {
        StackFrontier stackFrontier;
        stackFrontier.size = 0;

        stackFrontierAdd(&stackFrontier, createNode(maze->start, NULL, NULL));

        while (!stackFrontierEmpty(&stackFrontier)) {
            Node* node = stackFrontierRemove(&stackFrontier);
            maze->num_explored++;

            // Check if the goal is reached
            if (node->state.row == maze->goal.row && node->state.col == maze->goal.col) {
                maze->solution = node;
                return;
            }

            // Explore neighbors
            int row = node->state.row;
            int col = node->state.col;

            // Move up
            if (row > 0 && maze->walls[row - 1][col] == ' ' && !stackFrontierContainsState(&stackFrontier, (State){row - 1, col})) {
                stackFrontierAdd(&stackFrontier, createNode((State){row - 1, col}, node, "up"));
            }
            // Move down
            if (row < maze->height - 1 && maze->walls[row + 1][col] == ' ' && !stackFrontierContainsState(&stackFrontier, (State){row + 1, col})) {
                stackFrontierAdd(&stackFrontier, createNode((State){row + 1, col}, node, "down"));
            }
            // Move left
            if (col > 0 && maze->walls[row][col - 1] == ' ' && !stackFrontierContainsState(&stackFrontier, (State){row, col - 1})) {
                stackFrontierAdd(&stackFrontier, createNode((State){row, col - 1}, node, "left"));
            }
            // Move right
            if (col < maze->width - 1 && maze->walls[row][col + 1] == ' ' && !stackFrontierContainsState(&stackFrontier, (State){row, col + 1})) {
                stackFrontierAdd(&stackFrontier, createNode((State){row, col + 1}, node, "right"));
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s maze.txt (0 for stack, 1 for queue)\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Maze maze;
    initializeMaze(&maze, argv[1]);

    int useQueue = atoi(argv[2]);
    if (useQueue != 0 && useQueue != 1) {
        fprintf(stderr, "Invalid argument: 0 for stack, 1 for queue\n");
        exit(EXIT_FAILURE);
    }

    // Set initial state
    maze.solution = NULL;
    maze.num_explored = 0;

    printf("Maze:\n");
    for (int i = 0; i < maze.height; i++) {
        printf("%s\n", maze.walls[i]);
    }

    printf("Solving...\n");
    solveMaze(&maze, useQueue);

    printf("States Explored: %d\n", maze.num_explored);

    printSolution(&maze);
    
    freeMaze(&maze); // Free allocated memory
    
    return 0;
}
