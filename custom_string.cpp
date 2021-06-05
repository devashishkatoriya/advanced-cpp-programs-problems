#include <iostream>

class MyString
{
    char *str;
    int len;
public:
    /*
    MyString(char *str2)
    {
        int len = 0;
        while(str2[len]!='\0')
            len++;
        
        str = new char[len+1];
        for (int i=0; i < len; i++)
        {
            str[i] = str2[i];
        }
        str[len] = '\0';
    }
    */
    
    MyString(const std::string str2)
    {
        int len = 0;
        while(str2[len]!='\0')
            len++;
        
        str = new char[len+1];
        for (int i=0; i < len; i++)
        {
            str[i] = str2[i];
        }
        str[len] = '\0';
    }
    /*
    MyString(const char *str2)
    {
        int len = 0;
        while(str2[len]!='\0')
            len++;
        
        str = new char[len+1];
        for (int i=0; i < len; i++)
        {
            str[i] = str2[i];
        }
        str[len] = '\0';
    }
    */
    ~MyString()
    {
        delete[] str;
    }

    int length() const
    {
        return len;
    }

    void display()
    {
        std::cout << this->str << std::endl;
    }

    friend MyString& operator+(MyString &a, MyString &b);
    friend std::ostream& operator<<(std::ostream &o, MyString &obj);
    char operator[](int i);
    MyString& operator=(std::string str);
};

MyString& operator+(MyString &a, MyString &b)
{
    int len = a.length() + b.length();
    char *str = new char[len+1];

    int k = 0;
    for (int i=0; i < a.length(); i++)
    {
        str[k] = a[i];
        k++;
    }
    for (int i=0; i < b.length(); i++)
    {
        str[k] = a[i];
        k++;
    }

    str[len] = 0;

    MyString *obj = new MyString(str);
    return *obj;
}

std::ostream& operator<<(std::ostream &o, MyString &obj)
{
    o << obj.str;
    return o;
}

char MyString::operator[](int i)
{
    return *(str + i);
}

MyString& MyString::operator=(std::string str)
{
    MyString *obj = new MyString(str);
    return *obj;
}

int main()
{
    MyString obj2("Hi");
    obj2.display();
    std::cout << obj2 << std::endl;

    MyString obj = obj2;
    std::cout << obj << std::endl;
    
    MyString *obj3 = new MyString("Hello");    
    std::cout << *obj3 << std::endl;

    return 0;
}