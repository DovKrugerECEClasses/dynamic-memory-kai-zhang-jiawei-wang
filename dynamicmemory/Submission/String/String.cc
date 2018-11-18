#include "String.hh"
#include<iostream>
#include<string>
#include<cstdint>
using namesapce std;

String::String() :len(0),s(nullptr){}

String::String(const char str[]):len(strlen(str), s(new char[len]) {
	for (int i=0; i<len; i++)
		s[i]=str[i];
}
	
String::String(const char str[], uint32_t mult):len(strlen(str)*mult),s(new char[len]) {
	uint32_t strsize=len/mult;
	int c=0;
	for (int i=0; i<mult; i++)
		for(int j=0; j<strsize; j++,c++)
			s[c]=str[i];
}

String::~String() {
	delete [] s;
}

	//copy constructor
String::String(const String& orig) {
	len=orig.len;
	s=new char[len];
	uint64_t *src = (uint64_t *) orig.s;
    uint64_t *dest = (uint64_t *) s;
    uint32_t count;
    for (count = len; count >= 8; count -= 8) {
        *dest++ = *src++;
    }
    char* pdest = (char*)des;
    char* psrc = (char*)src;
    for (count = len; count > 0; count--) {
        *pdest++ = *psrc++;
    }
}
String& String::operator =(const String& orig) {
	String copy(orig);
	len=orig.len;
	swap(s, copy.s);
	
	return *this;
}

char String::operator [](const uint32_t pos)const {
	return s[pos];
}
char& String::operator [](uint32_t pos) {
	return s[pos];
}

ostream& operator<<(ostream& s, const String& str) {
	for  (int i =0; i<str.len;i++)
		s<<str[i];
	return s;
}

	
