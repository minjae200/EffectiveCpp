#include <iostream>
#include <vector>
using namespace std;

/* 
    C++ 컴파일러가 템플릿 타입을 추론할 때, 템플릿 인자 T가 레퍼런스가 아닌 일반적인 타입이라면
    cosnt를 무시하기 때문에 '좌측값 레퍼런스 호출' 됨.
    다시 말해, T가 전부 class A로 추론된다.
 */
template <typename T>
void wrapper(T&& u) {
    g(std::forward<T>(u));
}

class A {};

void g(A& a) { std::cout << "좌측값 레퍼런스 호출" << std::endl; }
void g(const A& a) { std::cout << "좌측값 상수 레퍼런스 호출" << std::endl; }
void g(A&& a) { std::cout << "우측값 레퍼런스 호출" << std::endl; }

int main(void)
{
    A a;
    const A ca;

    std::cout << "원본 ---------" << std::endl;
    g(a);
    g(ca);
    g(A());

    std::cout << "Wrapper ---------" << std::endl;
    wrapper(a);
    wrapper(ca);
    wrapper(A());
}