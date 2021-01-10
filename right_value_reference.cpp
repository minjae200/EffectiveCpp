#include <iostream>
#include <cstring>
#include <vector>

class MyString {
    char *string_content;
    int string_length;
    int memory_capacity;

public:
    MyString();
    MyString(const char *str); // 문자열로부터 생성
    MyString(const MyString &str); // 복사 생성자
    MyString(MyString &&str) noexcept;  // 이동 생성자
    ~MyString();
};

MyString::MyString() {
    std::cout << "생성자 호출!" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = nullptr;
}

MyString::MyString(const char *str) {
    std::cout <<"(const) 생성자 호출!" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i=0; i != string_length; i++)
        string_content[i] = str[i];
}

MyString::MyString(const MyString &str) {
    std::cout << "복사 생성자 호출!" << std::endl;
    string_length = str.string_length;
    memory_capacity = str.memory_capacity;
    string_content = new char[string_length];

    for (int i=0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

MyString::MyString(MyString &&str) noexcept {
    std::cout << "이동 생성자 호출!" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    // 임시 객체 소멸 시 메모리를 해제하지 못하게 한다.
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

    std::cout << "첫번째 추가" << std::endl;
    vec.push_back(s);
    std::cout << "두번째 추가" << std::endl;
    vec.push_back(s);
    std::cout << "세번째 추가" << std::endl;
    vec.push_back(s);
}