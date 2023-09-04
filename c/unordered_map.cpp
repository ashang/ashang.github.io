#include <iostream>
#include <string>
#include <unordered_map>
 
int main()
{
    std::unordered_map<std::string, int> months;
    months["january"] = 31;
    months["february"] = 28;
    months["march"] = 31;
    months["april"] = 30;
    months["may"] = 31;
    months["june"] = 30;
    months["july"] = 31;
    months["august"] = 31;
    months["september"] = 30;
    months["october"] = 31;
    months["november"] = 30;
    months["december"] = 31;
    std::cout << "september -> " << months["september"] << std::endl;
    std::cout << "april     -> " << months["april"] << std::endl;
    std::cout << "december  -> " << months["december"] << std::endl;
    std::cout << "february  -> " << months["february"] << std::endl;

    //判断map中是否包含一个键值，没有直接做此事的成员函数。类似其他的STL容器，解决办法是：
    if( months.find("no_value") == months.end() )
    {
          printf("No such key in the map.");
    }
    return 0;
}
