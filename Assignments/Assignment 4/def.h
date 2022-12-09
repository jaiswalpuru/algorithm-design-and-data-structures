/*
This file contains all the definitions for the code
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define PB push_back

template <typename T>
struct vec_one { typedef std::vector<T> vt; };

template <typename T>
struct vec_two { typedef std::vector<typename vec_one<T>::vt > vtt; };

typedef vec_two<int>::vtt vii;
typedef vec_two<char>::vtt vcc;

template <typename T>
struct mp { typedef std::map<T,typename vec_one<T>::vt > mt; };
