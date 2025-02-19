#include "Poly.h"

using namespace std;

// overloaded istream operator
istream &operator>>(istream &inStream, Poly &sourceCoeff)
{
    int coeff;
    int power;
    while (true)
    {
        inStream >> coeff >> power;
        if ((coeff == -1 && power == -1))
        {
            break;
        }
        sourceCoeff.setCoeff(coeff, power); // sets coefficient and power when accepting user input
    }
    return inStream;
}

// overloaded ostream operator
ostream &operator<<(ostream &outStream, const Poly &SourcePoly)
{
    for (int i = SourcePoly.size - 1; i >= 0; i--) // starts at back of array, works towards front
    {
        if (SourcePoly.coeffPtr[i] != 0) // array of power (size) 5 and coefficient 4 would have coeffPtr[5] == 4,
                                         // other values initialized to 0, skip those values
        {
            outStream << " ";
            if (SourcePoly.coeffPtr[i] > 0) // sets + before positive coefficients
            {
                outStream << "+";
            }
            if (i == 1) // sets first x
            {
                outStream << SourcePoly.coeffPtr[i] << "x";
            }
            if (i == 0) // sets first coefficient
            {
                outStream << SourcePoly.coeffPtr[i];
            }
            else if (i != 1) // sets the rest of the coefficients and their powers
            {

                outStream << SourcePoly.coeffPtr[i] << "x" << "^" << i;
            }
        }
    }
    return outStream;
}

// getter
int Poly::getCoeff(int power) const
{
    if (power < 0 && size > power) // checks if index is valid
    {
        std::cerr << "Index out of bounds" << endl;
        return 0;
    }
    else
    {
        return coeffPtr[power];
    }
}

// setter
void Poly::setCoeff(int coeff, int power)
{
    if (power >= size) // if index is valid and greater than or equal to size, array needs to be resized
    {
        int *temp = new int[power + 1]; // dynamically allocates new array temporarily to resize coeffptr
        for (int i = 0; i < size; i++)  // fills temp with existing coeffPtr values
        {
            temp[i] = coeffPtr[i];
        }
        for (int j = size; j < power; j++) // fills extra spaces with 0s
        {
            temp[j] = 0;
        }
        temp[power] = coeff; // sets temp to coeff and power value passed in from parameter
        delete[] coeffPtr;   // deletes old pointer
        coeffPtr = nullptr;  // sets old pointer to nullptr to avoid dangling pointers
        coeffPtr = temp;     // sets pointer to temp, effectively resizing coeffPtr
        temp = nullptr;      // sets temp to nullptr
        size = power + 1;    // resizes size to be current power plus one to align coefficient and power values effectively
    }
    coeffPtr[power] = coeff; // passes parameter values to coeffPtr
}

// default constructor
Poly::Poly()
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = 0;
}

// constructor takes one parameter
Poly::Poly(int coeff)
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = coeff;
}
// constructor takes two parameters, an exercise in polymorphism
Poly::Poly(int coeff, int power)
{
    size = power + 1;
    coeffPtr = new int[size];
    coeffPtr[power] = coeff;
}

// copy constructor creates deep copy of pointer so it has its own memory allocated instead of sharing memory
Poly::Poly(const Poly &source)
{
    size = source.size + 1;
    coeffPtr = new int[size];
    for (int i = 0; i < size; i++)
    {
        coeffPtr[i] = source.coeffPtr[i];
    }
}

// assignment operator
Poly &Poly::operator=(const Poly &rhs)
{
    if (this == &rhs) // if both values are equal, return pointer to current object
    {
        return *this;
    }
    delete[] coeffPtr; // delete to allow reassignment
    size = rhs.size;
    coeffPtr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        coeffPtr[i] = rhs.coeffPtr[i];
    }
    return *this;
}

// overloaded addition operator
Poly Poly::operator+(const Poly &rhs) const
{
    int reSize = max(size, rhs.size); // sets size large enough to account for maximum index size
    Poly result(0, reSize - 1);       // creates new Poly object with values 0, size = max - 1 for proper alignment
    for (int i = 0; i < size; i++)    // fills result with left hand side values
    {
        result.coeffPtr[i] = coeffPtr[i];
    }

    for (int i = 0; i < rhs.size; i++) // adds left hand to right hand side values
    {
        result.coeffPtr[i] += rhs.coeffPtr[i];
    }
    return result;
}

// overloaded == comparator
bool Poly::operator==(const Poly &rhs) const
{
    return (coeffPtr == rhs.coeffPtr);
}

// overloaded != comparator
bool Poly::operator!=(const Poly &rhs) const
{
    return (coeffPtr != rhs.coeffPtr);
}

// helper method to debug, prints values, useful for placing inside loops
void Poly::printPoly(const Poly &p, const std::string &label) const
{
    std::cout << label << ": ";
    for (int i = p.size - 1; i >= 0; i--)
    {
        std::cout << p.coeffPtr[i] << "x^" << i << " ";
    }
    std::cout << endl;
}

// overloaded subtraction operator, considers that subtraction is not commutative
Poly Poly::operator-(const Poly &rhs) const
{
    int reSize = max(size, rhs.size);
    Poly result(0, reSize - 1);
    for (int i = 0; i < size; i++)
    {
        result.coeffPtr[i] = coeffPtr[i];
    }

    for (int i = 0; i < rhs.size; i++)
    {
        result.coeffPtr[i] -= rhs.coeffPtr[i];
    }
    return result;
}

// overloaded multiplication operator
Poly Poly::operator*(const Poly &rhs) const
{
    int reSize = size + rhs.size - 1; // sets max size equal to both sizes - 1
    Poly result(0, reSize - 1);
    for (int i = 0; i < size; i++)
    {
        if (coeffPtr[i] == 0) // skips index i where coeff == 0 to avoid multiplication by 0
        {
            continue;
        }
        for (int j = 0; j < rhs.size; j++)
        {
            if (rhs.coeffPtr[j] == 0) // skips index j where coeff == 0 to avoid multiplication by 0
            {
                continue;
            }
            else
            {
                // example 1st iteration: i = 7, j = 4, coeffPtr[7] = 5, rhs.coeffPtr[4] = 3. simulates distributive property
                // result.coeffPtr[7 + 4] += (coeffPtr[5] * rhs.coeffPtr[3]) -> result.coeffPtr[11] = 15 -> +15x^11
                result.coeffPtr[i + j] += (coeffPtr[i] * rhs.coeffPtr[j]);
            }
        }
    }
    return result;
}

// compound assignment operators, enables encapsulation by modifying objects internal state
Poly &Poly::operator+=(const Poly &rhs)
{
    *this = *this + rhs;
    return *this;
}

// also, as an operator overload, is polymorphism, updates existing object instead of creating new one
Poly &Poly::operator-=(const Poly &rhs)
{
    *this = *this - rhs;
    return *this;
}

// enables abstraction in main, user can, for example, write Poly A(5), Poly B(6), and simply say A * B and receive the result
// while details of implementation are hidden from the user
Poly &Poly::operator*=(const Poly &rhs)
{
    *this = *this * rhs;
    return *this;
}

//  Destructor deletes pointer when object is out of scope, preventing memory leaks
//  All heap blocks were freed -- no leaks are possible
Poly::~Poly()
{
    delete[] coeffPtr;
}