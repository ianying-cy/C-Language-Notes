#include <stdio.h>

int main()
{
    const int a = 10;
    a = 20; // error: assignment of read-only variable ‘a’
    // a = 20; // error: assignment of read-only variable ‘a’


    const int *p = &a;
    *p = 20; // error: assignment of read-only location ‘*p’

    char a = 'A';
    const char *p = &a;
    *p = 'B'; // error: assignment of read-only location ‘*p’
    return 0;
}

// 使用场景--保护数据不被修改
#include <stdio.h>

int addUser()
{
    const int a = 10;
    const int *p = &a;
    printf("%d\n", *p);
    return 0;
}

// 使用场景--提高代码可读性

const double PI = 3.1415926;

double calculateCircleArea(double r)
{
    return PI * r * r;
}

// 使用场景--函数参数中，防止函数修改参数的值

void printArray(const int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", p[i]);   // 可以读取，但不能修改p[i]的值
    }
}

// 使用场景--防止函数返回值被修改

#include <stdio.h>

typedef struct {
    int id;
    const char *name; // 使用 const 修饰，防止修改
} User;

const User* getUser() {
    static User user = {1, "Alice"};
    return &user; // 返回指向 User 的指针
}

int main() {
    const User *userPtr = getUser();
    
    printf("User ID: %d\n", userPtr->id);
    printf("User Name: %s\n", userPtr->name);
    
    // 尝试修改返回的指针指向的内容，将会导致编译错误
    // userPtr->name = "Bob"; // 错误：无法修改 const 数据

    return 0;
}

// 使用场景--初始化数组大小
int arrSize()
{
    const int n = 10;
    int a[n] = {0};
    return 0;
}