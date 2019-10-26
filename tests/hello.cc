// All systemc modules should include systemc.h header file
#include "systemc.h"
// Hello_world is module name
template <class T>
class hello_world:public sc_module {
  

	T base;
	public:
  SC_CTOR (hello_world) {
	  base = 0;
    // Nothing in constructor 
  }
  void say_hello() {
    //Print "Hello World" to the console.
    cout << "Hello World.\n";
  }

  T givmesum ( T a, T b) {
	 return a+(b*base) 	;
	 }	
};

// sc_main in top level function like in C++ main
int sc_main(int argc, char* argv[]) {
  hello_world<int> hello("HELLO");
  // Print the hello world
  hello.say_hello();
  printf("Result of 2 + 2 is %x",(hello.givmesum (2,2)));
  return(0);
}
