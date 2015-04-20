var
  n,m,x,y : longint;
  function min(x,y : longint) : longint;
   begin
    if x<y then min:=x
    else min:=y;
   end;
begin
  assign(input,'prizes.in'); reset(input);
  assign(output,'prizes.out'); rewriute(output);
  readln(n,m);
  x:=min(n,m);
  if x=n then y:=m
  else y:=n;
  if x>2 then writeln(1)
  else
  if x=2 then writeln(0)
  else
  if x=1 then
  if y>=2 then writeln((y-2) div 4+1)
  else
  writeln(0);
  close(input);
  close(output);
end.