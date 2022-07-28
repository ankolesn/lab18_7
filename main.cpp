#include <iostream>
#include "hashmapclass.hpp"
int main() {
    Hashmap_class<int> hm(4);

    hm.insert("123", 2);
    hm.insert("13", 4);
    hm.insert("1", 1);

    auto r = hm.find("46");
    std::cout << r.first << " " << r.second << std::endl;
    hm.erase("13");
    std::cout << hm;


}
