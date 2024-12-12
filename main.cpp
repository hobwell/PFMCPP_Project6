/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    int value = 0; // 2
    std::string name = ""; // 3

    T (int val, const char* charPtr) : value{val}, name{charPtr} {}
};

struct F                               // 4
{
    T* compare (T& a, T& b) // 5
    {
        if (a.value < b.value) return &a;
        if (a.value > b.value) return &b;
        return nullptr;
    }
};

struct U
{
    float height { 0.0f }, width { 0.0f };
    
    float almostSquare (const float& newValue)      // 12
    {
        std::cout << "U's height value: " << this->height << std::endl;
        this->height = newValue;
        std::cout << "U's height updated value: " << this->height << std::endl;

        while (std::abs (this->width - this->height) > 0.001f)
        {
            // shrink the distance between this->width and this->height
            this->width += this->height / 1000.0f;
        }

        std::cout << "U's width updated value: " << this->width << std::endl;
        
        return this->width * this->height;
    }
};

struct I
{
    static float almostSquare (U& that, const float& newValue)        // 10
    {
        std::cout << "U's height value: " << that.height << std::endl;
        that.height = newValue;
        std::cout << "U's height updated value: " << that.height << std::endl;
        
        while (std::abs (that.width - that.height) > 0.001f)
        {
            // shrink the distance between that->width and that->height
            that.width += that.height / 1000.0f;
        }
            
        std::cout << "U's width updated value: " << that.width << std::endl;
        
        return that.width * that.height;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1 (1, "one");                                             // 6
    T t2 (2, "two");                                             // 6
    
    F f;                                                        // 7
    
    auto* smaller = f.compare (t1, t2);                       // 8
    
    if (smaller == nullptr)
    {
        std::cout << "f.compare returned nullptr" << std::endl;
        std::cout << "the values of the compared items are equal" << std::endl;
    }
    else
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; // 9    
    }    
    
    U u1;
    float updatedValue = 5.0f;
    std::cout << "[static func] u1's multiplied values: " << I::almostSquare (u1, updatedValue) << std::endl;                  // 11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.almostSquare (updatedValue) << std::endl;
}
