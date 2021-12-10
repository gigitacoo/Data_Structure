#include "SortAlgorithms.h"

/**
 * 直接插入排序，时间复杂度O(n^2)
 **/
void StraightInsertSort(List R, int n){
    int i,j;
    for(i = 2; i <=n; i++){             //n为表长，从第二个记录开始插入
        R[0] = R[i];                    //第i个记录复制成岗哨，R[0]是岗哨
        j = i-1;                        //从第1个开始比较
        while(R[0].key < R[j].key){     //与岗哨比较大于的向后挪一位
            R[j+1] = R[j];              //向后挪动1位
            j--;
        }
        R[j+1] = R[0];                  //将第i个记录插入到序列中
    }
}
/**
 * 冒泡排序，时间复杂度O(n^2)
 * 该算法从0开始计算，不同于插入排序用0当作岗哨
**/
void BubbleSort(List R, int n){
    int i, j, endsort;
    Record temp;
    for(i = 0; i < n; i++){             
        endsort = 0;                        //endsort标识无可排序
        for(j = 0; j < n-i-1;j++){          //n-i最大为20，j不大于20
            if(R[j].key > R[j+1].key){
                temp = R[j];
                R[j] = R[j+1];
                R[j+1] = temp;
                endsort = 1;
            }
        }
        if(endsort == 0){
            break;
        }
    }
}
/**
 * 快速排序
 * 平均效率O(nlog2n)
 * 最坏情况下，即对已经排好的序列近似于O(n^2)
 **/
int quickPartition(List R, int low, int high){
    Record x = R[low];                                  //置初值
    while (low < high){
        while(low < high && R[high].key >= x.key){      //自尾端进行比较，将比x小的移动到低端
            high--;
        }
        R[low] = R[high];
        while(low < high && R[low].key <= x.key){       //自前端进行比较，将比x大的移动到高端
            low++;
        }
        R[high] = R[low];
    }
    R[low] = x;                                         //一趟快速排序后将x移到其最终位置
    return low;
}
void quickSort(List R, int low, int high){
    if(low < high){
        int temp = quickPartition(R, low, high);
        quickSort(R, low, temp - 1);
        quickSort(R, temp + 1, high);
    }
}

/**
 * 直接选择排序
**/
void selectSort(List R, int n){
    int i, j, min;
    Record tmp;
    for(i = 0; i < n;i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(R[j].key < R[min].key){
                min = j;
            }
        }
        if(min != i){
            tmp = R[min];
            R[min] = R[i];
            R[i] = tmp;
        }
    }
}

/**
 * 堆排序
 * 堆的定义：{k1,k2,...,kn} 满足：ki <= k2i && ki <= k(2i+1) 或者 ki >= k2i && ki >= k(2i+1)
 * 最小堆：{13,40,27,88,55,34,65,92}
 * 最大堆：{92,65,88,40,55,34,13,27}
 *                 13(1)
 *           40(2)       27(3)
 *       88(4)  55(5)  34(6)  65(7)
 *    92(8)
 * 
 * 建堆：
**/

void Sift(List R, int k, int m){
    //假设R[k], R[k+1],...,R[m]是以R[k]为根的完全二叉树
    int i,j,x;
    Record t;
    i=k;j=2*i;
    x=R[k].key;
    t=R[k];
    while(j <= m){
        if((j<m)&&(R[j].key>R[j+1].key)){
            j++;
        }
        if(x<R[j].key){
            break;
        } else {
            R[i]=R[j];
            i=j;
            j=2*i;
        }
    }
    R[i]=t;
}

void HeapSort(List R, int n){
    int i;
    for(i = n/2;i>=1;i--){
        Sift(R,i,n);
    }
    for(i=n;i>=2;i--){
        Record tmp = R[1];
        R[1] = R[i];
        R[i] = tmp;
        Sift(R,1,i-1);
    }
}