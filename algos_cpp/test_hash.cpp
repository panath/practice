#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;


size_t djb_hash(const string & str) {

    size_t hash = 5381;

    for (size_t i=0; i < str.length() ; i++)
    {
        hash = ((hash << 5) + hash) + str[i]; // hash*33 + str
    }

    return hash;
}


int main() {
  cout << "djb hash" << hex << djb_hash("Steve") << endl;
  cout << "std hash" << hex << std::hash<string>()("Steve") << endl;
  unordered_map<string, string> m1;
  unordered_map<string, string>::hasher hash_func = m1.hash_function();
  cout << "unordered map hasher: " << hex << hash_func("Steve") << "\n\n";

  unordered_map<string, string, function<decltype(djb_hash)>> m2(10, djb_hash);
  m2["Steve"] = "OK";
  cout << m2["Steve"] << endl;
}
