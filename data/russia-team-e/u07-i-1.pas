var sum,n,k,i:integer;
    s:array[1..100000]of integer;
    r,w:text;
begin
  assign(r,'sochi.in'); reset(r);
  assign(w,'sochi.out'); rewrite(w);
  readln(r,n,k);
  for i:= 1 to n do
  read(r,s[i]);
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

