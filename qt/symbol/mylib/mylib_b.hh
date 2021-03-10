#include <cstdio>

namespace ns{

class Foo{
public:
    // 若无调用，该构造函数不会在so文件中出现
    Foo();

    // 若无调用，该函数不会在so文件中出现
    void funA(int x){
        printf("Foo::funA()=>%d\n", x);
    }

    void funB(int x);
};

template<typename T>
class Bar{
public:
    Bar(T x);
    void funA();
    T x;
};

}