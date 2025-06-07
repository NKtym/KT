class Main {
  main(): Int {
    let a : Int <- 1 + 2 in
    let s : String <- "foo".concat("bar") in
    {
      s;
      a + 3;
    }
  };
};