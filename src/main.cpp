#include "./skip-list/skip-list.hh"
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main() {
    // Seed random number generator
    srand(time(nullptr));

    // Test with ordered numbers from 1 to 10
    cout << "Test with ordered numbers from 1 to 10:" << endl;
    SkipList skipList1(4); // Maximum level set to 4 for demonstration
    for (int i = 1; i <= 10; ++i)
        skipList1.insert(i);
    skipList1.display();

    // Test with unordered numbers
    cout << "\nTest with unordered numbers:" << endl;
    SkipList skipList2(5); // Maximum level set to 5 for demonstration
    vector<int> unorderedNumbers = {3, 9, 1, 7, 2, 5, 8, 6, 10, 4};
    for (int num : unorderedNumbers)
        skipList2.insert(num);
    skipList2.display();

    // Test time performance
    cout << "\nPerformance test with 1,000,000 ordered numbers:" << endl;
    SkipList skipList3(20); // Maximum level set to 20 for better performance test
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 1; i <= 1000000; ++i)
        skipList3.insert(i);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Time taken to insert 1,000,000 ordered numbers: " << duration << " milliseconds" << endl;

    return 0;
}
