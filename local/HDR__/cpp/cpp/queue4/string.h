#ifndef STRING_H
#define STRING_H

class String {
friend std::ostream& operator<<(std::ostream& out, const String& rhs);
private:
	char *str;
	int len;
	
public:
	// String& operator=(const String& rhs) { /* memberwise copy */ return *this; }
	// String *operator&() { return this; }
	// const String *operator&() const { return this; }
	
	String();
	String(const char *s);
	String(const String& rhs);
	~String();
	
	String& operator=(const String& rhs);
	//String& operator=(const char *s);
	// +-, *=
	
	bool operator==(const String& rhs);
	// !=, >, <, >=, <=
	
	const String operator+(const String& rhs);
	// *

	
	const char *c_str();
	int size();
	
	// 
};

#endif
