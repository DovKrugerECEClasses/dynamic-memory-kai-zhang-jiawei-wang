class String {
private:
	uint32_t capacity;
	uint32_t len;
	char* s;
	uint32_t stringlen(const char* str) {
		uint32_t count = 0;
		while (*str++ != '\0')
			count++;
		return count;
	}
public:
  String();
	String(const char str[]);
	
	String(const char str[], uint32_t mult);
	~String();

	//copy constructor
	String(const String& orig);
	String& operator =(const String& orig);
	char  operator [](const uint32_t pos)const;
	}
  char& operator [](uint32_t pos);
  friend ostream& operator<<(ostream& s, const String& str) {
	}
	
	String& operator +=(const String& orig);
	String operator +(String& orig) const;
	String substring(uint32_t pos, uint32_t length); // left right
  	String& replace(const char ori, const char rep);
	uint32_t length() const;
  	String& insert(uint32_t pos, const String& insert);
	
	
	
};
