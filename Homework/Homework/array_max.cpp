#include <cstdio>


int findMaxScore(int score[], int size)
{
    int max = score[0];
    for (int i = 1; i < size; i++) {
        if (score[i] > max) {
            max = score[i];
        }
    }
    return max;
}

int main()
{
    int result;

   
    int scoreSet1[6] = { 3, 7, 2, 9, 10, 5 };
    int scoreSet2[3] = { -10, -5, -3 };
    int scoreSet3[5] = { 100, 200, 300, 50, 400 };
    int scoreSet4[4] = { 0, 0, -2, 0 };
    int scoreSet5[1] = { 10000 };

    
    result = findMaxScore(scoreSet1, 6);
    printf("%d\n", result);

    result = findMaxScore(scoreSet2, 3);
    printf("%d\n", result);

    result = findMaxScore(scoreSet3, 5);
    printf("%d\n", result);

    result = findMaxScore(scoreSet4, 4);
    printf("%d\n", result);

    result = findMaxScore(scoreSet5, 1);
    printf("%d\n", result);

    return 0;
}
