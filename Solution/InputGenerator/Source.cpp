#include <cstdio>

#include "Array.h"
#include "Tree.h"

int main()
{
    FILE* pOutputFile = fopen("output.txt", "wt");

    string result = "";

    // [Array]
    {
        result = ConvertArray();
    }

    // [Tree]
    {
        int nodeNum = 19; // 노드 번호의 최대
        int rootNum = 1; // 루트 노드외 번호

        result = ConvertTree(nodeNum, rootNum);
    }

    fprintf(pOutputFile, "%s\n", result.c_str());

    fclose(pOutputFile);

    return 0;
}
