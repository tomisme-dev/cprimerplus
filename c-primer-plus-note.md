# 51. Introducing C

## 1. 函数的形式

1. 参数

   - actual argument
   -  formal argument 

2. 内联函数， gcc编译时需要带上```-Winline```参数

   ```c
   #include <stdio.h>
   
   //函数定义为inline即:内联函数
   static inline char *dbtest(int a)
   {
       return (a % 2 > 0) ? "1" : "0";
   }
   
   int main()
   {
       int i = 0;
       for (i = 1; i < 100; i++)
       {
           printf("i:%d    奇偶性:%s /n", i, dbtest(i));
       }
   }
   ```

   



# 2. Data and C

## 1. 不同数据的输出

1. 格式化输出八进制和十六进制

   ```c
   // %#o 加上#后，输出的八进制前面带0
   // %#x 加上#后，输出的十六进制前面带0x
   printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
   ```

2. 转译字符， "x61" 等价于 "a"

   序列|含义
   -|-
   \0oo | Octal value. (o represents an octal digit.)
   \xhh | Hexadecimal value. (h represents a hexadecimal digit.)
   
   

## 2. Flushing the Output

1. 在使用printf后，如果立即使用scanf，最好在printf中加一个回车，刷新输出流

```c
printf("Enter your desired monthly salary:\n");
scanf("%f", &salary);
```

2. 另一种刷新output方式是采用```flush```函数



# 3. Character Strings

1. Constants and the C Preprocessor

   ```c
   #define PI 3.14
   
   int main(int argc, char const *argv[])
   {
       double x = 5 * PI;
       return 0;
   }
   
   ```

   通过下列gcc指令可以输出预编译后的文件

   ```shell
   gcc -E test_define.c -o test_define.i
   ```

2. The ```const``` modifier

   ```c
   int main(int argc, char const *argv[])
   {
       const int x = 14;
       x = 9; // compile error, const修饰的数据不能修改
       return 0;
   }
   ```

3. limits.h and float.h文件中定义了一些常用的常量

   ```
   // limits.h
   INT_MAX
   INT_MIN
   UINT_MAX
   LONG_MAX
   LONG_MIN
   ...
   
   // float.h
   FLT_MANT_DIG
   FLT_DIG
   FLT_MIN
   FLT_MAX
   DBL_MAX
   ...
   ```

4. printf函数

   ```c
   // 字符串需要换行续写的方法
   int main(int argc, char const *argv[])
   {
       // 方法1：用\来换行续写
       printf("1.hello\
   world\n");
   	// 方法2：用字符串拼接的方法
       printf("2.hello"
       "world\n");
   
       return 0;
   }
   
   ```

5. scanf函数

   ```c
   // %*d代表跳过这个整数
   scanf("%*d %*d %d", &n); // 跳过前两个，取第三个整数
   ```



# 4. Operators, Expressions, and Statements



# 5. C Control Statements: Looping

1. Interspersing calls to getchar() with calls to scanf() can cause problems when scanf() leaves a newline character in the input just before a call to getchar(). By being aware of this problem, however, you can program around it
2. Unix systems enable you to simulate the end-of-file condition from the keyboard by pressing Ctrl+D at the beginning of a line; DOS systems use Ctrl+Z for the same purpose.
3. Many programs use getchar() to read input character-by-character. Typically, systems use linebuffered input, meaning that input is transmitted to the program when you press Enter. Pressing Enter also transmits a newline character that may require programming attention



# 6. Function

## 6.1 Function Prototyping

1. 函数使用前需要声明

    ```c
    int imax(int, int);
    int imax(int a, int b);
    // 声明时，void参数需要显式给出，否则编译器会推断为int类型参数
    void print_name(void);
    // 对可变参数方法的声明
    int printf(const char *, ...);
    ```

2. 函数类型的声明与使用

   ```c
   typedef void (*func)(char *);
   
   void println(char *string);
   
   
   int main(int argc, char const *argv[])
   {
       func f = println;
       f("world");
       println("hello");
   
       return 0;
   }
   
   
   void println(char *string) {
       printf("%s\n", string);
   }
   ```

