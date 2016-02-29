#include <iostream>
#include <string>
using namespace std;

class Integer {											//class declaration
public:
	Integer(int initialValue = 0);
	~Integer();
	Integer(const Integer &rhs);
	const Integer& operator=(const Integer &rhs);
	void operator<<(ostream & out);
	const Integer& operator+=(const Integer& rhs);
	int getValue() const;

private:
	int storedValue;
};

class Integer {											//class implementation
public:
	Integer(int initialValue = 0){						//constructor
		storedValue = initialValue;
	}

	~Integer() {}										//default destructor

	Integer(const Integer &rhs){						//copy constructor
		storedValue = rhs.getValue();
	}

	const Integer& operator=( const Integer &rhs) {		//copy assignment operator
		if (this != &rhs) {
			storedValue = rhs.getValue();
		}
	}

	void operator<<(ostream & out){						// << overload (best we can do with it as a member function)
		out << "value is: " << storedValue << endl; 
	}

	const Integer& operator+=(const Integer& rhs){		// += overload
		storedValue += rhs.getValue();
		return *this;
	}

	int getValue() const{								//const accessor
		return storedValue;
	}

private:
	int storedValue;
};
