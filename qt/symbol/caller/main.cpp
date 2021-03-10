#include <QCoreApplication>
#include <iostream>
#include <QLibrary>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout<<"Hello!"<<std::endl;
    QLibrary qlib(argv[1]);
    if(qlib.load()){
        std::cout<<"Load successfully!"<<std::endl;
    }
    else{
        std::cout<<"Load failed!"<<std::endl;
    }

    auto use_my_lib = qlib.resolve("use_my_lib");

    if(use_my_lib != nullptr){
        std::cout<<"Resolve successfully!"<<std::endl;
    }
    else{
        std::cout<<"Resolve failed!"<<std::endl;
        return -1;
    }

    use_my_lib();

    return a.exec();
}
