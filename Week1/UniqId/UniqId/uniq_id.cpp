#include <string>
#include <vector>
using namespace std;

#define UNIQ_ID_GLUE(line) id_number_##line
#define UNIQ_ID_HELPER(line) UNIQ_ID_GLUE(line)
#define UNIQ_ID UNIQ_ID_HELPER(__LINE__)

int main() {
    int UNIQ_ID = 0;
    string UNIQ_ID = "hello";
    vector<string> UNIQ_ID = { "hello", "world" };
    vector<int> UNIQ_ID = { 1, 2, 3, 4 };
}