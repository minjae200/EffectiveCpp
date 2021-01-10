#include <iostream>
#include <memory>
#include <vector>

class A {
    int *data;
public:
    A() {
        data = new int[100];
        std::cout << "�ڿ��� ȹ����!" << std::endl;
    }

    ~A() {
        std::cout << "�Ҹ��� ȣ��!" << std::endl;
        delete[] data;
    }
};

int main(void)
{
    std::vector<std::shared_ptr<A>> vec;

    // vec.push_back(std::shared_ptr<A>(new A()));
    vec.push_back(std::make_shared<A>());
    vec.push_back(std::shared_ptr<A>(vec[0]));
    vec.push_back(std::shared_ptr<A>(vec[1]));

    std::cout << "ù ��° �Ҹ� !" << std::endl;
    vec.erase(vec.begin());

    std::cout << "���� ���� �Ҹ� !" << std::endl;
    vec.erase(vec.begin());

    std::cout << "������ ���� �Ҹ� !" << std::endl;
    vec.erase(vec.begin());

    std::cout << "���α׷� ����!" << std::endl;
}