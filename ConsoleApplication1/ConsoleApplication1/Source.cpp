#include <iostream>  /* a preprocessor directive */
#include <string>    /* string library, which appears to be optional to declare */
#include <sstream>   /* library to convert strings to other data types */
#define SHORT_PI 3.14  /* replaces 'SHORT_PI' with '3.14', except in string literals.  pre-processor directive*/
using namespace std; /* allows cout and cin functions to be called 'unqualified' */

int basic_statements()
{
	// I'm a comment
	auto x1 = R"(Hello )"; // 'auto' deduces the type for variable declaration; 
	                       // R"(...)" is a raw string which may include backslash and double quotes and single quotes 
    decltype(x1) x2; x2 =  "world";  // decltype uses the type of a variable to declare another
	char x3 = '!';            // strings use double quotes.  single character uses single quote.
	string x4 = "abcd";
	const char newline = '\n';  // declaring a constant
	cout << x1 << x2 << x3 << newline; // \n can be in a string to cause a newline.

	/* another 
	   comment */
	int a, b, sum;
	
	std::cout << 
		"1st integer: "; // semi-colons end a statement, not new line chars
	std::cin >> a;
	std::cout << 
		"2nd integer: ";
	std::cin >> b;

	sum = a + b;
	std::cout << "sum: " << sum << std::endl;

	cout << "enter two words: ";
	string word1, word2; 
	cin >> word1 >> word2; // get two values.  white-space is the delimiter and is discarded  
	cout << "word 1: " << word1 << endl;
	cout << "word 2: " << word2 << endl;
	
	cout << "enter a line: ";
	string line1, dummy;
	getline(cin, dummy);  // consume 'whitespace' at end of previous cin.  normally 'cin >>' and getline should be mixed.
	getline(cin, line1);
	cout << "line1: " << line1 << endl;

	// ways to intialize a variable when declared
	int w = 0;   int w2 = 75;  int w3 = 75u; // unsigned integer.
	int y(0);    int y2 = 0113; // octal constant, begins with '0'
	int z{ 0 };  int z2 = 0x4b; // hexidecimal constant, begins with '0x' 
	bool myBool = true;

	float f1 = 3.14f; double f2 = 3.14e2; long double f3 = 3.0;
	cout << 3.14159f << endl; // float constant
	cout << 3.14159  << endl; // double constant
	cout << 3.14159l << endl; // long double constant
	cout << "SHORT_PI " << SHORT_PI << endl;
	
	int v1, v2; v2 = 1;
	v1 = 3; v2 = v1++; cout << "++ suffix " << v1 << ", " << v2 << endl;  // increment, return value before increment
	v1 = 3; v2 = ++v1; cout << "++ prefix " << v1 << ", " << v2 << endl;  // increment, return incremented value
	cout << "true is " << true << ", false is " << false << endl;
	int bb(0); cout << ((bb = 2) == 2) << ' ' << bb << endl; // assignment allowed in expressions

	// type casting - recast type 
	float p = (float) SHORT_PI;  // decimal literals are double by default, except where f or l suffix
	int p1 = (int)p;
	int p2 = int(p);
	cout << p << " " << p1 << " " << p2 << endl;


	string input_string;
	int an_integer;
	float a_float;
	cout << "enter string with a decimal number: ";
	cin >> input_string;
	stringstream(input_string) >> an_integer;
	stringstream(input_string) >> a_float;
	cout << "'" << input_string << "' as an integer: " << an_integer << "; as a float: " << a_float << endl;

	return 0; // optional for main()
}

