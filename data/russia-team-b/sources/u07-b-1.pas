var
 l,k,n,r,i,j:integer;
 s:array[1..400000]of integer;
 a,w:text;
begin
  assign(a,'che.in'); reset(a);
  assign(w,'che.out'); rewrite(w);
  readln(a,n,r);
  for i:= 1 to n do
  read(a,s[i]);
  for i:= 1 to n-1 do
  for j:= i to n do
    if s[i]>s[j] then
  begin
    k:=s[i];
    s[i]:=s[j];
    s[j]:=k;
  end;
  for i:= n downto 1 do
  begin
  k:=1;
  while s[i]-s[k]>r do
  begin
  inc(l);
  inc(k);
  end;
  end;
  writeln(w,l);
  close(a);
  close(w);
end.
