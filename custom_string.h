#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

class CustomString
{
private:
    char *m_ptr;
    int m_len;
public:
    CustomString();
    ~CustomString();
    CustomString(char *value);
    char * c_str();
    CustomString(const CustomString & value);
    void operator =(const CustomString & value);
    char operator [](const int index);
    char* operator +(const CustomString &rhs);
    bool operator ==(const CustomString &rhs);
    int size();
    int length();
    void clear();
    bool empty();
    void push_back(char c);
};

#endif