3. stdio.h中的部分声明

   ```c
   // 表明printf的实现在其他文件中
   extern int printf (const char *__restrict __format, ...);
   ```

   

# 7. Arrays And Pointers

## 7.1 Arrasy

1. The array members are like ordinary variables—if you don’t initialize them, they might have any value

2. That is, if you don’t initialize an array at all, its elements, like uninitialized ordinary variables, get garbage values, but if you partially initialize an array, the remaining elements are set to 0.

3. 计算数组长度方法

   ```c
   const int days[] = {31,28,31,30,31,30,31,31,30,31};
   int size = sizeof(days) / sizeof(days[0]);
   ```

4. 数组的选择性初始化

   ```c
   int days[12] = {31,28, [4] = 31,30,31, [1] = 29};
   // 输出结果
   /*
   1 31
   2 29
   3 0
   4 0
   5 31
   6 30
   7 31
   8 0
   9 0
   10 0
   11 0
   12 0
   */
   
   int staff[] = {1, [6] = 4, 9, 10}; // staff数组元素个数：9
   ```

## 7.2 Pointer

1. const关键字

   ```c
   int a = 1;
   int *p = &a;
   const int **pp = &p; 
   // **pp = 7;  // 这样赋值编译报错
   a = 9; // 这样编译不报错
   
   int b = 9;
   int *bp = &b;
   pp = &bp; // 这样编译不报错
   ```

2. const的三种使用场景

   - constant arrays

     ```c
     #define MONTHS 12
     const int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
     days[9] = 44; /* compile error */
     
     double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
     const double * pd = rates; // pd points to beginning of the array
     *pd = 29.89; // not allowed
     pd[2] = 222.22; // not allowed
     rates[0] = 99.99; // allowed because rates is not const
     pd++; /* make pd point to rates[1] -- allowed */
     
     double *pd2 = pd; // not allowed, 不能将一个const的指针赋值给不是const的指针
     ```

     

   - constant pointers

     ```c
     double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
     double * const pc = rates; // pc points to beginning of the array
     pc = &rates[2]; // not allowed to point elsewhere
     *pc = 92.99; // ok -- changes rates[0]
     ```

   - pointers to constants

   ```c
   const int a = 9;
   a = 9; // not allow
   ```

3. 两次const使用，可以将pointer和value都设置为不可修改

   ```c
   double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
   const double * const pc = rates;
   pc = &rates[2]; // not allowed
   *pc = 92.99; // not allowed
   ```

## 7.3 指针和多维数组

1. 案例分析

   ```c
   int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
   ```

   | 表达式           | 含义                                                         |
   | ---------------- | ------------------------------------------------------------ |
   | zippo            | the address of the first two-int element                     |
   | zippo+2          | the address of the third two-int element                     |
   | *(zippo+2)       | the third element, a two-int array, hence the address of its first element, an int |
   | *(zippo+2) + 1   | the address of the second element of the two-int array, also an int |
   | *((zippo+2) + 1) | the value of the second int in the third row (zippo[2]\[1\]) |

2. Pointers to Multidimensional Arrays

   ```c
   int (* pz)[2]; // pz points to an array of 2 ints
   
   // 使用
   int main(int argc, char const *argv[])
   {
       int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
       int (* p2)[2] = zippo;
       for(int i = 0; i < 4; i++, p2++) {
           for(int j = 0; j < 2; j++) {
               printf("(%d, %d) = %d\n", i, j, (*p2)[j]);
           }
       }
       return 0;
   }
   ```

3. 二维数组作为函数参数的使用

   ```c
   #define COLS 4
   
   // 申明
   int sum2d(int (*ar)[COLS], int rows); // another syntax
   
   int sum2d(int ar[][COLS], int rows)
   {
       int r;
       int c;
       int tot = 0;
       for (r = 0; r < rows; r++)
           for (c = 0; c < COLS; c++)
           	tot += ar[r][c];
       return tot;
   }
   ```

