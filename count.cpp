/*
 * Multithreaded Count to twenty and back to zero Program
 * count.cpp
 *
 * Created by Victor Enogwe on 20/05/2024.
 */

#include <iostream>

#include "count.h"

using std::cout;

void count_to_twenty(int &thread_count) {
    // critical section reading a shared variable

    cout << "Count From " << thread_count << " to 20\n";

    while (thread_count <= 20) {
        cout << thread_count << "\n";

        thread_count++; // critical section writing to shared variable
    }

    thread_count--; // critical section writing to shared variable

    cout << "\n";
}

void count_to_zero(int &thread_count) {
    // critical section reading a shared variable

    cout << "count from " << thread_count << " to 0\n";

    while (thread_count >= 0) {
        cout << thread_count << "\n";
        thread_count--; // critical section writing to shared variable
    }

    cout << "\n";
}