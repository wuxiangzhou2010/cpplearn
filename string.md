## [characters and strings]

- 1.Characters

  - 1.1 header `<cctype>` -- Character Type Library

    - `isdigit()`
    - `isalpha()`
    - `isupper`
    - `islower`

    All these functions `treat a char as a signed int`.

- 2.Strings: the C string and the string class
  - The C-style string (or C-String) in header `cstring`
  - The new C++ string class in header `string`. string is a regular class,
- 2.1 C-string literal
- 2.2 C-string header and function

  NULL-terminated character strings(char array)

  - `cstring`

    - contains these commonly-used functions to operate on C-strings.
    - `char[]` is same as `char *`: C treats an array name as a pointer to the first element of the array
      - `size_t strlen (const char * cstr)` // not include the null

  - `cstdlib`
    - contains functions to convert C-strings to fundamental types.
    - `int atoi (char * cstr)`
    - `double atof (char * cstr)`

- 2.3 the C++'s string class

  The string class is an instantiation of the `basic_string<T>` template class that uses `char` type with a typedef.

  ```c
  typedef basic_string<char> string;
  typedef basic_string<wchar_t> wstring;
  ```

  - string Class Constructors
  - Public Functions

- 2.4 the c-string input method
- 2.5 the string class input method

<!-- `<iostream>` header

- getline()
- int cin.get()
- cin.peek()
- cin.ignore(unsigned int n = 1, int delim = EOF):

-- 1. string literal

u8/u/U/R raw string - -->

reference:

- [cp9_String](<(https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp9_String.html)>)