int flow_control()
{
	/* IF THEN ELSE statement */
	int i;
	cout << "enter a signed integer: ";
	cin >> i;
	if (i > 0) cout << "value is positive";
	else if (i < 0)
	{
		cout << "value is negative";
	}
	else
		cout << "value is zero";
	cout << "." << endl;

	/* WHILE loop. condition before statements */
	int n = 10;
	cout << "\ncountdown using while-loop: ";
	while (n>0) {
		cout << n << ", ";
		--n;
	}
	cout << "liftoff!\n";

	/* DO-WHILE loop.  statement is executed at least once*/
	string str;
	getline(cin, str); // consume whitespace from last "cin >>"
	cout << "\ndo-while loop.  repeat input.\n";
	do {
		cout << "Enter text ('x' to exit): ";
		getline(cin, str);
		cout << "You entered: " << str << '\n';
	} while (str != "x");

	/* FOR loop. for (initialization, condition, increment) */
	cout << "\ncountdown using for-loop: ";
	for (int n = 10; n>0; --n) {
		cout << n << ", ";
	}
	cout << "liftoff!\n";

	cout << "\nfor-loop with multiple indexes\n";
	for (int i=0, j=10; 
		 i != j; 
		 ++i, --j) // prefix or suffix for incrementor/decrementor doesn't matter, apparently.
	  cout << "i is " << i << ", j is " << j << endl;

	/* range-based loop.  for ( declaration: range ) */
	cout << "\nrange-based loop\n";
	string a_str("Hello");
	for (char a_char : a_str) { cout << "-" << a_char; }
	cout << endl;

	/* break from block in loop */
	cout << "\nabort countdown at 3: ";
	for (int n = 10; n>0; n--)
	{
		cout << n << ", ";
		if (n == 3)
		{
			cout << "countdown aborted!";
			break;
		}
	}

	/* 'continue' statments skips to end of block*/
	cout << "\nskip count at 5: ";
	for (int n = 10; n>0; n--) {
		if (n == 5) continue; // skip remainder of block and loop to next iteration.
		cout << n << ", ";
	}
	cout << "liftoff!\n";

	/* goto statement */
	cout << "\ncountdown using goto statment: ";
	int idx = 10;
    mylabel:
	cout << idx << ", ";
	idx--;
	if (idx>0) goto mylabel;
	cout << "liftoff!\n";

	/* switch statement */
	int num;
	cout << "enter a number 1-3: ";
	cin >> num;
	switch (num) {
	case 1:
		cout << "One";
		break;
	case 2:
		cout << "Two";
		break;
	case 3:
		cout << "Three";
		break;
	default:
		cout << "not 1, 2, or 3";
	}
	cout << endl;

	return 0;
}

void triple(int& val) // int& indicates parameter is a pointer/reference
{
	val *= 3;
}

// 'inline' suggests to compiler that function code could be inserted where it is called, 
//    rather than normal function call with stacked arguements and jump. 
                     // 'const' makes values read-only to protect variables but have efficency of passing pointers.
inline string concatenate(const string& str1, const string& str2) { 
	return str1 + str2;
}

// minimal definition before function is called so that full definition can appear later in file.
                   // default value for parameter
int divide(int a, int b=2);
double divide(double a, double b);
long factorial(long f);

// template function
template <class T>
T add (T a, T b)
{
	return a + b; 
}

// template function with argument (int N).  compiler will creates separate functions for each T, N combo called.
//   since functions are created at compile time N must be an expression, not a variable.
template <class T, int N>
T fixed_multiply(T val) { return val * N; }

void functions(void)
{
	int v;
	cout << "enter an integer: ";
	cin >> v;
	triple(v);
	cout << "tripled is " << v << endl;

	string s1, s2;
	cout << "\nenter a string: ";
	cin >> s1;
	cout << "enter another string: ";
	cin >> s2;
	cout << "concatenated: " << concatenate(s1, s2) << endl;

	cout << "6 divided by 2 is " << divide(6) << endl;
	cout << "20 divided by 5 is " << divide(20, 5) << endl;
	cout << "21.0 divided by 5.0 is " << divide(21.0, 5.0) << endl;

	cout << "recursion: 5! is " << factorial(5) << endl;

	cout << "template function A: add integers: 2 + 3 = " << add<int>(2, 3) << endl; // specifying the return type
	cout << "template function A: add floats: 2.1 + 3.1 = " << add(2.1f, 3.1f) << endl; // return type may be omitted if same as parameters

	cout << "template function B: integer 2 * 3 = " << fixed_multiply<int, 1 + 1>(3) << endl;
	cout << "template function B: integer 3 * 4.0 = " << fixed_multiply<float, 3>(4.0) << endl;
}

