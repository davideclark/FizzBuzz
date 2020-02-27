// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

string fizz_buzz(int n);

auto fizz_buzz(int n)->string;  // Alternate syntax
auto const ceiling = 100;
auto const Fizz = std::string{ "Fizz" };
auto const Buzz = std::string{ "Buzz" };
auto const FizzBuzz = Fizz + Buzz;

map<int, string> make_fizz_buzz(vector<int> const& numbers);


int main()
{
    // auto m = mayfly();
    // raii, memory allocation bit like c# using to manage the lift time of the numbers object
    auto const numbers = std::vector<int>{ 1,2,3,4,5,13,15,21 };
    auto const number_to_fb = make_fizz_buzz(numbers);

    auto outputFile = ofstream{ "fizzBuzz.txt" };
    // requires c++ language version 17
    for (auto [num, fb] : number_to_fb)
    {
        std::cout << num << fb << "\n";
        outputFile << num << fb << "\n";
    }
}



map<int, string> make_fizz_buzz(vector<int> const& numbers) {
    auto number_to_fb = map<int, string>{ };

    for (auto i : numbers) {
        number_to_fb[i] = fizz_buzz(i);
    }
    return number_to_fb;
}



string fizz_buzz(int i) {
        if (i % 15 == 0) {
            return FizzBuzz;
        }

        if (i % 3 == 0) {
            return Fizz;
        }
        else if (i % 5 == 0) {
            return Buzz;
        }
        else {
            return std::to_string(i);
        }
    
}

class mayfly {
public :
    mayfly()
    {
        std::cout << "born "<< "\n";

    }

    // copy constructor, delete makes the mayfly inutable
    mayfly(mayfly const& rhs) = delete;
    //    mayfly(mayfly const& rhs) {

    //}

    ~mayfly()
    {
        std::cout << "die " << "\n";

    }
    void eat() {
        std::cout << "eat" << "\n";

    }
};

