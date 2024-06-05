/*
 * Multithreaded Count to twenty and back to zero program.
 * main.cpp
 *
 * Created by Victor Enogwe on 20/05/2024.
 */

#include <iostream>

#include "thread.h"
#include "count.h"

using std::cout;
using std::thread;
using std::ref;

int main() {
    thread_details("Count Up and Down Main Thread");
    cout << "\n";

    // critical variable modified in two concurrent threads.
    int thread_count = 0;

    mutex thread_lock;

    thread count_up(
        thread_runner,
        "Count Up Thread",
        ref(count_to_twenty),
        ref(thread_count),
        ref(thread_lock)
    );

    thread count_down(
        thread_runner,
        "Count Down Thread",
        ref(count_to_zero),
        ref(thread_count),
        ref(thread_lock)
    );

    count_up.join();
    count_down.join();

    return 0;
}
