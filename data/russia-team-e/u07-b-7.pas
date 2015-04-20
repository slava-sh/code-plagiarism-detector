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
  for i:= 1 to n do
  begin
  k:=n;
  while (s[k]-s[i]>r)and(k>i) do
  begin
  dec(k);
  l:=l+1;
  end;
  end;
  writeln(w,l);
 close(a);
 close(w);
end.
