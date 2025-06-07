class Expr {
  test(): Int {
    {
        let x: Int <- 5, y: Int <- 10 in
        if x < y then
          x * (y - 2)
        else
          x / y
        fi;

      while x <= y loop
        x <- x + 1
      pool;

      case x of
        a: Int => a + 1;
        b: Int => b - 1;
      esac;
    }
  };
};