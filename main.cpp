// DO NOT change anything in this file. Your code must compile and give the
// correct output with this main on the linux machines.

// Make sure the file containing the member function source is: poly.cpp
// Use all lowercase in the file names.

// This main does not do a thorough job of testing.  When testing arrays,
// be sure to test the middle and also all the boundary conditions.  Test
// values on the boundary and outside the boundaries, i.e., too big/small.

#include "Poly.h"
#include <iostream>

using namespace std;

int main()
{

     // Poly A;
     // Poly B;

     // cout << "Enter terms for polynomial A.  Enter a coefficient " << endl
     //      << "then exponent for each term. Enter -1 -1 to terminate." << endl;
     // cin >> A;

     // cout << "Enter terms for polynomial B.  Enter a coefficient " << endl
     //      << "then exponent for each term. Enter -1 -1 to terminate." << endl;
     // cin >> B;

     // cout << A << endl;
     // cout << B << endl;

     // set poly A and print
     // Poly A(5, 7);
     // A.setCoeff(10, 1);
     // A.setCoeff(-4, 3);
     // A.setCoeff(-2, 0);
     // cout << "A =    " << A << endl;
     // cout << "=== A = +5x^7 -4x^3 +10x -2" << endl
     //      << endl;

     // // set poly B and print
     // Poly B(3, 4);
     // B.setCoeff(1, 3);
     // cout << "B =    " << B << endl;
     // cout << "=== B = +3x^4 +1x^3" << endl
     //      << endl;
     // //
     // // Min Chen Polies
     // Poly C(2), D(A), X, Y;
     // Poly A2, B2, Z1, Z2;

     // A2 = A;
     // cout << "A2 = " << A2 << endl;

     // B2 = B;
     // cout << "B2 = " << B2 << endl;

     // C = A + B;
     // cout << "C = " << C << endl
     //      << endl;

     // cout << ((A == B) ? "A == B" : "A is not == B") << endl;
     // cout << ((A != B) ? "A is not == B" : "A == B") << endl
     //      << endl;

     // Z1 = A2 - B2;
     // cout << "Z1 =    " << Z1 << endl;
     // cout << "=== Z1 = +5x^7 -3x^4 -5x^3 +10x -2" << endl
     //      << endl;

     // Z2 = B2 - A2;
     // cout << "Z2 =    " << Z2 << endl;
     // cout << "=== Z2 = -5x^7 +3x^4 +5x^3 -10x +2" << endl
     //      << endl;

     //--------------------------------------------

     //    Poly A(5, 7), B(3, 4), C(2), D(A), X, Y;
     //    Poly A2, B2, Z1, Z2;
     //
     //    A.setCoeff(10, 1);
     //    A.setCoeff(-4, 3);
     //    A.setCoeff(-2, 0);

     Poly A(5, 7), B(3, 4), C(2), D(A), X, Y;
     Poly A2, B2, Z1, Z2;

     // set polynomials A and B to desired values
     // A = +5x^7 -4x^3 +10x -2
     // B = +3x^4 +1x^3
     //     cout << "Enter terms for polynomial A.  Enter a coefficient " << endl
     //     << "then exponent for each term. Enter -1 -1 to terminate." << endl;
     // //    cin >> A;                                     // or use a bunch of setCoeff
     A.setCoeff(5, 7);
     A.setCoeff(10, 1);
     A.setCoeff(-4, 3);
     A.setCoeff(-2, 0);

     //     cout << "Enter terms for polynomial B.  Enter a coefficient " << endl
     //     << "then exponent for each term. Enter -1 -1 to terminate." << endl;
     // //    cin >> B;                                     // or use a bunch of setCoeff
     B.setCoeff(3, 4);
     B.setCoeff(1, 3);

     // outputs exactly what is in quotes: "A = +5x^7 -4x^3 +10x -2"
     cout << "A =" << A << endl;
     // outputs exactly what is in quotes: "B = +3x^4 +1x^3"
     cout << "B =" << B << endl
          << endl;

     A2 = A;
     B2 = B;
     C = A + B;
     cout << "Compute C = A + B: " << C << endl
          << endl;

     cout << ((A == B) ? "A == B" : "A is not == B") << endl;
     cout << ((A != B) ? "A is not == B" : "A == B") << endl
          << endl;

     Z1 = A2 - B2;
     cout << "Compute  Z1 = A2 - B2: " << Z1 << endl;
     Z2 = B2 - A2;
     cout << "Compute  Z2 = B2 - A2: " << Z2 << endl
          << endl;

     cout << "Compute  D = A * B - 15" << endl;
     cout << "Before A = " << A << " Before B =" << B << endl;
     cout << "Before: D =" << D << endl;
     D = A * B - 15;
     cout << "After:  D =" << D << endl
          << endl;

     cout << "Test assignment operators" << endl;
     X = C = D = D;
     Y += A -= B *= A;
     cout << "X =" << X << endl;
     cout << "Y =" << Y << endl
          << endl;

     cout << "Get and Set coefficient" << endl;
     int coeff = D.getCoeff(0);
     cout << "coeff of subscript 0 of D is: " << coeff << endl;
     cout << "Doing getCoeff for term -20000" << endl;
     coeff = D.getCoeff(-20000); // handle value out of range
     coeff = D.getCoeff(10000);
     D.setCoeff(50, 0);     // set x^0 coeff to 50
     D.setCoeff(50, 20000); // set x^20000 coeff to 50
     cout << "D =" << D << endl
          << endl;

     return 0;
}
