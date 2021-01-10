#include <iostream>
#include <memory>
#include <vector>

class A {
    int* data;
public:
    A(int i) {
        std::cout << "�ڿ��� ȹ����." << std::endl;
        data = new int[100];
        data[0] = i;
    }

    void some() { std::cout << "�Ϲ� �����Ϳ� �����ϰ� ��밡��!" << std::endl; }

    void do_sth(int a) {
        std::cout << "���𰡸� �Ѵ�." << std::endl;
        data[0] = a;
    }

    ~A() {
        std::cout << "�ڿ��� ������!" << std::endl;
        delete[] data;
    }
};
#if 0
/* 
    unique_ptr ��Ģ�� �����.
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
    vec.push_back(pc); // error! ��������ڿ� �����ؼ� ������ ����. (unique_ptr�� ��������ڰ� ����)
    vec.push_back(std::move(pc)); // compile �ߵ�. �߽���� �� ��������� �ִ�.
    #endif
    vec.emplace_back(new A(1));  // perfect forwarding �Ѵ�.
    vec.back()->some();

    #if 0
    std::vector<int> v;
    v.emplace_back(100); // 100�̶� int���� v�� �߰��Ѵ�.

    std::vector<std::vector<int>> v;
    v.emplace_back(100); // ���Ұ� 100�� ����ִ� vector�� v�� �߰��ϰ� �ȴ�.
    #endif
}