program graph;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var d:array[0..12,0..500000] of longint;
a,b,c,w:array[1..1600000] of longint;
r,f:array[1..500000] of longint;
i,j,k,n,m,y,l,s:longint;
procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;
  j:=r;
  x:=a[random(r-l)+l];
  while i<=j do
    if a[i]<x then inc(i) else
    if a[j]>x then dec(j) else
     begin
       y:=a[i];
       a[i]:=a[j];
       a[j]:=y;
       y:=b[i];
       b[i]:=b[j];
       b[j]:=y;
       y:=w[i];
       w[i]:=w[j];
       w[j]:=y;
       inc(i);
       dec(j);
     end;
  if i<r then qsort(i,r);
  if j>l then qsort(l,j);
end;
begin
  assign(input,'graph.in');
  assign(output,'graph.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  j:=1;
  for i:=1 to m do
    begin
     readln(a[j],b[j],w[j]);
     if w[j]<>0 then w[j]:=12 div w[j];
     inc(j);
     b[j]:=a[j-1];
     a[j]:=b[j-1];
     w[j]:=w[j-1];
     inc(j);
    end;
  qsort(1,m*2);
  for i:=1 to m*2 do
    if (i=1) or (a[i]<>a[i-1]) then c[a[i]]:=i;
  d[0,1]:=1;
  d[0,0]:=1;
  k:=1;
  for i:=1 to n do
   r[i]:=maxlongint div 2;
  r[1]:=0;
  i:=0;
   while k>0 do
    begin
    y:=d[i,0];
    for j:=y downto 1 do
      begin
        l:=c[d[i,j]]-1;
        if (c[d[i,j]]<>0) and (f[d[i,j]]=0) then
          repeat
            l:=l+1;
            if r[b[l]]>r[a[l]]+w[l] then
             begin
              k:=k+1;
              r[b[l]]:=r[a[l]]+w[l];
              s:=r[b[l]] mod 13;
              d[s,0]:=d[s,0]+1;
              d[s,d[s,0]]:=b[l];
             end;
          until (a[l]<>a[l+1]) or (l>=m*2);
        k:=k-1;
        f[d[i,j]]:=1;
        d[i,0]:=d[i,0]-1;
      end;
      i:=(i+1) mod 13;
    end;
   for i:=2 to n do
     writeln(r[i]/12);
   close(input);
   close(output);
end.
