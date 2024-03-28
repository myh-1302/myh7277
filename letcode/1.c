#include <stdio.h>
#include <assert.h>
#include <string.h>
// 从下标 0 开始遍历 arr 中的每个下标 i ，并将包含整数 arr[i] 的 mat 单元格涂色。
// 请你找出 arr 中第一个使得 mat 的某一行或某一列都被涂色的元素，并返回其下标 i 。
int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize){
    int m = matSize, n = matColSize[0];  // 获取矩阵的行数和列数
    int row[m], col[n];  // 创建行和列的数组
    memset(row, 0, sizeof(row));  // 将行数组的所有元素设置为 0
    memset(col, 0 , sizeof(col));  // 将列数组的所有元素设置为 0

    // 遍历 arr 数组
    for(int i =0; i < arrSize; i++){
        int num = arr[i];  // 获取当前元素
        int x = (num - 1) / n;  // 计算元素在矩阵中的行索引
        int y = (num - 1) % n;  // 计算元素在矩阵中的列索引
        row[x]=1;  // 将行数组的对应元素设置为 1
        col[y]=1;  // 将列数组的对应元素设置为 1

        int rowComplete=1,colComplete=1;  // 初始化行和列的完成状态为 1

        // 检查行数组是否全部为 1
        for(int j=0;j<m;j++){
            if(row[j]==0){
                rowComplete=0;  // 如果找到一个元素为 0，将行的完成状态设置为 0
                break;  // 并跳出循环
            }
        }

        // 检查列数组是否全部为 1
        for(int j=0;j<n;j++){
            if(col[j]==0){
                colComplete=0;  // 如果找到一个元素为 0，将列的完成状态设置为 0
                break;  // 并跳出循环
            }
        }

        // 如果行或列的完成状态为 1，返回当前的索引
        if(rowComplete==1||colComplete==1){
            return i;
        }
    }

    // 如果没有找到已经完成的行或列，返回 -1
    return -1;
}
void test_firstCompleteIndex() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int mat1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int* mat1_ptrs[2] = {mat1[0], mat1[1]};
    int matColSize1 = 3;
    assert(firstCompleteIndex(arr1, 6, mat1_ptrs, 2, &matColSize1) == 2);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int mat2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* mat2_ptrs[3] = {mat2[0], mat2[1], mat2[2]};
    int matColSize2 = 3;
    assert(firstCompleteIndex(arr2, 9, mat2_ptrs, 3, &matColSize2) == 2);

    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int mat3[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int* mat3_ptrs[3] = {mat3[0], mat3[1], mat3[2]};
    int matColSize3 = 4;
    assert(firstCompleteIndex(arr3, 12, mat3_ptrs, 3, &matColSize3) == 3);
}

int main() {
    test_firstCompleteIndex();
    printf("全部通关\n");
    return 0;
}