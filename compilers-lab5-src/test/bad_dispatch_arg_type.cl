class B {
  foo(x:Int): Int { x };
};
class A {
  f(): Int { (new B).foo("nope") };  -- строка вместо Int
};
class Main { main(): Int { 0 }; };