#include <hello.h>
#include <vector>
#include <iostream>

int main(void)
{
    HelloFunc();

    using namespace std;
    std::vector<int> vec(4);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(8);

    vec.pop_back();
    cout << "vec size: " << vec.size() << endl;
}
