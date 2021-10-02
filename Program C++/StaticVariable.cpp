#include <iostream>
using namespace std;

// Static duration
void doSomeThing_static()
{
	// static duration via static keyword.  This line is only executed once.
	static int s_value(0);
	++s_value;
	cout << s_value << endl;
} // s_value is not destroyed here, but becomes inaccessible

int main()
{
	// Static variables
	doSomeThing_static();
	doSomeThing_static();
	doSomeThing_static();

	return 0;
}