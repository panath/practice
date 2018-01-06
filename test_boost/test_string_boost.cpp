#include <string>
template <class T>
	std::size_t test_default() {
	// Constants
	const std::size_t ii_max = 20000000;
	const std::string s(
	"Long long long string that "
	"will be used in tests to compare "
	"speed of equality comparisons."
	);
// Making some data, that will be
// used in comparisons
const T data[] = {
	T(s),
	T(s + s),
	T(s + ". Whooohooo"),
	T(std::string(""))
	};

const std::size_t data_dimensions
= sizeof(data) / sizeof(data[0]);
std::size_t matches = 0u;
	for (std::size_t ii = 0; ii < ii_max; ++ii) {
	for (std::size_t i = 0; i < data_dimensions; ++i) {
	for (std::size_t j = 0; j < data_dimensions; ++j) {
	if (data[i] == data[j]) {
	++ matches;
	}
}
}
}
return matches;
}
