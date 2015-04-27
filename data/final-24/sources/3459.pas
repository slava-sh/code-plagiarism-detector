var
 l,nd,z,i,j,n,m,k,t,x,mn:longint;
 f1,f2,f3:byte;
 p:array[0..111111]of longint;
 c:array[0..111111]of char;
 s,s1:ansistring;

function nod(x,y:longint):longint;
begin
 while(x>0)and(y>0)do if x>y then x:=x mod y else y:=y mod x;
 nod:=x+y;
end;

begin
 readln(m);
 readln(s);
 n:=length(s);
 if m>=n then
 begin
  writeln(1);
  writeln(s);
  halt;
 end;
 for i:=1 to n do
 begin
  if s[i]='a' then f1:=1;
  if s[i]='b' then f2:=1;
  if s[i]='c' then f3:=1;
 end;
 mn:=f1+f2+f3;
 for i:=2 to n do
 begin
  while(j>0)and(s[i]<>s[j+1])do j:=p[j];
  if s[i]=s[j+1] then inc(j);
  p[i]:=j;
 end;
 k:=n-p[n];
 if(n mod k=0)and(k<=m)then
 begin
  writeln(1);
  writeln(copy(s,1,k));
 end else
 begin
  for i:=1 to m do
  begin
   j:=1;k:=0;l:=1;nd:=0;
   s1:=copy(s,1,i);
   while j<=n do
   begin
    if j>n-i+1 then
    begin
     inc(k);c[k]:=s[j];inc(j);continue;
    end else
    if copy(s,j,i)<>s1 then
    begin
     inc(k);c[k]:=s[j];inc(j);continue;
    end else
    begin
     if j-l>0 then
     begin
      if nd=0 then nd:=j-l else nd:=nod(nd,j-l);
     end;
     inc(j,i);
     l:=j;
    end;
   end;
   if l<n+1 then
   begin
    if nd=0 then nd:=n-l+1 else nd:=nod(nd,n-l+1);
   end;
   for j:=1 to k do p[j]:=0;
   j:=0;
   for z:=2 to k do
   begin
    while(j>0)and(c[z]<>c[j+1])do j:=p[j];
    if c[z]=c[j+1] then inc(j);
    p[z]:=j;
   end;
   t:=k-p[k];
   if(k mod t=0)and(t<=m)and(mn=3)and(nd mod t=0)then
   begin
    writeln(2);
    writeln(s1);
    for j:=1 to t do write(c[j]);
    writeln;
    halt;
   end;
  end;
  writeln(mn);
  if f1=1 then writeln('a');
  if f2=1 then writeln('b');
  if f3=1 then writeln('c');
 end;
end.
