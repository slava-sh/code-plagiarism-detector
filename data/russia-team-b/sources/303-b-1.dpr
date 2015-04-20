Var n,d,i:longint;
m:array [1..1000000] of longint;
r,rez:int64;
begin
  Assign(input,'che.in'); reset(input);
  Assign(output,'che.out'); rewrite(output);
  read(n,d);
  for i:=1 to n do
  read(m[i]);
  r:=1;
  rez:=0;
  for i:=1 to n do
  begin
    while (r<=n)and(m[r]-m[i]<=d) do
    inc(r);
    if m[r]-m[i]>d
    then rez:=rez+n-r+1;
  end;
  writeln(rez);
end.
 