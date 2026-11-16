#include <iostream> 
#include <cstring> 
#include <chrono> 
#include <utility> 
using namespace std; 
using namespace chrono; 

 
 
 
class String 
{ 
private: 
    char* data; 
    size_t length; 
public: 
    // Constructor 
    String(const char* str = "") 
    { 
        length = strlen(str); 
        data = new char[length + 1]; 
        strcpy(data, str); 
    } 
 
    // Copy Constructor 
    String(const String& other) 
    { 
        length = other.length; 
        data = new char[length + 1]; 
        strcpy(data, other.data); 
    } 
    // Move Constructor 
    String(String&& other) noexcept 
    { 
        data = other.data; 
        length = other.length; 

 
 
 
        other.data = nullptr; 
        other.length = 0; 
    } 
 
    // Copy Assignment Operator 
    String& operator=(const String& other) 
    { 
        if (this != &other) 
        { 
            delete[] data; 
 
            length = other.length; 
            data = new char[length + 1]; 
            strcpy(data, other.data); 
        } 
 
        return *this; 
    } 
 
    // Move Assignment Operator 
    String& operator=(String&& other) noexcept 
    { 
        if (this != &other) 
        { 
            delete[] data; 
 

 
 
            data = other.data; 
            length = other.length; 
 
            other.data = nullptr; 
            other.length = 0; 
        } 
 
        return *this; 
    } 
 
    // Destructor 
    ~String() 
    { 
        delete[] data; 
    } 
 
    void display() const 
    { 
        if (data != nullptr) 
            cout << data << endl; 
    } 
}; 
 
// Perfect Forwarding Function 
template <typename T> 
String createString(T&& value) 
{ 

 
 
    return String(forward<T>(value)); 
} 
 
int main() 
{ 
    const int SIZE = 100000; 
 
    String original( 
        "This is a resource-heavy string used to demonstrate " 
        "copy and move semantics in C++."); 
 
    // Benchmark Copy Operations 
    auto startCopy = high_resolution_clock::now(); 
 
    for (int i = 0; i < SIZE; i++) 
    { 
        String copy = original; 
    } 
 
    auto endCopy = high_resolution_clock::now(); 
 
    auto copyTime = 
        duration_cast<milliseconds>(endCopy - startCopy); 
 
    // Benchmark Move Operations 
    auto startMove = high_resolution_clock::now(); 
 

 
 
    for (int i = 0; i < SIZE; i++) 
    { 
        String temp( 
            "This is a resource-heavy string used for " 
            "move semantics."); 
 
        String moved = move(temp); 
    } 
 
    auto endMove = high_resolution_clock::now(); 
 
    auto moveTime = 
        duration_cast<milliseconds>(endMove - startMove); 

        // Test Case 1: Additional Copy Benchmark
auto startCopy2 = high_resolution_clock::now();

for (int i = 0; i < SIZE; i++)
{
    String copy2("Another string for copy testing");
}

auto endCopy2 = high_resolution_clock::now();

auto copyTime2 =
    duration_cast<milliseconds>(endCopy2 - startCopy2);

    // Test Case 2: Additional Move Benchmark
auto startMove2 = high_resolution_clock::now();

for (int i = 0; i < SIZE; i++)
{
    String temp2("Another string for move testing");
    String moved2 = move(temp2);
}

auto endMove2 = high_resolution_clock::now();

auto moveTime2 =
    duration_cast<milliseconds>(endMove2 - startMove2);
 
    // Perfect Forwarding Demonstration 
    String forwarded = createString( 
        "Perfect Forwarding Example"); 
 
    cout << "Perfect Forwarding Result: "; 
    forwarded.display(); 
 
    // Display Benchmark Results 
    cout << "\nCopy Operation Time: " 
         << copyTime.count() 
         << " milliseconds" << endl; 
 
    cout << "Move Operation Time: " 

 
 
         << moveTime.count() 
         << " milliseconds" << endl; 

         cout << "\nAdditional Copy Operation Time: "
     << copyTime2.count()
     << " milliseconds" << endl;

cout << "Additional Move Operation Time: "
     << moveTime2.count()
     << " milliseconds" << endl;
 
    return 0; 
} 