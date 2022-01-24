#include <stdio.h>
#include <assert.h>

#define NUMBER_OF_MAJOR_COLORS 5
#define NUMBER_OF_MINOR_COLORS 5

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct colorPair
{
	int pairNumber;
	char* majorCol;
	char* minorCol;
}ColorPairs[NUMBER_OF_MAJOR_COLORS * NUMBER_OF_MINOR_COLORS];

int formColorMap(){
	int i = 0, j = 0, counter = 0;
	for(i = 0; i < NUMBER_OF_MAJOR_COLORS; i++) {
        for(j = 0; j < NUMBER_OF_MINOR_COLORS; j++) {
        	ColorPairs[counter].pairNumber = i * 5 + j;
        	ColorPairs[counter].majorCol = majorColor[i];
        	ColorPairs[counter].minorCol = minorColor[i];
        	counter++;
        }
    }
    return i * j;
}

//function to generate correct mapping
//int formColorMap(){
//	int i = 0, j = 0, counter = 0;
//	for(i = 0; i < NUMBER_OF_MAJOR_COLORS; i++) {
//        for(j = 0; j < NUMBER_OF_MINOR_COLORS; j++) {
//        	ColorPairs[counter].pairNumber = counter+1;
//        	ColorPairs[counter].majorCol = majorColor[i];
//        	ColorPairs[counter].minorCol = minorColor[j];
//        	counter++;
//        }
//    }
//    return i * j;
//}

void printColorMap() {
    int i = 0;
    for(i = 0; i < NUMBER_OF_MAJOR_COLORS * NUMBER_OF_MINOR_COLORS; i++) {
            printf("%d | %s | %s\n", ColorPairs[i].pairNumber, ColorPairs[i].majorCol, ColorPairs[i].minorCol);
    }
}

void testColorMap()
{
	int i=0, j=0, counter = 0;
	for(i=0; i<NUMBER_OF_MAJOR_COLORS ;i++)
	{
		for(j=0 ; j<NUMBER_OF_MINOR_COLORS ; j++)
		{
			assert(ColorPairs[counter].pairNumber == counter+1);
			assert(ColorPairs[counter].majorCol == majorColor[i]);
			assert(ColorPairs[counter].minorCol == minorColor[j]);
			counter++;
		}
	}
}

int main() {
	int result = formColorMap();
	assert(result == 25);
    printColorMap();
    testColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
