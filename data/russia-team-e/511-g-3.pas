var
  n,m,x,y,ans : int64;
  function min(x,y : int64) : int64;
   begin
    if x<y then min:=x
    else min:=y;
   end;
begin
  assign(input,'prizes.in'); reset(input);
  assign(output,'prizes.out'); rewrite(output);
  readln(n,m);
  x:=min(n,m);
  if x=n then y:=m
  else y:=n;
  if x>2 then writeln(1)
  else
  if x=2 then writeln(0)
  else
  if x=1 then
  begin
    ans:=0;
    if y>=3 then begin ans:=1; y:=y-3; end;
    ans:=ans+(y div 4);
    writeln(ANS);
  end
  else
  writeln(0);
  close(input);
  close(output);
end.