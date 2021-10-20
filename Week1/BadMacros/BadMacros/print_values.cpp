#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << std::endl << (y) << std::endl

int main() {
    TestRunner tr;
    /*int n = 0;
    while (n != 10)
    {
        PRINT_VALUES(std::cout, 5, "red belt");
        ++n;
    }*/
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
    }, "PRINT_VALUES usage example");
    return 0;
}
