#include "mylib_b.hh"

extern "C"{

void use_my_lib(){
    ns::Foo lib;
    lib.funA(1);
    lib.funB(2);

    ns::Bar<float> lib_b(2.0);
    lib_b.funA();
}

}
