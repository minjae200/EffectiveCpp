#include <iostream>
#include <cstring>
#include <vector>

class MyString {
    char *string_content;
    int string_length;
    int memory_capacity;

public:
    MyString();
    MyString(const char *str); // ���ڿ��κ��� ����
    MyString(const MyString &str); // ���� ������
    MyString(MyString &&str) noexcept;  // �̵� ������
    ~MyString();
};

MyString::MyString() {
    std::cout << "������ ȣ��!" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = nullptr;
}

MyString::MyString(const char *str) {
    std::cout <<"(const) ������ ȣ��!" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i=0; i != string_length; i++)
        string_content[i] = str[i];
}

MyString::MyString(const MyString &str) {
    std::cout << "���� ������ ȣ��!" << std::endl;
    string_length = str.string_length;
    memory_capacity = str.memory_capacity;
    string_content = new char[string_length];

    for (int i=0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

MyString::MyString(MyString &&str) noexcept {
    std::cout << "�̵� ������ ȣ��!" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    // �ӽ� ��ü �Ҹ� �� �޸𸮸� �������� ���ϰ� �Ѵ�.
    str.string_content = nullptr;
}
MyString::~MyString() {
    if(string_content) delete[] string_content;
}

int main(void)
{
    MyString s("abc");
    std::vector<MyString> vec;
    vec.resize(0);

    std::cout << "ù��° �߰�" << std::endl;
    vec.push_back(s);
    std::cout << "�ι�° �߰�" << std::endl;
    vec.push_back(s);
    std::cout << "����° �߰�" << std::endl;
    vec.push_back(s);
}