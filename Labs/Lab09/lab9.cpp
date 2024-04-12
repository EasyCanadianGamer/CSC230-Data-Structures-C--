#include<iostream>
#include<fstream>
#include<unordered_map>

using namespace std;

long hashcode(char *s);

int main(int argc, char const *argv[]) {
  
  int total = 0;
  int collisions = 0;
  
  ifstream input(argv[1]);
  string line;
  
  unordered_map<long, int> hashes;
  
  while (getline(input, line)) {
    total++;
    long hash = hashcode(const_cast<char*>(line.c_str()));
    if (hashes.count(hash) > 0) {
      collisions++; 
    }
    hashes[hash]++;
  }
  
  cout << "Total Input is " << total << endl;
  cout << "Collision # is " << collisions << endl;

  return 0;
}


long hashcode(char *s) {
  long hash = 0;
  int i = 0;
  while (s[i] != '\0') {
    hash = (hash  + s[i]) % 1007;
    i++; 
  }
  return hash;
}