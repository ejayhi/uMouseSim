/**
 * name: ejayt
 * team: pg
 * proj: umouse
 * file: maze.h
 */

#include<stdio.h>
#include<stdlib.h>

#define DISP_HEIGHT 33  
#define DISP_WIDTH  33
#define MAZE_HEIGHT 16
#define MAZE_WIDTH  16

typedef struct Cell {
    int dispCoord[2];
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
    Cell actualMap[MAZE_HEIGHT][MAZE_WIDTH];
    char displayMap[DISP_HEIGHT][DISP_WIDTH];
} Maze;

Maze uploadMaze(char mazeFilePath[]);
Maze determineWalls(Maze maze);


