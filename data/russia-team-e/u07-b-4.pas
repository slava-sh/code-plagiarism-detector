var
 l,k,n,r,i,j:integer;
 s:array[1..400000]of integer;
 a,w:text;
procedure QuickSort( L, R : Integer ); { Áûñòðàÿ ñîðòèðîâêà ìàññèâà A[] }
var i,j,x,y : integer;
begin
  i := l; j := r;
  x := s[(l+r) div 2];
  repeat
    while (s[i] < x) do inc(i);
    while (x < s[j]) do dec(j);
    if ( i <= j ) then
    begin
      y:=s[i]; s[i]:=s[j]; s[j]:=y;
      inc(i); dec(j);
    end;
  until (i > j);
  if (l < j) then QuickSort(l,j);
  if (i < r) then QuickSort(i,r);
end;
begin
  assign(a,'che.in'); reset(a);
  assign(w,'che.out'); rewrite(w);
  readln(a,n,r);
  for i:= 1 to n do
  read(a,s[i]);
  quicksort(1,n);
  for i:= n downto 1 do
  begin
  k:=1;
  while (s[i]-s[k]>r)and(k<i) do
  begin
  inc(l);
  inc(k);
  end;
  end;
  writeln(w,l);
end.
