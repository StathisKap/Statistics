#include <stdio.h>
#include <math.h>

void main(int argc, char *argv[])
{
    char *name = argv[1];
    FILE * input = fopen(name,"r");
    int count = 0;
    float mean=0,variance=0,standard_deviation=0, measurements=0;

    while(EOF && fscanf(input, "%f", &measurements)==1)
    {
        mean +=measurements;
        count++;
    }
    mean = mean / count;

   fseek(input, 0, SEEK_SET);
    
    while(EOF && fscanf(input, "%f", &measurements)==1)
    {
        variance += pow((measurements - mean),2);
        
    }
    variance = variance/(count-1);

    standard_deviation = sqrt(variance);

    printf("Mean = %.3f\nVariance = %.3f\nStandard Deviation = %.3f\nCoefficient of Variation = %.3f\n",mean,variance,standard_deviation,standard_deviation/mean);
    fclose(input);

}