program qq;

var
  f, f1: text;
  a, b, c, i, t: int64;

begin
  assign(f, 'abcd.in');
  assign(f1, 'abcd.out');
  reset(f);
  rewrite(f1);
  readln(f, t);
  for i := 1 to t do 
  begin
    readln(f,a);
    b := a div 100;
    c := a mod 100;
    if (c * c + b * b) mod 7 = 1 then writeln(f1, 'YES') else writeln(f1, 'NO');
  end;
  close(f);
  close(f1);
end.