#include "def.h"

class HashTable { 
private:
    vs hash_map;
    hs h;
    int total_elements;
    int size;
    int n_collisions;
    void rehash();
    double load_factor();
    int hash_function(std::string word);
    int get_next_prime(int n);
    bool is_prime(int n);
public:
    HashTable();
    void put(std::string word);
    void print();
    int get_total_collisions();
};

HashTable::HashTable() {
    this->size = SIZE;
    this->hash_map = vs(this->size);
    this->total_elements = 0;
    this->n_collisions = 0;
}


int HashTable::get_next_prime(int  n) {
    while(!is_prime(n)) n++;
    return n;
}

bool HashTable::is_prime(int n) {
    if (n%2 == 0 || n%3 == 0 || n%5==0 || n%7== 0 ) return false;
    for (int i=8; i<=std::sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}

void HashTable::print() {
    for (int i=0; i<this->hash_map.size(); i++) {
        if (hash_map[i] != "")
            std::cout<<"Key : "<<i<<"\t Value : "<<hash_map[i]<<"\n";
    }
}

double HashTable::load_factor() { return ((double)this->total_elements/this->size); }

void HashTable::put(std::string word) {
    std::cout<<"Inserting word : "<<word<<"\n";
    double lf = load_factor();
    if (lf >= LOAD_FACTOR) rehash();
    int key = hash_function(word);
    int i = 0;
    while(this->hash_map[(key+(i*i))%this->size] != "") {
        std::cout<<"Collision occured at key : "<<(key+(i*i))%this->size<<" value : "<<hash_map[key+(i*i)%this->size]<<"\n";
        i++;
        this->n_collisions++;
    }
    this->hash_map[(key+(i*i))%this->size] = word;
    std::cout<<word<<" inserted at key : "<<(key+(i*i))%this->size<<"\n\n";
    this->total_elements++;
}

int HashTable::hash_function(std::string word) { return this->h(word)%this->size; }

void HashTable::rehash() {
    std::cout<<"Number of collions before rehashing : "<<this->n_collisions<<"\n";
    this->n_collisions = 0;
    this->total_elements = 0;
    std::cout<<"Load factor more than "<<LOAD_FACTOR<<" rehasing\n";
    std::cout<<"Initial table size : "<<this->size<<"\n";
    this->size = get_next_prime(this->size*2+1);
    std::cout<<"Table size increased to "<<this->size<<"\n";
    vs temp = this->hash_map;
    this->hash_map = vs(this->size);
    for (auto it=temp.begin(); it!=temp.end(); it++) {
        if (*it != "") {
            put(*it);
        }
    }
}

int HashTable::get_total_collisions() { return this->n_collisions; }
