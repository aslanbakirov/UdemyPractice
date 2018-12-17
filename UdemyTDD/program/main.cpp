//
// Created by aslan on 10.12.18.
//

#include <iostream>
#include "../src/Math.h"

using  namespace std;

int main(){
    cout << "Hello world" << "\n";
    Math math;
    auto r=math.add(30,10);
    cout<< "Result is: " << r <<"\n";
}