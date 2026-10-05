#include "DynamicString.h"
#include <cctype>
#include <stdexcept>

using std::ostream;
using std::out_of_range;
using std::tolower;
using std::toupper;
using std::ostream;

DynamicString::DynamicString(){
}

DynamicString::DynamicString(const char* str){
}

DynamicString::DynamicString(const DynamicString& other){

}

DynamicString& DynamicString::operator=(const DynamicString& other){

   return *this;
}

DynamicString::~DynamicString(){
   return;
}

int DynamicString::len() const{
   return -1;
}

const char* DynamicString::c_str() const{
   return cstr;
}

char DynamicString::char_at(int position) const{
   return 'z';
}

char& DynamicString::operator[](int position){

   return *(new char('z'));
}

bool DynamicString::startsWith(const DynamicString& other) const{
   return true;
}

bool DynamicString::endsWith(const DynamicString& other) const{
   return true;
}

int DynamicString::compare(const DynamicString& other) const{
   return -1;
}

DynamicString& DynamicString::toLower(){
   return *this;
}

DynamicString& DynamicString::toUpper(){
   return *this;
}

DynamicString& DynamicString::replace(char old, char newCh){
   return *this;
}

int DynamicString::find(char c, int start) const{
   return -1;
}

ostream& operator<<(ostream& out, const DynamicString& str){
   return out;
}
