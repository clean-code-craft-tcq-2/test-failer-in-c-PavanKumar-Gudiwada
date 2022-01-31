#include <stdio.h>
#include <assert.h>

#define FSW_ENVIRONMENT_REAL 0
#define FSW_ENVIRONMENT_TEST 1

#define FSW_ENVIRONMENT FSW_ENVIRONMENT_REAL

#define NUMBER_OF_MAJOR_COLORS 5
#define NUMBER_OF_MINOR_COLORS 5

int formColorMap();
int formColorMapStub();

#if(FSW_ENVIRONMENT == FSW_ENVIRONMENT_REAL)
	int (*colorMapMaker)() = &formColorMap;
#else
	int (*colorMapMaker)() = &formColorMapStub;
#endif

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct colorPair
{
	int pairNumber;
	const char* majorCol;
	const char* minorCol;
}ColorPairs[NUMBER_OF_MAJOR_COLORS * NUMBER_OF_MINOR_COLORS];

int formColorMapStub(){
	int i = 0, j = 0;
	for(i = 0; i < NUMBER_OF_MAJOR_COLORS; i++) {
        for(j = 0; j < NUMBER_OF_MINOR_COLORS; j++) {
        	ColorPairs[(i * 5) + j].pairNumber = i * 5 + j;
        	ColorPairs[(i * 5) + j].majorCol = majorColor[i];
        	ColorPairs[(i * 5) + j].minorCol = minorColor[i];
        }
    }
    return i * j;
}

int index2String(int majorNumber, int minorNumber)
{
	return (majorNumber * 5) + minorNumber + 1;
}

const char* majorIndex2Color(int majorIndex)
{
	return majorColor[majorIndex];
}

const char* minorIndex2Color(int minorIndex)
{
	return minorColor[minorIndex];
}

//function to generate correct mapping
int formColorMap(){
	int i = 0, j = 0;
	for(i = 0; i < NUMBER_OF_MAJOR_COLORS; i++) {
        for(j = 0; j < NUMBER_OF_MINOR_COLORS; j++) {
        	ColorPairs[(i * 5) + j].pairNumber = index2String(i,j);
        	ColorPairs[(i * 5) + j].majorCol = majorIndex2Color(i);
        	ColorPairs[(i * 5) + j].minorCol = minorIndex2Color(j);
        }
    }
    return i * j;
}

const char* formatInfo(int pairNumber, const char* majorColorName, const char* minorColorName)
{
	static char rowInfo[80];
	sprintf(rowInfo, "%11d | %-11s | %-14s \n", pairNumber, majorColorName, minorColorName);
	return rowInfo;
}

void printColorMap() {
	static int i = 0;
    static const char* rowInfo;
	
	printf("\n---------Color Codes Table-------------\n");
	printf("Pair number | Major Color | Minor color\n");
	printf("---------------------------------------\n");
	
    for(i = 0; i < NUMBER_OF_MAJOR_COLORS * NUMBER_OF_MINOR_COLORS; i++) {
    		rowInfo = formatInfo(ColorPairs[i].pairNumber, ColorPairs[i].majorCol, ColorPairs[i].minorCol);
            printf("%s", rowInfo);
    }
}

void testColorMap()
{
	int i=0, j=0;
	for(i=0; i<NUMBER_OF_MAJOR_COLORS ;i++)
	{
		for(j=0 ; j<NUMBER_OF_MINOR_COLORS ; j++)
		{
			assert(ColorPairs[(i * 5) + j].pairNumber == (i * 5) + j + 1);
			assert(ColorPairs[(i * 5) + j].majorCol == majorColor[i]);
			assert(ColorPairs[(i * 5) + j].minorCol == minorColor[j]);
		}
	}
}

int main() {
	int result = (*colorMapMaker)();
	assert(result == 25);
    printColorMap();
    testColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
