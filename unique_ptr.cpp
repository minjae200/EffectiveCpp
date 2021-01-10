#include <iostream>
#include <memory>
#include <vector>

class A {
    int* data;
public:
    A(int i) {
        std::cout << "자원을 획득함." << std::endl;
        data = new int[100];
        data[0] = i;
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용가능!" << std::endl; }

    void do_sth(int a) {
        std::cout << "무언가를 한다." << std::endl;
        data[0] = a;
    }

    ~A() {
        std::cout << "자원을 해제함!" << std::endl;
        delete[] data;
    }
};
#if 0
/* 
    unique_ptr 원칙에 위배됨.
 */
void do_something(std::unique_ptr<A>& ptr)
{
    ptr->do_sth(3);
}

int main(void)
{
    std::unique_ptr<A> pa(new A());
    do_something(pa);
}
#endif
void do_something(A* ptr)
{
    ptr->do_sth(3);
}
int main(void)
{
    // std::unique_ptr<A> pa(new A());
    auto pa = std::make_unique<A>(1);
    do_something(pa.get());
    auto pb = std::move(pa);
    std::cout << pa.get() << std::endl; // 0 (nullptr)
    std::cout << pb.get() << std::endl; // 0xec1990 (some address)


    std::vector<std::unique_ptr<A>> vec;
    auto pc = std::make_unique<A>(3);
    
    #if 0
    vec.push_back(pc); // error! 복사생성자에 접근해서 에러가 난다. (unique_ptr은 복사생성자가 없다)
    vec.push_back(std::move(pc)); // compile 잘됨. 잘실행됨 더 좋은방법이 있다.
    #endif
    vec.emplace_back(new A(1));  // perfect forwarding 한다.
    vec.back()->some();

    #if 0
    std::vector<int> v;
    v.emplace_back(100); // 100이란 int값을 v에 추가한다.

    std::vector<std::vector<int>> v;
    v.emplace_back(100); // 원소가 100개 들어있는 vector를 v에 추가하게 된다.
    #endif
}