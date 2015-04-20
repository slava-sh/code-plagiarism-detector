uses math;
var A,B,M : int64;
begin
  assign(input,'prizes.in'); reset(input);
  assign(output,'prizes.out'); rewrite(output);
  readln(A,B);
  M:=min(A,B)+1;
  writeln(trunc(M/4));
  close(input);
  close(output);
end.