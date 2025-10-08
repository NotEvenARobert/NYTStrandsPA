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


int main(void) {

    int numRows, numCols;
    dllnode*** strandsGrid;

    scanf("%d %d", &numRows, &numCols);
    strandsGrid = (dllnode***)malloc(numRows * sizeof(dllnode**));
    for(int a = 0; a < numRows; a++) {

        strandsGrid[a] = (dllnode**)malloc(numCols * sizeof(dllnode*));
        
    }
    for(int a = 0; a < numRows; a++) {
        
        for(int b = 0; b < numCols; b++) {

            strandsGrid[a][b] = (dllnode*)malloc(sizeof(dllnode));
            
        }
        
    }
    
    return 0;
  
}
