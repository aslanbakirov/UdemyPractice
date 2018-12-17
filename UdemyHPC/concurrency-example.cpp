//
// Created by aslan on 02.12.18.
//

#include <iostream>
#include <future>
#include <chrono>

using namespace std;

void sayHello(){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << endl << "Hello Concurrency support library! from " << std::this_thread::get_id() << endl;
}

int main(){
    cout << endl << "Hello from " << std::this_thread::get_id() << endl;
    future<void> futureObj = async(launch::async, sayHello);
    futureObj.wait();

    exit(0);
}