4. 结合typedef

   ```c
   typedef int arr4[4]; // arr4 array of 4 int
   typedef arr4 arr3x4[3]; // arr3x4 array of 3 arr4
   int sum2(arr3x4 ar, int rows); // same as next declaration
   int sum2(int ar[3][4], int rows); // same as next declaration
   int sum2(int ar[][4], int rows); // standard form
   ```

## 7.4 Variable-Length Arrays (VLAs)

1. 声明方式, 注意：rows和cols必须出现在参数ar的前面

   ```c
   int sum2d(int rows, int cols, int ar[rows][cols]); // ar a VLA
   int sum2d(int ar[rows][cols], int rows, int cols); // invalid order
   ```

## 7.5 Compound Literals

1. 创建

   ```c
   (int []){50, 20, 90} // a compound literal with 3 elements
   
   int * pt1;
   pt1 = (int [2]) {10, 20};
   
   int (*pt2)[4]; // declare a pointer to an array of 4-int arrays
   pt2 = (int [2][4]) { {1,2,3,-9}, {4,5,6,-8} };
   ```

2. compound literal没有名字，因此创建时需将将某个指针指向它，以便后续使用

3. 使用场景，作为参数传递给函数

   ```c
   int sum(const int ar[], int n);
   ...
   int total3;
   total3 = sum((int []){4,4,4,5,5,5}, 6);
   ```

4. Keep in mind that a compound literal is a means for providing values that are needed only
   temporarily



# 8. Character Strings and String Functions
## 8.1 字符串数组与字符串常量的差异

1. 表现形式

   ```c
   char *str = "hello world";
   char arr[] = "hello world";
   ```

2. 差异点

   - 字符串常量存储在进程内存模型中的.rodata区域，而字符串数组存储在栈中
   - 字符串常量不可以修改，在符数组可以修改
   - 相同的字符串常量，具有相同的内存值
   - str可以执行++，而arr不可以

## 8.2 字符串二维数组

1. 表现形式

   ```c
   // 字符串常量数组
   char *arr1[] = {
       "hello", // 存放在.rodata区域
       "my world"
   }
   
   // 字符二维数组
   char arr2[][] = {
       "hello", // 存放在栈中
       "my world"
   }
   ```

2. 分析

   - arr1数组长度为2，里面存放的是指针
   - arr2数组里面存放的全都是char

## 8.3 字符串读取函数

1. fgets/fputs:  一次读一行，会读取换行符\n
2. gets_s/puts: 一次读一行，不会读取换行符\n



## 8.4 String-to-Number Conversions

1. ```atoi```

2. ```atol```

3. ```atof```

4. ```strtol```

5. ```strtoul```

6. ```strtod```

7. ```strtof```

   

# 9. Storage Classes, Linkage, and Memory Management
## 9.1 Five Storage Classes

| Storage Class                | Duration  | Scope | Linkage  | How Declared                                     |
| ---------------------------- | --------- | ----- | -------- | ------------------------------------------------ |
| automatic                    | Automatic | Block | None     | In a block                                       |
| register                     | Automatic | Block | None     | In a block with the keyword register             |
| static with external linkage | Static    | File  | External | Outside of all functions                         |
| static with internal linkage | Static    | File  | Internal | Outside of all functions with the keyword static |
| static with no linkage       | Static    | Block | None     | In a block with the keyword static               |

## 9.2 ANSI C Type Qualifiers

1. ```restrict```, designed to facilitate compiler optimizations. 只用于限定指针；该关键字用于告知编译器，所有修改该指针所指向内容的操作全部都是基于(base on)该指针的. The keyword restrict has two audiences:

    - One is the compiler, and it tells the compiler it is free to make certain assumptions concerning optimization

    - The other audience is the user, and it tells the user to use only arguments that satisfy the restrict requirements.

      

    **In general, the compiler can’t check whether you obey this restriction, but you flout it at your own risk**
    
