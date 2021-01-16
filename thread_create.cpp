#include <iostream>
#include <thread>

void func1() {
    for (int i=0; i<10; i++) {
        std::cout << "thread 1 operation" << std::endl;
    }
}

void func2() {
    for (int i=0; i<10; i++) {
        std::cout << "thread 2 operation" << std::endl;
    }
}

void func3() {
    for (int i=0; i<10; i++) {
        std::cout << "thread 3 operation" << std::endl;
    }
}

int main(void)
{
    std::thread t1(func1);
    std::thread t2(func2);
    std::thread t3(func3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}