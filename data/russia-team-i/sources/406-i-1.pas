var
  pairs,mm,ko,n,i,segisize,sum,l,r,d,q1,q2,g : longint;
  a,f : array [0..20000] of longint;
  mar : array [0..20000] of boolean;
  procedure sort(l,r : longint);
  var i,j,x,f : longint;
  begin
    i:=l; j:=r; x:=a[random(r-l+1)+l];
    repeat
      while a[i]<x do inc(i);
      while a[j]>x do dec(j);
      if i<=j then
      begin
        f:=a[i]; a[i]:=a[j]; a[j]:=f;
        inc(i); dec(j);
      end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
  end;
begin
  assign(input,'sochi.in'); reset(input);
  assign(output,'sochi.out'); rewrite(output);
  l:=0; r:=0; g:=0;
  readln(n,d);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  for i:=1 to n do
    if a[i]>=2*d then
    begin
      inc(g);
      f[g]:=a[i];
      mar[i]:=true;
    end;
  mm:=0;
  q1:=0; q2:=0;
  for i:=1 to n do
    if (not mar[i]) and (a[i]>=d) then
      mm:=i else break;
  if (mm>=2) then begin q1:=a[mm]; q2:=a[mm-1]; ko:=2; end else
  if (mm>=1) then begin q1:=a[mm]; ko:=1; end else ko:=0;
  pairs:=g-1+ko;
  for i:=1 to g do sum:=sum+f[i];
  sum:=sum+q1+q2;
  sum:=sum-((2*d)*pairs);
  writeln(sum);
  close(input);
  close(output);
end.