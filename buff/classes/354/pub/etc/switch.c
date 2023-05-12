// gcc -c switch.c

void f1() {
  int i=0;
  switch (i) {
    case 0: break;
    case 1: break;
    // case i: break;
  }
}

void f2() {
  int i=0;
  switch (i) {
    case 1: break;
    case 0: break;
  }
}

void f3() {
  int i=0;
  switch (i) {
    case 0: break;
    // case 0: break;
  }
}

void f4() {
  switch (0) {
    default: break;
  }
}

void f5() {
  switch (0) {
    default: ;
  }
}

void f6() {
  switch (0) {
    default:
  }
}

void f7() {
  switch (0) {
    default: ;
    // default: ;
  }
}

void f8() {
  switch (0) {
    default: ;
    case 0: ;
  }
}

void f14() {
  switch (0) {}
}

void f15() {
  switch (0) default: break;
}

void f16() {
  switch (0) break;
}

void f17() {
  switch (0);
}
