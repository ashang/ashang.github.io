#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> wordcounts;
    std::string s;

    while (std::cin >> s && s != "end")
        ++wordcounts[s];

    while (std::cin >> s && s != "end")
        std::cout << s << ' ' << wordcounts[s] << '\n';
}
