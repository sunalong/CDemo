//
// Created by sunalong on 17/2/27 17:38.
// Email:466210864@qq.com
//

#include <iostream>

void newAndDelete();

void yinyong();

using namespace std;

int main() {
    newAndDelete();
    yinyong();
}

/**
 * 引用
 */
void yinyong() {
    int a = 5;
    int b = 7;
    int &c = a;
//    int &d = 20;
    printf("c 的地址：%p，a 的地址：%p\n", &c, &a);
    printf("c 的值：%d，a 的值：%d\n", c, a);
}

/**
 * new 和 delete 匹配，使用 new 创建出来的空间，必须使用 delete 来释放
 * 使用 malloc 分配的空间，使用 free 来释放
 */
void newAndDelete() {
    int *pMalloc = (int *) malloc(sizeof(int));
    *pMalloc = 11;
    printf("使用 malloc:%d\n", *pMalloc);
    free(pMalloc);

//    int *p = new int(10);//创建一个 int 类型的指针并赋值为10
    int *pNew = new int;
    *pNew = 15;
    cout << "使用 new:" << *pNew << endl;
    delete (pNew);

    int *pArr = new int[5];//创建一个 int 数组类型的指针，数组长度为5
    for (int i = 0; i < 5; i++) {
        pArr[i] = i + 1;
        cout << pArr[i] << endl;
    }
    delete[]pArr;//删除数组指针 pArr
//    delete pArr;//只删除数组中第一个指针变量，引起内在泄漏

}