2. ```_Atomic```,  to support concurrent programming,  but it is part of that optional support

    ```C
    #include <stdatomic.h> // 定义了相关原子操作
    
    _Atomic int count = 0;
    atomic_store(&count, 12);
    atomic_fetch_add(&count, 10);
    ```

    

3. ```const``` qualifier

   ```c
   const float * pf; /* pf points to a constant float value */
   float * const pt; /* pt is a const pointer */
   const float * const ptr; // ptr and *ptr are a const
   ```

4. The ```volatile ```Type Qualifier

   ```c
   volatile int loc1; /* loc1 is a volatile location */
   volatile int * ploc; /* ploc points to a volatile location */
   ```

   - The volatile qualifier tells the compiler that a variable can have its value altered by agencies other than the program
   - It is typically used for hardware addresses and for data shared with other programs or threads running simultaneously



# 10. File Input/Output

# 11. Structure and Other Data Forms

## 7.1 struct

1. 定义

   ```c
   // 方法1
   struct book {
       char title[MAXTITL];
       char author[MAXAUTL];
       float value;
   };
   struct book b1;
   
   // 方法2
   struct book {
       char title[MAXTITL];
       char author[MAXAUTL];
       float value;
   } b2;
   
   // 方法3
   struct {
       char title[MAXTITL];
       char author[MAXAUTL];
       float value;
   } b3;
   
   // 方法4
   typedef struct book {
       char title[MAXTITL];
       char author[MAXAUTL];
       float value;
   } t_book;
   t_book b4;
   
   // 方法5
   typedef struct {
       char title[MAXTITL];
       char author[MAXAUTL];
       float value;
   } t_book;
   t_book b5;
   ```

2. 初始化

   ```c
   // 方法1
   struct book library = {
       "The Pious Pirate and the Devious Damsel",
       "Renee Vivotte",
       1.95
   };
   
   // 方法2
   struct book library = {
       .value = 1.95,
       .title="The Pious Pirate and the Devious Damsel",
       .author="Renee Vivotte"
   };
   
   // 方法3：采用另一个struct来初始化自己
   struct book b1 = library; // 会将library中的值拷贝到b1这个新空间
   ```

3. ```struct```作为方法参数

   ```c
   void f(struct book b1); // b1采用值传递，也就是复制一份
   void f(struct book *b2) // b2是采用指针传递
   ```

4. Anonymous Structures (C11)， The anonymous feature becomes more useful with nested unions

   ```c
   // 定义
   struct student {
       int age;
       struct { // 匿名结构体
           char letf[20];
           char right[20];
       };
   } s_student;
   
   // 初始化
   struct student s1 = {12, {"left hand", "right hand"}};
   
   // 使用, 像使用内部变量一样直接使用匿名结构体中的数据
   char *left = s1.left;
   ```

## 7.2 Union

1. 定义

   ```c
   union hold {
       int digit;
       double bigfl;
       char letter;
   };
   ```

2. 初始化

   ```c
   union hold fit; // union variable of hold type
   union hold save[10]; // array of 10 union variables
   union hold * pu; // pointer to a variable of hold type
   
   union hold valA;
   valA.letter = 'R';
   union hold valB = valA; // initialize one union to another
   union hold valC = {88}; // initialize digit member of union
   union hold valD = {.bigfl = 118.2}; // designated initializer
   ```

3. 匿名union

   ```c
   struct car_data {
       char make[15];
       int status; /* 0 = owned, 1 = leased */
       union {
           struct owner owncar;
           struct leasecompany leasecar;
       };
   };
   ```

## 7.3 Enumerated Types

1. enum constants are type int; therefore, they can be used wherever you would use an int

2. 定义

   ```c
   // red默认值为0， 依次往后推
   enum spectrum {red, orange, yellow, green, blue, violet};
   
   // 给定每个枚举的值
   enum levels {low = 100, medium = 500, high = 2000};
   ```

3. 使用

   ```
   enum spectrum color;
   color = yello;
   ```

## 7.4 typedef

