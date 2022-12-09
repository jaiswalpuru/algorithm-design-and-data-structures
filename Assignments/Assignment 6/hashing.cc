#include "hash_table.h"

int main() {
    HashTable ht = HashTable();
    std::ifstream read_file("words.txt");
    std::string word;
    while(getline(read_file, word)) ht.put(word);
    std::cout<<"Total number of collisions : "<<ht.get_total_collisions()<<"\n\n";
    ht.print();
}
