# Boost

## lexial_cast

```cpp
lexial_cast<string>('34.5)
lexial_cast<array<char, 64>>(23)
s= lexial_cast<int>("3456")
try {
s=lexial_cast<int>("56.78") ; // bad_lexial_cast
}catch(bad_lexical_cast &e){

}
```

## variant

## any

```cpp
any kind of data //use dynamic storage
boost::any x, y, z;
x = string("helllo");
y = 2.3;
y = 'z';
boost::any_cast<char>(y);
    //bad_any_cast
```

## [BigInteger](https://www.geeksforgeeks.org/advanced-c-boost-library)

## Arbitrary precision data type --> cpp_int

``` cpp
#include <boost/multiprecision/cpp_int.hpp>
```

int128_t, int256_t, int512_t or int1024_t

## Multiprecsion float

``` cpp
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
```

cpp_dec_float_50

## datetime

## smart pointer