1. typedef的特点
   - Unlike #define, typedef is limited to giving symbolic names to types only and not to values
   - The typedef interpretation is performed by the compiler, not the preprocessor.
   - Within its limits, typedef is more flexible than #define
   
2. 使用

   ```c
   typedef unsigned char BYTE;
   typedef char * STRING;
   
   typedef struct complex {
       float real;
       float imag;
   } COMPLEX;
   
   // 复杂场景
   typedef char (* FRPTC ()) [5];
   
   ```

## 7.5 Fancy Declarations

案例

```c
// 变量声明
int board[8][8]; // an array of arrays of int
int ** ptr; // a pointer to a pointer to int
int * risks[10]; // a 10-element array of pointers to int
int (* rusks)[10]; // a pointer to an array of 10 ints
int * oof[3][4]; // a 3 x 4 array of pointers to int
int (* uuf)[3][4]; // a pointer to a 3 x 4 array of ints
int (* uof[3])[4]; // a 3-element array of pointers to 4-element arrays of int

// 函数声明
char * fump(int); // function returning pointer to char
char (* frump)(int); // pointer to a function that returns type char
char (* flump[3])(int);// array of 3 pointers to functions that return type char

// 结合typedef
typedef int arr5[5];
typedef arr5 * p_arr5;
typedef p_arr5 arrp10[10];
arr5 togs; // togs an array of 5 int
p_arr5 p2; // p2 a pointer to an array of 5 int
arrp10 ap; // ap an array of 10 pointers to array-of-5-int
```

## 7.6 Functions and Pointers

1. 声明

   ```c
   void (*pf)(char *); // pf a pointer-to-function
   ```

2. 使用

   ```c
   void ToUpper(char *);
   void ToLower(char *);
   int round(double);
   void (*pf)(char *);
   pf = ToUpper; // valid, ToUpper is address of the function
   pf = ToLower; // valid, ToLower is address of the function
   pf = round; // invalid, round is the wrong type of function
   pf = ToLower(); // invalid, ToLower() is not an address
   ```



# 8. Bit Fiddling

## 8.1 Bitwise Operators

1. Usage: Masks

   ```c
   flags = flags & MASK;
   ```

2. Usage: Turning Bits On (Setting Bits)

   ```c
   flags = flags | MASK;
   ```

3. Usage: Turning Bits Off (Clearing Bits)

   ```c
   flags = flags & ~MASK;
   ```

4. Usage: Toggling Bits

   ```c
   flags = flags ^ MASK;
   ```

5. Usage: Checking the Value of a Bit

   ```c
   (flags & MASK) == MASK
   ```

## 8.2 Bit Fields

1. 定义

   ```c
   struct {
       unsigned int autfd : 1; // 表明autfd占一个bit位
       unsigned int bldfc : 1;
       unsigned int undln : 1;
       unsigned int itals : 1;
   } prnt;
   
   struct {
       unsigned int code1 : 2;
       unsigned int code2 : 2;
       unsigned int code3 : 8; // code3占用8个bit位
   } prcode;
   
   
   struct {
       unsigned int field1 : 1;
       unsigned int : 2; // 代表中间空2个bit位
       unsigned int field2 : 1;
       unsigned int : 0; // padding, 代表下一个field3将对齐到下一个int
       unsigned int field3 : 1;
   } stuff;
   ```

2. 使用

   ```c
   prnt.itals = 0;
   prnt.undln = 1;
   ```

3. bit fields和具体机器实现相关，可移植性差，不建议使用

4. they are used for nonportable purposes, such as putting data in the exact form used by a particular hardware device.

## 8.3 Alignment Features (C11)

1. ```_Alignof```关键字，获取对齐的大小

   ```c
   size_t d_align = _Alignof(float); // 获取float数据在内存中对齐的大小
   ```

2. ```_Alignas```关键字，指定对齐内存的大小

   ```c
   char _Alignas(double) cz; // cz采用double对齐的方式
   ```

3.  可以使用 stdalign.h 头文件中的```alignas```, ```alignof```替换对应的关键字



# 9. The C Preprocessor and the C Library

