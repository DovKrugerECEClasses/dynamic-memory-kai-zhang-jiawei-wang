#include "String.hh"
#include<string>

//constructors
String::String() {
	cap = 2;
	len = 1;
	s = new char[cap];
	s[0] = ' ';
}

String::String(const char str[]) {
	int size = 2 * stringlen(str);
	s = new char[size];
	len = stringlen(str);
	cap = size;
	for(int i = 0; i < size; i++)
		s[i] = str[i];
}

String::String(const char str[], uint32_t mult) {
	int size = 2 * stringlen(str) * mult;
	s = new char[size];
	len = stringlen(str)*mult;
	cap = size;
	int i = 0;
	while( i < stringlen(str)*mult){
		for(int j = 0; j < stringlen(str); j++)
			s[i++] = str[j];
	}
}

String::~String() {
	delete [] s;
}

//utility functions
uint32_t String::length() const{
	return len;
}

void String::replace(char a, char b){
	for(int i = 0; i < len; i++){
		if(s[i] == a)
			s[i] = b;
	}
}

void String::insert(uint32_t pos, String msg){
	int size = msg.length() + length();

	len = size;
	grow(size);

	//shifting chars to make room for insert
	for (int i = msg.len+pos; i > pos; i--)
		s[i+1] = s[i];

	//the insert
	for(int i = 0; i < msg.len; i++)
		s[pos+i] = msg[i];

}

String String::substring(uint32_t pos, uint32_t length) const{
	char* temp = new char[length];

	for(int i = 0; i < length; i++)
		temp[i] = s[pos+i];

	return String(temp);
}

//copy constructor
String::String(const String& orig) : len(orig.len), cap(orig.cap), s(new char[orig.cap]) {
	uint64_t* src = (uint64_t*)orig.s;
	uint64_t* dest = (uint64_t*)s;
	uint32_t count;
	for (count = len; count >= 8; count -= 8)
		*dest++ = *src++;
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	for ( ; count > 0; count--)
		*pdest++ = *psrc++;
}

//operator functions
String& String::operator =(const String& orig) {
	String copy(orig);
	std::swap(copy.s, s);
	cap = orig.cap;
	len = orig.len;

	return *this;
}

String& String::operator +=(const String& right) {
	int size = 2 * (right.len + len);
	grow(size);

	for(int i = 0; i < right.len; i++)
		s[len+i] = right[i];
	len = right.len+len;

	return *this;
}

String String::operator +(const String& right) const{
	int size = 2 * (right.len + len);
	char* temp = new char[size];

	int i;
	for(i = 0; i < len; i++)
		temp[i] = s[i];
	for(int j = 0; j < right.len; j++)
		temp[i + j] = right[j];

	return String(temp);
}

char String::operator [](const uint32_t pos)const {
	return s[pos];
}

char& String::operator [](uint32_t pos) {
	return s[pos];
}

std::ostream& operator<<(std::ostream& stream, const String& str) {
	for(int i = 0; i < str.len; i++)
		stream << str.s[i];
	return stream;
}

	
