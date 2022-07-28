//
// Created by ankolesn on 27.07.22.
//

#ifndef LAB18_7_HASHMAPCLASS_HPP
#define LAB18_7_HASHMAPCLASS_HPP
#include <string>
#include <vector>
#include <list>

template<typename V>
class Hashmap_class {
private:
    std::vector<std::list<V>> hashmap;

public:
    Hashmap_class(int size);

    void insert(const std::string & key, V value);

    std::pair<int, bool> find(const std::string & key); //bool --- найден или нет, int --- значение

    void erase(const std::string & key); // удаляет один экземпляр записи

    friend std::ostream &operator<<(std::ostream &out, const Hashmap_class<V> &hm) {
        for (auto &i: hm.hashmap) {
            for (auto &j: i) {
                out << "Value: " << j << std::endl;
            }
        }
        return out;
    }
    size_t hash_func(const std::string &key){
        size_t sum = 0;
        for (int i = 0; i < key.size(); ++i) {
            sum += key[i];
        }
        size_t res = sum % hashmap.size();
        return res;
    }

};

template<typename V>
void Hashmap_class<V>::insert(const std::string &key, V value) {
    hashmap[hash_func(key)].push_back(value);
}

template<typename V>
std::pair<int, bool> Hashmap_class<V>::find(const std::string &key) {
    if(!hashmap[hash_func(key)].empty()){
        return std::make_pair(hashmap[hash_func(key)].front(), true);
    }
    else{
        return std::make_pair(hashmap[hash_func(key)].front(), false);
    }
}

template<typename V>
void Hashmap_class<V>::erase(const std::string &key) {
    if(!hashmap[hash_func(key)].empty()){
        hashmap[hash_func(key)].erase(hashmap[hash_func(key)].begin(), hashmap[hash_func(key)].end());
    }
}

template<typename V>
Hashmap_class<V>::Hashmap_class(int size) {
    hashmap.resize(size);
}


#endif //LAB18_7_HASHMAPCLASS_HPP
