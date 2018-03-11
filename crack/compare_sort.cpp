#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename K, typename V>
 int comparePairs(const void* left, const void* right){
        if((((pair<K,V>*)left)->first) <= (((pair<K,V>*)right)->first))
            return 1;
        else 
            return -1;
} 



int compare(std::string & s1, std::string s2) {

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return (s1 == s2);
}

int main()
{
    std::string s = "dacb";
    std::sort(s.begin(), s.end());
    std::cout << s << std::endl;

    std::vector<string> my_vec;
    my_vec.push_back("efgh");
    my_vec.push_back("abcd");
    my_vec.push_back("efhg");
    my_vec.push_back("acdb");
   
    std::sort(my_vec.begin(), my_vec.end(), compare); 

    for (auto s : my_vec)
        std::cout << s << std::endl;

    return 0;
}
