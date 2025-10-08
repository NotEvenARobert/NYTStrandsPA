/* COP 3502C PA3
This program is written by: ANH NHAT LE (Robert) */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NUMDIR 8
const int NULLPTR = -1;
const int DR[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DC[] = {-1, 0, 1, -1, 1, -1, 0, 1};

typedef struct dllnode {

    char ch;
    struct dllnode* prev;
    struct dllnode* next;

} dllnode;

dllnode* getStartNode(dllnode* currentNode) {

    while(currentNode->prev != NULL) {
        
        currentNode = currentNode->prev;
        
    }
    return currentNode;
    
}

void printWord(dllnode* startNode) {
    
    dllnode* currentNode = startNode;
    while(currentNode != NULL) {
        
        printf("%c", currentNode->ch);
        currentNode = currentNode->next;
        
    }
    printf("\n");
    
}



int main(void) {

    int numRows, numCols;
    dllnode*** strandsGrid;

    scanf("%d %d", &numRows, &numCols);
    strandsGrid = (dllnode***)malloc(numRows * sizeof(dllnode**));
    for(int a = 0; a < numRows; a++) {

        strandsGrid[a] = (dllnode**)malloc(numCols * sizeof(dllnode*));
        
    }
    for(int b = 0; b < numRows; b++) {
        
        for(int c = 0; c < numCols; c++) {

            strandsGrid[b][c] = (dllnode*)malloc(sizeof(dllnode));
            
        }
        
    }

for(int d = 0; d < numRows; d++) {
    
    for(int e = 0; e < numCols; e++) {
        
        scanf(" %c", &strandsGrid[d][e]->ch);
        
    }
    
}

for(int g = 0; g < numRows; g++) {
    
    for(int h = 0; h < numCols; h++) {
        
        int nextDirection;
        scanf("%d", &nextDirection);
        if(nextDirection == NULLPTR) {
         
            strandsGrid[g][h]->next = NULL;
            
        } else {

            int nextRow = g + DR[nextDirection];
            int nextCol = h + DC[nextDirection];
            strandsGrid[g][h]->next = strandsGrid[nextRow][nextCol];
            
        }
        
    }
    
}

for(int i = 0; i < numRows; i++) {
    
    for(int j = 0; j < numCols; j++) {

        int prevDirection;
        scanf("%d", &prevDirection);
        if(prevDirection == NULLPTR) {
            
            strandsGrid[i][j]->prev = NULL;
            
        } else {

            int prevRow = i + DR[prevDirection];
            int prevCol = j + DC[prevDirection];
            strandsGrid[i][j]->prev = strandsGrid[prevRow][prevCol];
            
        }
        
    }
    
}
    
    return 0;
  
}
