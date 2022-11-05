#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!" << std::endl;
    vector<int> v = {1, 2, 3, 4, 5};

    // multiply each value in vector by 2
    for (int i = 0; i < v.size(); i++)
    {
        v[i] *= 2;
    }

    // print out the vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}