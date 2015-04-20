var sum,n,k:int64;
    i,j:integer;
    s:array[1..100000]of integer;
    r,w:text;
begin
  assign(r,'sochi.in'); reset(r);
  assign(w,'sochi.out'); rewrite(w);
  readln(r,n,k);
  for i:= 1 to n do
  read(r,s[i]);
  for i:= 1 to n-1 do
  for j:= i to n do
  if s[i]>s[j] then
  begin
    sum:=s[i];
    s[i]:=s[j];
    s[j]:=sum;
  end;
  sum:=(s[1]+s[2])-2*k;
  if n>2 then
  for i:= 3 to n do
  begin
  sum:=(sum+s[i])-2*k;
  end;
  writeln(w,sum);
  close(r);
  close(w);
end.

