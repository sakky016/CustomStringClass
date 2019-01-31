#include "custom_string.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// -----------------------------------------------------------------------------------------
// @name                        : CustomString
//
// @description                 : 
//
// @returns                     : Nothing
// -----------------------------------------------------------------------------------------
CustomString::CustomString()
{
    printf("Constructor-0 called\n");
    m_ptr = nullptr;
    m_len = 0;
}

// -----------------------------------------------------------------------------------------
// @name                        : CustomString
//
// @description                 : 
//
// @returns                     : Nothing
// -----------------------------------------------------------------------------------------
CustomString::~CustomString()
{
    printf("Destructor called for %s\n", m_ptr);
    free(m_ptr);
    m_ptr = nullptr;
}

// -----------------------------------------------------------------------------------------
// @name                        : CustomString
//
// @description                 : 
//
// @param value                 : 
//
// @returns                     : Nothing
// -----------------------------------------------------------------------------------------
CustomString::CustomString(char *value)
{
    printf("Constructor-1 called for %s\n", value);
    m_len = strlen(value);
    m_ptr = (char *)malloc(sizeof(char) * (m_len + 1));
    if (!m_ptr)
    {
        printf("ERROR: Malloc failure!\n");
    }

    memset(m_ptr, 0, m_len + 1);
    memcpy(m_ptr, value, m_len);
}

// -----------------------------------------------------------------------------------------
// @name                        : CustomString
//
// @description                 : Copy constructor. Does a deep copy of parameter 'value'.
//
// @param value                 : 
//
// @returns                     : Nothing
// -----------------------------------------------------------------------------------------
CustomString::CustomString(const CustomString & value)
{
    printf("Copy Constructor called for %s\n", value.m_ptr);

    m_len = value.m_len;
    m_ptr = (char *)malloc(sizeof(char) * (m_len + 1));
    if (!m_ptr)
    {
        printf("ERROR: Malloc failure!\n");
    }

    memset(m_ptr, 0, m_len + 1);
    memcpy(m_ptr, value.m_ptr, m_len);
}

// -----------------------------------------------------------------------------------------
// @name                        : operator = 
//
// @description                 : Assignment operator. Does a deep copy of parameter 'value'.
//
// @param value                 : 
//
// @returns                     : Nothing
// -----------------------------------------------------------------------------------------
void CustomString::operator =(const CustomString & value)
{
    printf("Assignment operator called for %s\n", value.m_ptr);
    m_len = value.m_len;
    m_ptr = (char *)malloc(sizeof(char) * (m_len + 1));
    if (!m_ptr)
    {
        printf("ERROR: Malloc failure!\n");
    }

    memset(m_ptr, 0, m_len + 1);
    memcpy(m_ptr, value.m_ptr, m_len);
}

// -----------------------------------------------------------------------------------------
// @name                        : operator [] 
//
// @description                 : Index operator
//
// @param value                 : 
//
// @returns                     : Character at 'index'
// -----------------------------------------------------------------------------------------
char CustomString::operator [](const int index)
{
    if (m_ptr == nullptr)
    {
        return '\0';
    }
    else if (index > (m_len-1) || index < 0)
    {
        return '\0';
    }
    else
    {
        return m_ptr[index];
    }
}

// -----------------------------------------------------------------------------------------
// @name                        : operator + 
//
// @description                 : Appends 'value' to current string and returns pointer to
//                                the beginning of the string.
//
// @param value                 : 
//
// @returns                     : pointer to beginning of string
// -----------------------------------------------------------------------------------------
char * CustomString::operator +(const CustomString &rhs)
{
    // String is already null, create new with 'rhs'
    if (m_ptr == nullptr)
    {
        m_len = rhs.m_len;
        m_ptr = (char *)malloc(sizeof(char) * (m_len + 1));
        if (!m_ptr)
        {
            printf("ERROR: Malloc failure!\n");
        }

        memset(m_ptr, 0, m_len + 1);
        memcpy(m_ptr, rhs.m_ptr, m_len);
        return m_ptr;
    }
    
    // Nothing to append
    if (rhs.m_ptr == nullptr)
    {
        return m_ptr;
    }

    // Both strings to be appended
    int new_len = m_len + rhs.m_len;

    // Store current string
    char *tmp = (char *)malloc(sizeof(char) * (m_len + 1));
    if (!tmp)
    {
        printf("ERROR: Malloc failure!\n");
    }

    memset(tmp, 0, m_len + 1);
    memcpy(tmp, m_ptr, m_len);
    // Free this memory
    free(m_ptr);
    m_ptr = nullptr;

    // Allocate memory for concatenated string
    m_ptr = (char *)malloc(sizeof(char) * (new_len + 1));
    if (!m_ptr)
    {
        printf("ERROR: Malloc failure!\n");
    }

    memset(m_ptr, 0, new_len + 1);
    memcpy(m_ptr, tmp, m_len);
    memcpy(m_ptr + m_len, rhs.m_ptr, rhs.m_len);
    m_len = new_len;

    // Free tmp memory
    free(tmp);
    tmp = nullptr;

    return m_ptr;
}

