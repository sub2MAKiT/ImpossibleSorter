#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char * allChars = malloc(sizeof(char)*256);
    size_t sizeOfAllChar = 256;
    for(unsigned int i = 0; i < 256;i++)
        allChars[i] = i;

    unsigned short * allShorts = malloc(sizeof(short)*65536);
    size_t sizeOfAllShorts = 65536;
    for(unsigned int i = 0; i < 65536;i++)
        allShorts[i] = i;

    // in this case I will be lazy, because this is just a helping program to generate files (it can be slow)
    FILE * MKTFILE = fopen("./smallSort.MKTI","wb");
    
    while(sizeOfAllChar > 0)
    {
        int random = (rand()%sizeOfAllChar);
        fwrite(&allChars[random],1,sizeof(char)/*profacionale*/,MKTFILE);
        sizeOfAllChar--;
        printf("\n wrote char with the value: %d",allChars[random]);
        for(int i = random;i < sizeOfAllChar;i++)
            allChars[i] = allChars[i+1];
        allChars = realloc(allChars,sizeOfAllChar);
    }
    
    fclose(MKTFILE);

    MKTFILE = fopen("./hugeSort.MKTI","wb");
    
    while(sizeOfAllShorts > 0)
    {
        int random = (rand()%sizeOfAllShorts);
        fwrite(&allShorts[random],1,sizeof(short)/*profacionale again (I could've just write 2)*/,MKTFILE);
        sizeOfAllShorts--;
        printf("\n wrote char with the value: %d",allShorts[random]);
        for(int i = random;i < sizeOfAllShorts;i++)
            allShorts[i] = allShorts[i+1];
        allShorts = realloc(allShorts,sizeOfAllShorts*2);
    }
    
    fclose(MKTFILE);

    free(allChars);
    free(allShorts);
    return 0;
}