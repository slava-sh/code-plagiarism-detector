{$r-,q-,t-,s-,i-,o+}
{$m 50000000}
uses math;
var
  a,b : int64;
begin
  assign(input,'prizes.in'); reset(input);
  assign(output,'prizes.out'); rewrite(output);
  readln(a,b);
  writeln(trunc(min(a,b)/3));
  close(input);
  close(output);
end.