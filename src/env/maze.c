#include<stdio.h>
#include<stdlib.h>

typedef struct Cell {
    int north; // north wall
    int east;  // east
    int south; // south
    int west;  // west
} Cell;

int wallNorth(Cell cell); //returns 1 if cell has wall to north, 0 otherwise
int wallEast(Cell cell); //returns 1 if cell has wall to east, 0 otherwise
int wallSouth(Cell cell); //returns 1 if cell has wall to south, 0 otherwise
int wallWest(Cell cell); // returns 1 if cell has wall to west, 0 otherwise

typedef struct Maze { // a depiction of the maze
    Cell actualMap[16][16];
    char displayMap[34][34];
} Maze;

Maze uploadMaze(char mazeFilePath[]);

int main() {
    char mazeFilePath[] = "../../mazes/j1.maze.txt";
    Maze maze = uploadMaze(mazeFilePath);
    int i,j;
    for(i=0;i<33;i++) {
        for(j=0;j<33;j++) {
            printf("%c",maze.displayMap[i][j]);
        }
        printf("\n");
    }
}

Maze uploadMaze(char mazeFilePath[]) {
    Maze maze;
    char line[35];
    FILE *mazeFile;
    
    mazeFile = fopen(mazeFilePath,"r");
    if(!mazeFile) {
        printf("Couldn't find maze file");
        exit(0);
    }
    else { 
        int row;
        int col;
        for(row=0;fgets(line,35,mazeFile)!=NULL;row++) {
            for(col=0;line[col]!=0;col++) {
                printf("%d : ",line[col]);
                printf("(%d,%d)\n",row,col);
                maze.displayMap[row][col] = line[col];
            }
        }
    }
    return maze;
}
