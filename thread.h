/*
 * Multithreaded Count to twenty and back to zero Program
 * thread.h
 *
 * Created by Victor Enogwe on 20/05/2024.
 */

#ifndef THREAD_H
#define THREAD_H

#include <thread>

using std::string;
using std::mutex;

void thread_details(const string &name);
void thread_runner(const string &name, void (&thread_function)(int&), int& thread_count, mutex &thread_lock);

#endif //THREAD_H
