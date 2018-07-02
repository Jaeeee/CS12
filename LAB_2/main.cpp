#include <iostream>

using namespace std;

class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};


Rational::Rational() {
   numerator = 0;
   denominator = 1;
} 

Rational::Rational(int num) {
   numerator = num;
   denominator = 1;
}

Rational::Rational(int x, int y) {
   numerator = x;
   denominator = y;
}

const Rational Rational::add(const Rational &rational) const {
   Rational x;
   x.numerator = rational.numerator * denominator + rational.denominator * numerator;
   x.denominator = rational.denominator * denominator;
   return x;
}

const Rational Rational::subtract(const Rational &rational) const {
   Rational x;
   x.numerator = rational.denominator * numerator -  rational.numerator * denominator ;
   x.denominator = denominator * rational.denominator;
   return x;
}

const Rational Rational::multiply(const Rational &rational) const {
   Rational x;
   x.numerator = rational.numerator * numerator;
   x.denominator = denominator * rational.denominator;
   return x;
}

const Rational Rational::divide(const Rational & rational) const {
   Rational x;
   x.numerator = rational.denominator * numerator;
   x.denominator = denominator * rational.numerator;
   if (denominator != 0) {
      x.simplify();
   }
   return x;
}

void Rational::simplify() {
   int n = numerator < 0 ? -numerator: numerator;
   int d = denominator;
   int largest = n > d ? n : d;
   int gcd = 0;
   
   for (int i = largest; i >= 2; i--) {
      if (numerator % i == 0 && denominator % i == 0) {
         gcd = i;
         break;
      }
   }
   
   if (gcd !=0) {
      numerator /= gcd;
      denominator /= gcd;
   }
}

void Rational::display() const {
   if (denominator == 0) {
      cout << endl << "divide by 0" << endl;
   // } else if (numerator == 0) {
   //       cout << 0;
   } else {
   cout << numerator << " / " << denominator;
   }
}

int Rational::gcd(int x, int y) const {
   int ans = 0;
   int largestValue = x > y ? x : y;
   for (int i = largestValue; i >= 2; i--) {
      if (numerator % i == 0 && denominator % i == 0) {
         ans = i;
         break;
      }
   }
   return ans;
}

Rational getRational();

void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   int choice;

   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;

   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;

   cout << "Enter Operation (1 - 4):" << endl
      << "1 - Addition (A + B)" << endl
      << "2 - Subtraction (A - B)" << endl
      << "3 - Multiplication (A * B)" << endl
      << "4 - Division (A / B)" << endl
      << "5 - Simplify A" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 2) {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 3) {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 4) {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 5) {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;

   return 0;
}

Rational getRational() {
   int choice;
   int numer, denom;

   cout << "Which Rational constructor? (Enter 1, 2, or 3)" << endl
      << "1 - 2 parameters (numerator & denominator)" << endl
      << "2 - 1 parameter (numerator)" << endl
      << "3 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