获取预处理后的文本指令

```shell
gcc -E program.c
```



## 9.1 First Steps in Translating a Program

1. 将换行的文本调整为一行

   ```c
   printf("That's wond\
   erful!\n");
   
   //调整为
   printf("That's wonderful\n!");
   ```

2. 删除调注释

## 9.2 Manifest Constants: #define

1. 一般形式， 字符串替换

   ```c
   // 处理前
   #define PI 3.14
   double x = 3 * PI;
   
   // 处理后
   x = 3 * 3.14
   ```

2. 带参数的宏

   ```c
   // 处理前
   #define MAX(a,b) ((a>b)?(a):(b))
   double x = MAX(3,5);
   
   // 处理后
   x = ((3>5)?(3):(5))
   ```

3. 带#的宏，代表参数x的字符串

   ```c
   // 处理前
   #define F(x) #x#x"12"
   char * s = F(hello);
   
   // 处理后
   char * s = "hello""hello""12";
   ```

4. 带##的宏

   ```
   // 处理前
   #define F2(x) A##x##12
   int F(hello) = 9;
   
   // 处理后
   int Ahello12 = 9;
   ```

5. Variadic Macros: ```...``` and``` __VA_ARGS__```

   ```c
   // 处理前
   #define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
   PR(1, "x = %d\n", x);
   
   // 处理后
   printf("Message" "1" ": " "x = %d\n", x);
   ```

## 9.3 Macro or Function?

1. macro是字符串替换，因此占用空间
2. macro采用inline的方式，运行期间不需要额外调用函数，速度更快
3. macro是字符串替换，不需要考虑宏的参数类型问题

## 9.4 File Inclusion: #include

1. 使用

   ```c
   #include <stdio.h> // Searches directive>> system directories
   #include "hot.h" // Searches your current working directory
   #include "/usr/biff/p.h" // Searches the /usr/biff directory
   ```

## 9.5 Other Directives

1. The #undef Directive

   ```c
   #define LIMIT 400
   // Then the directive
   #undef LIMIT
   ```

2. 条件判断

   ```c
   #if
   #elif
   #else
   #endif
   
   #ifdef // 等价于 #if defined (VAX)
   #ifndef
   ```

3. 可通过条件判断解决重复引入同一个头文件定义问题

   ```c
   // define.h头文件
   #ifndef DEFINE_H_
   
   #define DEFINE_H_
   #define SIZE 100
   
   #endif
   ```

   ```c
   // 重复引入
   #include "define.h"
   #include "define.h"
   ```

4. #if和#elif的使用

   ```c
   // 表达方式1
   #if SYS == 1
   	#include "ibmpc.h"
   #elif SYS == 2
   	#include "vax.h"
   #elif SYS == 3
   	#include "mac.h"
   #else
   	#include "general.h"
   #endif
   
   // 表达方式2
   #if defined (IBMPC)
   	#include "ibmpc.h"
   #elif defined (VAX)
   	#include "vax.h"
   #elif defined (MAC)
   	#include "mac.h"
   #else
   	#include "general.h"
   #endif
   ```

5. c语言中一些内置宏

   ```c
   // __DATE__
   // __TIME__
   // __FILE__
   // __LINE__
   // __STDC_VERSION__ 版本号
   ```

6.  predefined identifier: ```__func__```

   ```c
   void why_me()
   {
       printf("This function is %s\n", __func__); // __func__获取当前方法名称
       printf("This is line %d.\n", __LINE__);
   }
   ```

7. Generic Selection (C11): ```_Generic```函数类似于switch，根据参数的数据类型，返回对应的值

   ```c
   // 格式
   // _Generic(x, int: 0, float: 1, double: 2, default: 3)
   
   // 使用案例1
   #define MYTYPE(X) _Generic((X),\
       int: "int",\
       float : "float",\
       double: "double",\
       default: "other"\
   )
   
   int main(void)
   {
       int d = 5;
       printf("%s\n", MYTYPE(d)); // d is type int
       printf("%s\n", MYTYPE(2.0*d)); // 2.0* d is type double
       printf("%s\n", MYTYPE(3L)); // 3L is type long
       printf("%s\n", MYTYPE(&d)); // &d is type int *
       return 0;
   }
   
   // 使用案例2
   char * type = _Generic((9), int: "int", double: "double", default: "other" );
   ```