// -----------------------------------------------------------------------------------------
// @name                        : operator == 
//
// @description                 : Checks if 2 strings are same
//
// @param value                 : 
//
// @returns                     : true/false
// -----------------------------------------------------------------------------------------
bool CustomString::operator ==(const CustomString &rhs)
{
    // If both are null, then they are equal
    if (m_ptr == nullptr && rhs.m_ptr == nullptr)
    {
        return true;
    }

    // One of them is null, they are unequal
    if (m_ptr == nullptr || rhs.m_ptr == nullptr)
    {
        return false;
    }

    if (strcmp(m_ptr, rhs.m_ptr) == 0)
        return true;

    return false;
}

// -----------------------------------------------------------------------------------------
// @name                        : c_str
//
// @description                 : 
//
// @returns                     : Pointer to string start location.
// -----------------------------------------------------------------------------------------
char * CustomString::c_str()
{
    return m_ptr;
}

// -----------------------------------------------------------------------------------------
// @name                        : size
//
// @description                 : 
//
// @returns                     : Returns length of string
// -----------------------------------------------------------------------------------------
int CustomString::size()
{
    return m_len;
}

// -----------------------------------------------------------------------------------------
// @name                        : length
//
// @description                 : 
//
// @returns                     : Returns length of string
// -----------------------------------------------------------------------------------------
int CustomString::length()
{
    return m_len;
}

// -----------------------------------------------------------------------------------------
// @name                        : clear
//
// @description                 : Clears the string memory.
//
// @returns                     : nothing
// -----------------------------------------------------------------------------------------
void CustomString::clear()
{
    free(m_ptr);
    m_ptr = nullptr;
    m_len = 0;
}

// -----------------------------------------------------------------------------------------
// @name                        : empty
//
// @description                 : Checks if string is empty
//
// @returns                     : true/false
// -----------------------------------------------------------------------------------------
bool CustomString::empty()
{
    return (m_len == 0);
}

// -----------------------------------------------------------------------------------------
// @name                        : push_back
//
// @description                 : appends a character to end of string
//
// @returns                     : nothing
// -----------------------------------------------------------------------------------------
void CustomString::push_back(char c)
{
    if (m_ptr == nullptr)
    {
        m_len = 1;
        m_ptr = (char *)malloc(sizeof(char) * (m_len + 1));
        if (!m_ptr)
        {
            printf("ERROR: Malloc failure!\n");
        }

        memset(m_ptr, 0, m_len + 1);
        m_ptr[0] = c;
    }
    else
    {
        int new_len = m_len + 1;

        // Store current string
        char *tmp = (char *)malloc(sizeof(char) * (m_len + 1));
        if (!tmp)
        {
            printf("ERROR: Malloc failure!\n");
        }

        memset(tmp, 0, m_len + 1);
        memcpy(tmp, m_ptr, m_len);

        // Free this memory
        free(m_ptr);
        m_ptr = nullptr;

        // Allocate memory for concatenated string
        m_ptr = (char *)malloc(sizeof(char) * (new_len + 1));
        if (!m_ptr)
        {
            printf("ERROR: Malloc failure!\n");
        }

        memset(m_ptr, 0, new_len + 1);
        memcpy(m_ptr, tmp, m_len);
        m_ptr[m_len] = c;
        m_len++;

        // Free tmp memory
        free(tmp);
        tmp = nullptr;
    }
}

