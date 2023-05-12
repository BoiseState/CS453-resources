// g++ -Wall -o Excep Excep.cc && ./Excep

#include <iostream>
#include <string>

using namespace std;

class ArgsException {
  string msg;
public:
  ArgsException(string msg) : msg(msg) {}
  friend ostream& operator<<(ostream& os, const ArgsException& e) {
    return os << e.msg;
  }
};

class Excep {
public:
  static void foo(int i) throw(ArgsException) {
    if (i<2)
      throw ArgsException("too few args");
    // much more code
    cout << "foo() done" << endl;
  }
};

int main(int argc, char* argv[]) {
  try {
    Excep::foo(argc);
    // much more code
    cout << "ok" << endl;
  } catch (ArgsException e) {
    cout << "not ok: " << e << endl;
  }
}
