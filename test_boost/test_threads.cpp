#include <algorithm>
#include <fstream>
#include <iterator>
#include <boost/thread.hpp>

void set_not_first_run();
bool is_first_run();
// Function, that executes for a long time
void fill_file_with_data(char fill_char, std::size_t size, const char*
filename){
std::ofstream ofs(filename);
std::fill_n(std::ostreambuf_iterator<char>(ofs), size, fill_char);
set_not_first_run();
}
// ...
// Somewhere in thread that draws a user interface
if (is_first_run()) {
// This will be executing for a long time during which
// users interface will freeze..
fill_file_with_data(0, 8 * 1024 * 1024, "save_file.txt");
}
