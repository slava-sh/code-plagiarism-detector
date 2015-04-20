{$r-,q-,t-,s-,i-,o+}
{$m 50000000}
uses math;
var
  a,b : int64;
begin
  assign(input,'prizes.in'); reset(input);
  assign(output,'prizes.out'); rewrite(output);
  readln(a,b);
  if min(a,b)=1 then writeln(trunc(max(a,b)/3)) else writeln(trunc(min(a,b)/3));
  close(input);
  close(output);
end.