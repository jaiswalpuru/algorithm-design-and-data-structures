Implement Hash table.
Pick 20 random words.  Each word must be of different lengths, maximum length 8 characters  and minimum length 3 characters.
The words will be of letters a-zA-Z and the space character.
Insert them into a hash table. 
You can use a library for only the hash function.
The collision resolution scheme should be open addressing - quadratic.
Initially the table size is 31.  The program should increase the table size and rehash at load factor of .5
So after you inserted about 15 or 16 words, your program automatically doubles the table size and re-inserts (automatically) the old words and then continue the insert of additional words.
You do not have to insert the words manually (one by one) but you can add the words in a file and let your program read from the file
At the end print the total number of collisions you get.
Submit your code and print screen of your execution

Run : 
1. $ g++ --std=c++11 hashing.cc -o hashing
2. $ ./hashing
