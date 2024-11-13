#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size = 0;
    printf("Enter number of students in the class: ");
    scanf("%d", &size);
    float *averageScores = (float *)malloc(sizeof(float) * size);
    printf("Enter average scores of %d students \n", size);
    for (int i = 0; i < size; i++)
        scanf("%f", &averageScores[i]); // avgscores + i)

    printf("Average scores of %d students are \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%-7.2f", averageScores[i]);
    }
}