#include <stdlib.h>

//将序列每相邻两个数字进行归并操作，形成{\displaystyle ceil(n/2)}{\displaystyle ceil(n/2)}个序列，排序后每个序列包含两/一个元素
//若此时序列数不是1个则将上述序列再次归并，形成{\displaystyle ceil(n/4)}{\displaystyle ceil(n/4)}个序列，每个序列包含四/三个元素
//重复步骤2，直到所有元素排序完毕，即序列数为1

int min(int x, int y) {
    return x < y ? x : y;
}
void merge_sort(int arr[], int len) {
    int *a = arr;
    int *b = (int *) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

