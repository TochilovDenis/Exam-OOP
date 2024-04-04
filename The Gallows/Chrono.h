#pragma once
#include <chrono>
#include <iostream>

using namespace std::chrono;

class Chrono {
private:
    steady_clock::time_point startTime;
public:
    Chrono() : startTime(steady_clock::now()) {}
    duration<double> elapsed() const { return steady_clock::now() - startTime; }
    void PrintTime() const { std::cout << "Затраченное время: " << elapsed().count() << " секунд" << std::endl; }
};