int divide(int a, int b) {
	return a / b;
}

// overloaded function.  same function name but differ set of parameters
double divide(double a, double b) {
	return a / b;
}

long factorial(long a)
{
	if (a > 1) return a * factorial(a - 1);
	else return 1;
}

namespace toontown
{
	const string premier_attraction = "Roger Rabbit Spin";
	int location() { return 1130;  }
}

namespace adventureland
{
	const string premier_attraction = "Jungle Cruise";
	int location() { return 900; }
}

namespace neworleanssquare
{
	const string premier_attraction = "Pirates of the Caribean";
	int location() { return 945; }
}

/* variable scopes and namespaces */
void name_visibility() {

	cout << "\nregarding variable scope and blocks...var1 is 10, var2 is 20" << endl;
	int var1 = 10;
	int var2 = 20;
	{
		int var1;   // ok, inner scope.
		var1 = 50;  // sets value to inner x
		var2 = 50;  // sets value to (outer) y
		cout << "inner block declares a new var1, sets var1 & var2:\n";
		cout << "var1: " << var1 << '\n';
		cout << "var2: " << var2 << '\n';
	}
	cout << "outer block - var1 is unchanged, var2 is changed:\n";
	cout << "var1: " << var1 << '\n';
	cout << "var2: " << var2 << '\n';

	cout << "\nnamespace";
	// fully qualifyed names defined in namespace
	cout << "\nAdventureland is at approx " << adventureland::location() << ", premier attraction is " << adventureland::premier_attraction;
	cout << "\nToontown is at approx " <<      toontown::location() <<      ", premier attraction is " << toontown::premier_attraction;
	// 'using' a namespace allows names to be unqualified.
	{
		using namespace toontown;   // applies only to the block
		cout << "\nToontown is at approx " << location() << ", premier attraction is " << premier_attraction;
	}
	// 'using' can be applied to selected names in a namespace
	{
		using toontown::location;
		using adventureland::premier_attraction;
		cout << "\nToontown location is at approx " << location();
		cout << "\nAdventureland premier attraction is " << premier_attraction;
	}
	// aliasing a namespace
	{
		namespace nos = neworleanssquare;
		cout << "\nNew Orleans Square is at approx " << nos::location() << ", premier attraction is " << nos::premier_attraction;
	}
	cout << '\n';
}

int arrays()
{
	/* methods to declare an array
	string lands[5];
	string lands[5] = {};
	string lands[5] = { "Main Street", "Tomorrowland" };  length of 5, initializing 2 elements
	*/
	cout << "Lands at Disneyland\n";
	string lands[] { "Main Street", "Tomorrowland", "Adventureland" }; // initialize an array
	for (string land : lands) 
		cout << land << '\n';

	int myarray[3] = { 10,20,30 };
	for (int i = 0; i<3; ++i)
		++myarray[i];
	/* the following does not increment array elements
	for (int elem : myarray)
		++elem;
	*/
	cout << "\nusing for-loop to access array elements" << endl;
	for (int elem : myarray)
		cout << elem << '\n';
	cout << endl;

	/* using char arrays and strings together */
	char myword1[] = { 'H', 'e', 'l', 'l', 'o', '\0' };  // explicit null terminator
	char myword2[] = "Hello";                            // null terminated implied by literal
	cout << myword1 << endl;  // supported by char array, not supported by arrays of other types
	cout << myword2 << endl;

	char myntcs[] = "some text";
	string mystring = myntcs;  // convert c-string to string
	cout << mystring << endl;          // printed as a library string
	cout << mystring.c_str() << endl;  // printed as a c-string 
	
	return 0;
}

void print_range(const int* start, const int* stop);
void increment_range(int* start, int* stop);