## 9.6 Inline Functions (C99)

1. inline functon等价于将函数代码直接放入调用方函数中，避免函数调用的额外开销

2. inline function要比较短小，耗时较短

3. 案例

   ```c
   inline static void eatline() // inline definition/prototype
   {
       while (getchar() != '\n')
           continue;
   }
   
   int main()
   {
   
   	eatline(); // function call
   
   }
   ```

4. 为了inline函数的通用性，可以将inline函数写在头文件中

   ```c
   // eatline.h
   #ifndef EATLINE_H_
   #define EATLINE_H_
   inline static void eatline()
   {
       while (getchar() != '\n')
       continue;
   }
   #endif
   ```

5. inline的具体实依赖于具体编译器, gcc强制使用内联的方法

   ```c
   /* Prototype.  */
   inline void foo (const char) __attribute__((always_inline));
   ```

6. gcc值只采用编译优化时，才会使用内联优化```-O1```，否则不内联

   > GCC does not inline any functions when not optimizing unless you specify the ‘always_inline’ attribute for the function  

## 9.7 The Math Library

math.h

```c
sin;
cos;
tan;
asin;
acos;
atan;
sqrt;
...
```

## 9.8 The General Utilities Library

在```stdlib.h```这个头文件中

1. exit/atexit函数

    ```c
    exit ;
    atexit ; //The atexit() function provides this feature by registering the functions to be called on exit;
    ```

2. qsort-快速排序函数

   ```c
   void qsort(void *base, size_t nmemb, size_t size,
        	int (*compar)(const void *, const void *));
   ```

## 9.9 The Assert Library

需要引入头文件：```assert.h ```

1. using assert（运行期检查）

   ```c
   #include <assert.h>
   
   
   int main(int argc, char const *argv[])
   {
       int x = 9;
       assert(x > 9); // assert(exp); 如果exp表达式为false时，则中断程序
       return 0;
   }
   ```

2. 如果相关关闭断言，则在#include <assert.h>前加入#define NDEBUG

   ```
   #define NDEBUG
   #include <assert.h>
   
   int main(int argc, char const *argv[])
   {
       int x = 9;
       assert(x > 9); // 则此处断言不会发生作用
       return 0;
   }
   ```

3. 静态断言（编译期检查）--_Static_assert (C11)

   ```c
   #define SYS 2
   
   _Static_assert(SYS == 1, "sys must be 1"); // 编译期检查，如果表达式结果为false, 则编译不通过
   
   int main(int argc, char const *argv[])
   {
       /* code */
       return 0;
   }
   
   ```

4. memcpy() and memmove() from the string.h Library

   ```c
   void *memcpy(void *dest, const void *src, size_t n);
   void *memmove(void *dest, const void *src, size_t n);
   ```

## 9.10 Variable Arguments: stdarg.h

1. 变参必须位于最后一个参数

   ```c
   void f1(int n, ...); // valid
   int f2(const char * s, int k, ...); // valid
   char f3(char c1, ..., char c2); // invalid, ellipsis not last
   double f3(...); // invalid, no parameter
   ```

2. 使用案例

   ```c
   #include <stdarg.h>
   double sum(int, ...); // 变参
   
   int main(void)
   {
       double t;
       t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
       return 0;
   }
   
   double sum(int lim,...)
   {
   	va_list ap; // declare object to hold arguments
       double tot = 0;
       int i;
       
       va_start(ap, lim); // initialize ap to argument list
       for (i = 0; i < lim; i++)
       	tot += va_arg(ap, double); // access each item in argument list，以double类型来接受参数
       va_end(ap); // clean up
       return tot;
   }
   ```



# 10. Advanced Data Representation