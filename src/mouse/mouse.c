/**
 * name: ejayt
 * date: 25 Feb 2013
 * team: pg
 * proj: umouse
 * file: mouse.c
 *
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct mCell {
} mCell;

typedef struct Mouse {
    int ori; // Orientation. Which way the mouse is facing. 0123=NESW
    int loc[2]; // Location. Where the mouse is in the maze
    int mCell[16][16];
} Mouse;

void moveForward(int &ori,int &location[]) {
    // the mouse is facing north
    if(ori==0) location[0]=location[0]-1; 
    else if(ori==1) location[1]=location[1]+1; // east 
    else if(ori==2) location[0]=location[0]+1; // south
    else if(ori==3) location[1]=location[1]-1; // west
}

void faceLeft(int &ori) {
    if(ori==0) ori=3;
    else if(ori==1) ori=0;
    else if(ori==2) ori=1;
    else if(ori==3) ori=2;
}

void faceRight(int &ori) {
    if(ori==0) ori=1;
    else if(ori==1) ori=2;
    else if(ori==2) ori=3;
    else if(ori==3) ori=0;
}

void faceBack(int &ori) {
    faceLeft(&ori);
    faceLeft(&ori);
}
