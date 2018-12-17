//
// Created by aslan on 02.12.18.
//
#include <iostream>
#include <future>

using namespace std;

void sayHello(promise<string> promise1){
    cout << " Hello from " << this_thread::get_id() << endl;
    promise1.set_value("Hello papa");
}


int main(){
    promise<string> promiseObj;

    future<string> futureObj = promiseObj.get_future();

    async(launch::async, sayHello, move(promiseObj));

    cout<< futureObj.get() << endl;
}