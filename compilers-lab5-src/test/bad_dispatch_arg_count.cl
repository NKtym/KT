class B {
  foo(x:Int): Int { x };
};
class A {
  f(): Int { (new B).foo(1, 2) };
};
class Main { main(): Int { 0 }; };