/*
 * Multithreaded Count to twenty and back to zero program.
 * thread.cpp
 *
 * Created by Victor Enogwe on 20/05/2024.
 */

#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>

#include "thread.h"

using std::cout;
using std::mutex;
using std::this_thread::get_id;

void thread_details(const string &name) {
    printf("Running %s Process:  %d\n", name.c_str(), getpid());
    cout << name << ": " << get_id() << "\n";
}

void thread_runner(
    const string &name,
    void (&thread_function)(int&),
    int& thread_count,
    mutex &thread_lock
) {
    thread_lock.lock();

    thread_details(name);

    thread_function(thread_count);

    thread_lock.unlock();
}
