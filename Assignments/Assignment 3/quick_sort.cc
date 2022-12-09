#include <iostream>
#include <vector>
#include <cstdlib>

#include "def.h"
#include "quicksort_ascending.h"
#include "quicksort_descending.h"

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    srand(time(NULL));

    vi v(SIZE);
    std::cout<<"Before sorting\n";
    for (int i=0; i<SIZE; i++){
        v[i] = rand()%100+1;
        std::cout<<v[i]<<" ";
    }
    std::cout<<"\n\n";

    std::cout<<"Ascending order"<<"\n";
    quick_sort_ascending(v, 0, v.size()-1);
    for (auto itr=v.begin(); itr!=v.end(); itr++) std::cout<<*itr<<" ";
    std::cout<<"\n\n";
    
    std::cout<<"Descending order"<<"\n";
    quick_sort_descending(v, 0, v.size()-1);
    for (auto itr=v.begin(); itr!=v.end(); itr++) std::cout<<*itr<<" ";
    std::cout<<"\n";
}
