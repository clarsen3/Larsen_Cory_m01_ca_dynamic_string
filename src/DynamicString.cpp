#include "DynamicString.h"
#include <cctype>
#include <stdexcept>

using std::ostream;
using std::out_of_range;
using std::tolower;
using std::toupper;
using std::ostream;

DynamicString::DynamicString(){
   cstr = new char[1];

   cstr[0] = '\0';
};

DynamicString::DynamicString(const char* str){
   int length = 0;

   while(str[length] != '\0'){
      length++;
   }

   cstr = new char[length + 1];

   for(int i = 0; i < length; i++) {
      cstr[i] = str[i];
   }

   cstr[length] = '\0';
}

DynamicString::DynamicString(const DynamicString& other){
   cstr = new char[other.len() + 1];

   for(int i = 0; i < other.len(); i++) {
      cstr[i] = other.cstr[i];
   }

   cstr[other.len()] = '\0';

}

DynamicString& DynamicString::operator=(const DynamicString& other){
   if (this == &other) {
      return *this;
   }

   int length = 0;

   while (other.cstr[length] != '\0') {
      length++;
   }

   char* deepCopy = new char[length + 1];

   for(int i = 0; i < length; i++) {
      deepCopy[i] = other.cstr[i];
   }
   deepCopy[length] = '\0';

   delete[] cstr;
   cstr = deepCopy;

   return *this;
}

DynamicString::~DynamicString(){
   delete[] cstr;
}

int DynamicString::len() const{
   int length = 0;

   while (cstr[length] != '\0') {
      ++length;
   }

   return length;
}

const char* DynamicString::c_str() const{
   return cstr;
}

char DynamicString::char_at(int position) const{
   if (position < 0 || position >= len()) {
      throw out_of_range("Position out of range");
   }

   return cstr[position];
}

char& DynamicString::operator[](int position){
   if (position < 0 || position >= len()) {
      throw out_of_range("Position out of range");
   }

   return cstr[position];
}

bool DynamicString::startsWith(const DynamicString& other) const{
   int otherLength = other.len();

   if (otherLength > len()) {
      return false;
   }

   for (int i = 0; i < otherLength; i++) {
      if (cstr[i] != other.cstr[i]) {
         return false;
      }
   }

   return true;
}

bool DynamicString::endsWith(const DynamicString& other) const{
   int otherLength = other.len();

   if (otherLength > len()) {
      return false;
   }

   int difference = len() - otherLength;

   for (int i = 0; i < otherLength; i++) {
      if (cstr[difference + i] != other.cstr[i]) {
         return false;
      }
   }

   return true;
}

int DynamicString::compare(const DynamicString& other) const{
   int i = 0;
   
   while(cstr[i] != '\0' && other.cstr[i] != '\0') {
      if (cstr[i] < other.cstr[i]) {
         return -1;
      }
      if (cstr[i] > other.cstr[i]) {
         return 1;
      }
      i++;
   }

   if (cstr[i] == '\0' && other.cstr[i] == '\0') {
      return 0;
   }

   return (cstr[i] == '\0') ? -1 : 1;
}

DynamicString& DynamicString::toLower(){
   for (int i = 0; i < len(); i++) {
      cstr[i] = tolower(cstr[i]);
   }

   return *this;
}

DynamicString& DynamicString::toUpper(){
   for (int i = 0; i < len(); i++) {
      cstr[i] = toupper(cstr[i]);
   }

   return *this;
}

DynamicString& DynamicString::replace(char old, char newCh){
   for (int i = 0; i < len(); i++) {
      if (cstr[i] == old) {
         cstr[i] = newCh;
      }
   }

   return *this;
}

int DynamicString::find(char c, int start) const{
   if (start < 0) {
      start = 0;
   }

   for (int i = start; i < len(); i++) {
      if (cstr[i] == c) {
         return i;
      }
   }

   return -1;
}


ostream& operator<<(ostream& out, const DynamicString& str){
   for (int i = 0; i < str.len(); i++) {
      out << str.c_str()[i];
   }

   return out;
}
