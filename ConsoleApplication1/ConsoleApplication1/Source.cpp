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

// template function with argument.  compiler will creates separate functions for each T, N combo called.
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

	cout << "6 divided by 2 is " <<  divide(6) << endl;
	cout << "20 divided by 5 is " << divide(20, 5) << endl;
	cout << "21.0 divided by 5.0 is " << divide(21.0, 5.0) << endl;

	cout << "recursion: 5! is " << factorial(5) << endl;

	cout << "template function A: add integers: 2 + 3 = " << add<int>(2, 3) << endl; // specifying the return type
	cout << "template function A: add floats: 2.1 + 3.1 = " << add(2.1f, 3.1f) << endl; // return type may be omitted if same as parameters

	cout << "template function B: integer 2 * 3 = "   << fixed_multiply<int, 1+1>(3) << endl;
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

int main()
{
	functions();
	//flow_control();
	//basic_statements();
}