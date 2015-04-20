var
  a : array [0..1000000] of int64;
  i,n : longint;
  l,r,mid,k : int64;
  procedure sort(l,r : longint);
  var
  i,j,c,x : longint;
   begin
    i:=l;
    j:=r;
    x:=a[random(r-l+1)+l];
    repeat
     while (a[i]<x) do inc(i);
     while (a[j]>x) do dec(j);
     if i<=j then
      begin
       c:=a[i];
       a[i]:=a[j];
       a[j]:=c;
       inc(i);
       dec(j);
      end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
   end;
  function f(x : longint) : boolean;
   var
   l :int64;
   begin
    l:=0;
    for i:=1 to n do
     begin
      if a[i]<x then begin f:=false; exit; end;
      if l+x>k then begin f:=false; exit; end;
      if l+x<a[i] then l:=a[i]
      else l:=l+x;
     end;
    f:=true;
   end;
begin
  assign(input,'fence.in'); reset(input);
  assign(output,'fence.out'); rewrite(output);
  randomize;
  readln(n,k);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  l:=0;
  r:=k div n;
  while (r-l>1) do
   begin
    mid:=(r+l) div 2;
    if f(mid) then l:=mid
    else r:=mid;
   end;
  if f(r) then writeln(r)
  else writeln(l);
  close(input);
  close(output);
end.