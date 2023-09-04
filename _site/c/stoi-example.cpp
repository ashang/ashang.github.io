/*
In C++11 you can use std::to_string:

#include <string>

std::string s = std::to_string(5);

If you're working with prior to C++11, you could use C++ streams:
#include <sstream>

int i = 5;
std::string s;
std::stringstream out;
out << i;
s = out.str();

*/


/*
couple of years later, C++17 has finally delivered a way to do the originally macro-based type-agnostic solution (preserved below) without going through macro uglyness.

// variadic template
template < typename... Args >
std::string sstr( Args &&... args )
{
    std::ostringstream sstr;
    // fold expression
    ( sstr << std::dec << ... << args );
    return sstr.str();
}
Usage:

int i = 42;
std::string s = sstr( "i is: ", i );
puts( sstr( i ).c_str() );

Foo x( 42 );
throw std::runtime_error( sstr( "Foo is '", x, "', i is ", i ) );
*/

/*

C++11 introduces std::stoi (and variants for each numeric type) and std::to_string, the counterparts of the C atoi and itoa but expressed in term of std::string.

#include <string> 

std::string s = std::to_string(42);
is therefore the shortest way I can think of. You can even omit naming the type, using the auto keyword:

auto s = std::to_string(42);

*/


// stoi example
#include <iostream>   // std::cout
#include <sstream>
#include <string>     // std::string, std::stoi

int main ()
{
  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";

  std::string::size_type sz;   // alias of size_t

  int i_dec = std::stoi (str_dec,&sz);
  int i_hex = std::stoi (str_hex,nullptr,16);
  int i_bin = std::stoi (str_bin,nullptr,2);
  int i_auto = std::stoi (str_auto,nullptr,0);

  std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  std::cout << str_hex << ": " << i_hex << '\n';
  std::cout << str_bin << ": " << i_bin << '\n';
  std::cout << str_auto << ": " << i_auto << '\n';

const int i = 3;
std::ostringstream s;
s << i;
const std::string i_as_string(s.str());

  std::cout << '\n';
  std::cout << i_as_string << '\n';
  std::cout << '\n';
//const std::string i_as_string(s.str());
  std::cout << s.str() << '\n';
  std::cout << '\n';

    std::string str1 = "45";
    std::string str2 = "3.14159";
    std::string str3 = "31337 with words";
    std::string str4 = "words and 2";

    int myint1 = std::stoi(str1);
    int myint2 = std::stoi(str2);
    int myint3 = std::stoi(str3);
    // error: 'std::invalid_argument'
    // int myint4 = std::stoi(str4);

    std::cout << "std::stoi(\"" << str1 << "\") is " << myint1 << '\n';
    std::cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
    std::cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
    //std::cout << "std::stoi(\"" << str4 << "\") is " << myint4 << '\n';

  return 0;
}

/*
int stoi (const string&  str, size_t* idx = 0, int base = 10);
int stoi (const wstring& str, size_t* idx = 0, int base = 10);

Parses str interpreting its content as an integral number of the specified base, which is returned as an int value.

If idx is not a null pointer, the function also sets the value of idx to the position of the first character in str after the number.

The function uses strtol (or wcstol) to perform the conversion (see strtol for more details on the process).

idx
Pointer to an object of type size_t, whose value is set by the function to position of the next character in str after the numerical value.
This parameter can also be a null pointer, in which case it is not used.

Numerical base (radix) that determines the valid characters and their interpretation.
If this is 0, the base used is determined by the format in the sequence (see strtol for details). Notice that by default this argument is 10, not 0.

Return Value
On success, the function returns the converted integral number as an int value.
*/
