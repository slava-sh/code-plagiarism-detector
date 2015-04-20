uses math;
var A,B,M : int64;
begin
  assign(input,'prizes.in'); reset(input);
  assign(output,'prizes.out'); rewrite(output);
  readln(A,B);
  if min(A,B)=1 then begin writeln(trunc((max(A,B)+1)/4)); halt; end;
  M:=min(A,B)+1;
  writeln(trunc(M/4));
  close(input);
  close(output);
end.