void pointers()
{
	int my_int;
	char my_char;

	cout << "assign values thru pointers" << endl;
	int * ptr_to_int;  // pointer to an integer (or will be handled as an integer)
	char * ptr_to_char;   // pointer to a char

	ptr_to_int = &my_int;  // & is memory address. assign memory location to pointer
	*ptr_to_int = 10;      // * means dereference, i.e. contents of address
	ptr_to_char = &my_char;
	*ptr_to_char = 'Z';

	cout << "my integer is " << my_int << endl;
	cout << "ptr_to_int is " << ptr_to_int << endl;
	cout << "my char is " << my_char << endl;
	cout << "ptr_to_char is " << ptr_to_char << endl;

	cout << "pointers and arrays" << endl;
	{
		cout << "indexing an array of integers\n";
		int numbers[5];
		int * ptr;
		ptr = numbers;  *ptr = 10;        // referencing array without index is same as rpointer to first element
		ptr++;  *ptr = 20;                // increment pointer to another element of array.  
		ptr = &numbers[2];  *ptr = 30;    // reference using array subscript
		ptr = numbers + 3;  *ptr = 40;    // reference using array name + increment
		ptr = numbers;  *(ptr + 4) = 50;  // reference using pointer + increment 
		for (int n = 0; n < 5; n++)
			cout << numbers[n] << ", ";
		cout << endl;
	}

	{
		cout << "indexing an array of floats\n";
		float numbers[5];
		float * ptr = numbers;  // pointer initialization may include an assignment
		       *ptr = 10.1f;
		ptr++;  *ptr = 20.2f;       
		ptr = &numbers[2];  *ptr = 30.3f;
		ptr = numbers + 3;  *ptr = 40.4f;  // pointer arithmetic allows + and - operations
		ptr = numbers;  *(ptr + 4) = 50.5f;
		for (float elem : numbers)
			cout << elem << ", ";
		cout << endl;

		/* combining deferencing and incrementing
		   *p++    // same as *(p++): increment pointer, and dereference unincremented address
           *++p    // same as *(++p): increment pointer, and dereference incremented address
           ++*p    // same as ++(*p): dereference pointer, and increment the value it points to
           (*p)++  // dereference pointer, and post-increment the value it points to 
       */
	}

	{
		cout << "example of pointers protecting values\n";
		int numbers[] = { 10,20,30 };
		increment_range(numbers, numbers + 2);  // passing pointers
		print_range(numbers, numbers + 2);
	}

	/* 'const' can set whether value and/or pointer is read-only */
	{
		int x;
		      int *       p1 = &x;  // non-const pointer to non-const int
		const int *       p2 = &x;  // non-const pointer to const int
		      int * const p3 = &x;  // const pointer to non-const int
		const int * const p4 = &x;  // const pointer to const int 
	}

	{
		cout << '\n' << R"(pointing within a string "hello")" << endl;
		const char * foo = "hello";
		cout << "5th char via pointer increment *(foo + 4): " << *(foo + 4) << endl;
		cout << "5th char via subscript foo[4]: " << foo[4] << endl;
	}

	{
		cout << "pointer to a pointer\n";
		char a;
		char * b;
		char ** c;
		a = 'z';
		b = &a;
		c = &b;
		cout << "a is "   << a   << endl;
		cout << "*b is "  << *b  << endl;
		cout << "**c is " << **c << endl;
		cout << "b is "   << b   << endl;
		cout << "*c is "  << *c  << endl;
	}

}

void increment_range(int* start, int* stop)
{
	int * current = start;
	while (current <= stop) {
		++(*current);  // increment value pointed
		++current;     // increment pointer
	}
}

void print_range(const int * start, int const * stop) // 'const <type> *'  makes value read-only.  same as '<type> const *'
{
	const int * current = start;
	while (current <= stop) {
		cout << *current << ", ";
		++current;     // increment pointer.  'const' protects value but pointer may be incremented
	}
	cout << endl;
}

struct attraction {
	string name;
	bool fastpass;
};

enum compass_point { N, NNE, NE, ENE, E, ESE, SE, SES, S, SSW, SW, SWW, W, WNW, NW };

struct theme_land {  // 'struct' is same as 'class' except struct default access is public
	string name;
	compass_point from_hub;
	attraction rides[3];
};

