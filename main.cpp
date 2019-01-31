#include"custom_string.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* M A I N for testing purpose */
int main()
{
    CustomString s1;
    CustomString s2("Hello there");
    CustomString s3("derby");
    CustomString s4 = s3;
    CustomString s5;
    CustomString s6("Gryffindor");
    s5 = s4;

    printf("\n");
    printf("s1: %s, len: %d\n", s1.c_str(), s1.size());
    printf("s2: %s, len: %d\n", s2.c_str(), s2.size());
    printf("s3: %s, len: %d\n", s3.c_str(), s3.size());
    printf("s4: %s, len: %d\n", s4.c_str(), s4.size());
    printf("s5: %s, len: %d\n", s5.c_str(), s5.size());

    printf("\n");
    s1.clear();
    printf("s1: %s, len: %d\n", s1.c_str(), s1.size());
    s2.clear();
    printf("s2: %s, len: %d\n", s2.c_str(), s2.size());

    printf("\n");
    printf("s2 empty?: %d\n", s2.empty());

    printf("\n");
    printf("s2[3] : %c\n", s2[3]);
    printf("s3[3] : %c\n", s3[3]);

    printf("\n");
    CustomString s7 = s3 + s6;
    printf("s7: %s, len: %d\n", s7.c_str(), s7.size());

    printf("\n");
    CustomString s8;
    CustomString s9("throwback");
    s2.push_back('Y');
    printf("s2: %s, len: %d\n", s2.c_str(), s2.size());
    s8.push_back('Z');
    printf("s8: %s, len: %d\n", s8.c_str(), s8.size());
    s9.push_back('X');
    printf("s9: %s, len: %d\n", s9.c_str(), s9.size());

    printf("\n");
    CustomString s10("derby");
    printf("s10: %s, len: %d\n", s10.c_str(), s10.size());
    printf("s4: %s, len: %d\n", s4.c_str(), s4.size());
    if (s4 == s10)
    {
        printf("s4 and s10 are same\n");
    }
    else
    {
        printf("s4 and s10 are different\n");
    }

    getchar();
    return 0;
}