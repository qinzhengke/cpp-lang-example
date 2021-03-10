#include "mylib_b.hh"

/*

Linux下使用 'nm --dynamic --extern-only libmylib.so' 来查看so文件中的符号，'-g'表示外部符号。



*/

using namespace ns;

Foo::Foo(){

}


// 该函数会在so文件中出现
void Foo::funB(int x){
    printf("Foo::funB()=>%d\n", x);
}

// 该函数会在so文件中出现
int funcD(int x){
    // 如果构造了Foo，Foo的构造函数会在so文件中出现。
    Foo m;

    // 如果调用了,则Foo::funA会在so文件中出现。
    // m.funA(x);
}

template<typename T>
Bar<T>::Bar(T _x){
    this->x = _x;
}

template Bar<float>::Bar(float x);

template<typename T>
void Bar<T>::funA(){
    printf("MyTlib::funA()=>%.4f\n", x);
}

template void Bar<float>::funA();
