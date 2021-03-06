#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
       - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};

 // creates the date January 1st, 2000.
   Date::Date() {
       month = 1;
       monthName = "January";
       day = 1;
       year = 2000;
       
   }
   
   Date::Date(unsigned m, unsigned d, unsigned y) {
       year = y;
       if (m == 0) {
          m = 1;
       }
       if (m > 12) {
          m = 12;
       }
       month = m;
       day = d;
       if (day > daysPerMonth(month,year)) {
          day = daysPerMonth(month,year);
       }
       if (day < 1) {
          day = 1;
       }

       
       monthName = name(month);
       if(month != m || day != d){
          
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' <<  endl;
         
       }
   }
   
   Date::Date(const string &mn, unsigned d, unsigned y) {
       month = number(mn);

       year = y;
       if (month == 0) {
          month = 1;
       }
       if (month > 12) {
          month = 12;
       }
       monthName = name(month);
       day = d;
       if (day > daysPerMonth(month,year)) {
          day = daysPerMonth(month,year);
       }
       if (day < 1) {
          day = 1;
       }
      
       if (mn.size() != monthName.size()) {
          year  = 2000;
          day = 1;
         cout << "Invalid month name: the Date was set to " << month << '/' << day << '/' << year << '.'<< endl;
         return;
       }
       if(day != d){
          
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' <<  endl;
         
       }


}

void Date::printNumeric() const {
    cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const {
    cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const {
    bool x;
    
    // (year % 4 == 0) implies leap year
    // except (year % 100 == 0) implies NOT leap year
    // except (year % 400 == 0) implies leap year

    if ((y % 4 == 0) && !(y % 100 == 0)) {
        x = true;
    } else if (y % 400 == 0) {
        x = true;
    } else {
        x = false;
    }
    return x;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
    int days;
    switch(m) {
        case 1:
        days = 31;
        break;
        case 2:
        if (!isLeap(y)) {
            days = 28;
        } else {
            days = 29;
        }
        break;
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        days = 31;
        break;
        default:
        days = 30;
        break;
    }
    return days;
}

string Date::name(unsigned m) const {
    string monthName;
    switch(m) {
        case 1:
        monthName = "January";
        break;
        case 2:
        monthName = "February";
        break;
        case 3:
        monthName = "March";
        break;
        case 4:
        monthName = "April";
        break;
        case 5:
        monthName = "May";
        break;
        case 6:
        monthName = "June";
        break;
        case 7:
        monthName = "July";
        break;
        case 8:
        monthName = "August";
        break;
        case 9:
        monthName = "September";
        break;
        case 10:
        monthName = "October";
        break;
        case 11:
        monthName = "November";
        break;
        case 12: 
        monthName = "December";
        break;
    }
    return monthName;
}


   unsigned Date::number(const string &mn) const {
      
      if (mn == "January" || mn == "january") {
         return 1;
      }
      if (mn == "February" || mn == "february") {
         return 2;
      }
      if (mn == "March" || mn == "march") {
         return 3;
      }
      if (mn == "April" || mn == "april") {
         return 4;
      }
      if (mn == "May" || mn == "may") {
         return 5;
      }
      if (mn == "June" || mn == "june") {
         return 6;
      }
      if (mn == "July" || mn == "july") {
         return 7;
      }
      if (mn == "August" || mn == "august") {
         return 8;
      }
      if (mn == "September" || mn == "september") {
         return 9;
      }
      if (mn == "October" || mn == "october") {
         return 10;
      }
      if (mn == "November" || mn == "november") {
         return 11;
      }
      if (mn == "December" || mn == "december") {
         return 12;
      }
      
      //       if (temp == "January") {
      //    return 1;
      // }
      // if (temp == "February") {
      //    return 2;
      // }
      // if (temp == "March") {
      //    return 3;
      // }
      // if (temp == "April") {
      //    return 4;
      // }
      // if (temp == "May") {
      //    return 5;
      // }
      // if (temp == "June") {
      //    return 6;
      // }
      // if (temp == "July") {
      //    return 7;
      // }
      // if (temp == "August") {
      //    return 8;
      // }
      // if (temp == "September") {
      //    return 9;
      // }
      // if (temp == "October") {
      //    return 10;
      // }
      // if (temp == "November") {
      //    return 11;
      // }
      // if (temp == "December") {
      //    return 12;
      // }
      
      return 1;
      
}

Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}