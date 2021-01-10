#include <iostream>
#include <vector>
using namespace std;

/* 
    C++ �����Ϸ��� ���ø� Ÿ���� �߷��� ��, ���ø� ���� T�� ���۷����� �ƴ� �Ϲ����� Ÿ���̶��
    cosnt�� �����ϱ� ������ '������ ���۷��� ȣ��' ��.
    �ٽ� ����, T�� ���� class A�� �߷еȴ�.
 */
template <typename T>
void wrapper(T&& u) {
    g(std::forward<T>(u));
}

class A {};

void g(A& a) { std::cout << "������ ���۷��� ȣ��" << std::endl; }
void g(const A& a) { std::cout << "������ ��� ���۷��� ȣ��" << std::endl; }
void g(A&& a) { std::cout << "������ ���۷��� ȣ��" << std::endl; }

int main(void)
{
    A a;
    const A ca;

    std::cout << "���� ---------" << std::endl;
    g(a);
    g(ca);
    g(A());

    std::cout << "Wrapper ---------" << std::endl;
    wrapper(a);
    wrapper(ca);
    wrapper(A());
}