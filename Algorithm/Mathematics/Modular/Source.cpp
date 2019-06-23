#include <cstdio>
#include <cmath>

void ModularAddition(int A, int B, int M);
void ModularSubtraction(int A, int B, int M);
void ModularMultiple(int A, int B, int M);
void ModularDivide(int A, int B, int M);
void ModularSquare(int A, int B, int M);

int main()
{
    int A = 18;
    int B = 5;
    int M = 7;

    printf("[µ¡¼ÀÀÇ ³ª¸ÓÁö ¿¬»ê]\n");
    ModularAddition(A, B, M);
    printf("\n");

    printf("[»¬¼ÀÀÇ ³ª¸ÓÁö ¿¬»ê]\n");
    ModularSubtraction(A, B, M);
    printf("\n");

    printf("[°ö¼ÀÀÇ ³ª¸ÓÁö ¿¬»ê]\n");
    ModularMultiple(A, B, M);
    printf("\n");

    printf("[³ª´°¼ÀÀÇ ³ª¸ÓÁö ¿¬»ê]\n");
    //ModularOfDivide(A, B, M);
    printf("ERROR\n\n");

    printf("[Á¦°öÀÇ ³ª¸ÓÁö ¿¬»ê]\n");
    ModularSquare(A, B, M);

    return 0;
}

void ModularAddition(int A, int B, int M)
{
    int result[2] = { 0 };

    result[0] = (A + B) % M;
    result[1] = ((A % M) + (B % M)) % M;

    printf("(%d + %d) %% %d = %d\n", A, B, M, result[0]);
    printf("((%d %% %d) + (%d %% %d)) %% %d = %d\n", A, M, B, M, M, result[1]);
}

void ModularSubtraction(int A, int B, int M)
{
    int result[3] = { 0 };

    result[0] = (A - B) % M;
    result[1] = ((A % M) - (B % M)) % M;
    result[2] = ((A % M) - (B % M) + M) % M;

    printf("(%d - %d) %% %d = %d\n", A, B, M, result[0]);
    printf("((%d %% %d) - (%d %% %d)) %% %d = %d\n", A, M, B, M, M, result[1]);
    printf("((%d %% %d) - (%d %% %d) + %d) %% %d = %d\n", A, M, B, M, M, M, result[2]);
}

void ModularMultiple(int A, int B, int M)
{
    int result[2] = { 0 };

    result[0] = (A * B) % M;
    result[1] = ((A % M) * (B % M)) % M;

    printf("(%d * %d) %% %d = %d\n", A, B, M, result[0]);
    printf("((%d %% %d) * (%d %% %d)) %% %d = %d\n", A, M, B, M, M, result[1]);
}

void ModularDivide(int A, int B, int M)
{
    int result[2] = { 0 };

    result[0] = (A / B) % M;
    result[1] = ((A % M) / (B % M)) % M;

    printf("(%d / %d) %% %d = %d\n", A, B, M, result[0]);
    printf("((%d %% %d) / (%d %% %d)) %% %d = %d\n", A, M, B, M, M, result[1]);
}

void ModularSquare(int A, int B, int M)
{
    int result[2] = { 0 };

    result[0] = (int)pow((double)A, (double)B) % M;
    result[1] = (int)pow((double)(A % M), (double)B) % M;

    printf("(%d ^ %d) %% %d = %d\n", A, B, M, result[0]);
    printf("((%d %% %d) ^ %d) %% %d = %d\n", A, M, B, M, result[1]);
}