string compass_full_name(compass_point pt)
{
	/*
	if (pt == N) return "north";
	else if (pt == NE) return "northeast";
	else if (pt == E) return "east";
	else if (pt == SE) return "souteast";
	else if (pt == S) return "south";
	else if (pt == SSW) return "south-southwest";
	else if (pt == SW) return "southwest";
	else if (pt == W) return "west";
	else return to_string(pt);
	*/
	switch (pt) {
	case SSW:
		return "south-southwest";
	case E:
		return "east";
	default:
		return to_string(pt);
	}
}

void print_land(theme_land land)
{
	cout << land.name << " is " << compass_full_name(land.from_hub) << " of the hub." << endl;
	for (attraction ride : land.rides) {
		if (ride.name != "") {
			cout << " has " << ride.name;
			if (ride.fastpass) cout << " with fastpass";
			cout << '\n';
		}
	}
}

union person_name {
	char name[10];
	char initial;
};

void structures()
{
	theme_land adventureland;         // space allocated at compile time.
	theme_land * p_tomorrowland;
	p_tomorrowland = new theme_land;  // dynamically create an object.  space allocated at run time.

	adventureland.name = "Adventureland"; // '.' accesses member of a object
	adventureland.from_hub = SSW;
	adventureland.rides[0].name = "Tiki Room";
	adventureland.rides[0].fastpass = false;
	adventureland.rides[1].name = "Indiana Jones";
	adventureland.rides[1].fastpass = true;
	print_land(adventureland);

	p_tomorrowland->name = "Tomorrowland"; // "->" accesses member if variable is a pointer to an object
	p_tomorrowland->from_hub = E;
	print_land(*p_tomorrowland);

	person_name my_name = { "Toad" };
	cout << "Union structure: name is " << my_name.name << " with initial " << my_name.initial << endl;
}

class Rectangle {
  private:              // cannot access outside of class
	int width, height;  // no label also implies private
  public:
	  Rectangle(int, int); // placeholder for constructor
	  Rectangle(int);      // overloaded constructor
	  int area() { return width * height; }
};

Rectangle::Rectangle(int w, int h) { width = w; height = h; } // constructor definition
Rectangle::Rectangle(int s) : width(s), height(s) { }  // alternate syntax for initializing values

class Circle {
	double radius;  // private acces by default
public:
	Circle(double r) { radius = r; }
	double area() { return radius*radius*3.14159; }
};

class Cylindar {
	Circle base;
	double height;
  public:
	  Cylindar(double r, double h) : base(r), height(h) {}
	  double volume() { return base.area() * height; }
};

void classes()
{
	Rectangle rect1(3, 4);  // alternate syntaxes: rect1{3,4}, rect1 = (3,4), rect1 = {3,4} 
	cout << "rect1 area is " << rect1.area() << endl;
	Rectangle square1 = 6;  // alternate syntax for initialization with one parameter
	cout << "square1 area is " << square1.area() << endl;
	Cylindar * p_cyl1, * p_cyl2, * cyls;
	p_cyl1 = new Cylindar(10, 20);  // new class instance returns a pointer
	cout << "cyl1 volume is " << p_cyl1->volume() << " (should be approx 6283)" << endl;

	Cylindar cyl2(3, 4);
	p_cyl2 = &cyl2;
	cout << "cyl2 volume is " << cyl2.volume()      << " (should be approx 113)" << endl;
	cout << "cyl2 volume is " << p_cyl2->volume()   << " (should be approx 113)" << endl;
	cout << "cyl2 volume is " << (*p_cyl2).volume() << " (should be approx 113)" << endl;
	
	cyls = new Cylindar[2]{ {2,5}, {3,6} };
	cout << "cyls[0] volume is " << cyls[0].volume() << " (should be approx 62)" << endl; // note use of '.' for member
	cout << "cyls[1] volume is " << cyls[1].volume() << " (should be approx 169)" << endl;
}

int main()
{
	classes();
	//structures();
	//pointers();
	//arrays();
	//name_visibility();
	//functions();
	//flow_control();
	//basic_statements();
}