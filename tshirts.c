#include <stdio.h>
#include <string.h>
#include <assert.h>

char sizeName[4] = "\0";

char* size(int cms) {
    if((cms >= 36)&&(cms < 38)) {
        strcpy(sizeName, "S");
    } else if(cms >= 38 && cms < 40) {
        strcpy(sizeName, "M");
    } else if(cms >= 40 && cms < 42) {
        strcpy(sizeName, "L");
    } else if(cms >= 42 && cms < 44){
    	strcpy(sizeName, "XL");
	} else if(cms >= 44 && cms <= 46){
    	strcpy(sizeName, "XXL");
	} else if((cms < 36)||(cms > 46))
    {
    	strcpy(sizeName, "NA");
	}
    return sizeName;
}

int main() {
    assert(strcmp(size(37), "S") == 0);
    assert(strcmp(size(38), "M") == 0);
    assert(strcmp(size(40), "L") == 0);
    assert(strcmp(size(43), "XL") == 0);
    assert(strcmp(size(46), "XXL") == 0);
    assert(strcmp(size(-38), "NA") == 0);
    assert(strcmp(size(10), "NA") == 0);
    assert(strcmp(size(100), "NA") == 0);
    
    printf("All is well (maybe!)\n");
    return 0;
}
