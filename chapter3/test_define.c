#define PI 3.14

#define x(a) a##1
#define m(c) #c

int main(int argc, char const *argv[])
{
    double x = 5 * PI;
    int x(b) = 7;
    char * s = m(9);
    return 0;
}
