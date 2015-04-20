program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
 var n,d,c,s,i,k,res:integer; a:array[0..100000] of integer;
 function sort(var a:array of integer; n:integer):integer;
 var i,j,t:integer;
 begin
 for i:=1 to n-1 do
 for j:=i to n do
 if a[i]<a[j] then
 begin
 t:=a[i];
 a[i]:=a[j];
 a[j]:=t;
 end;
  end;
begin
assign(input,'sochi.in');
reset(input);
assign(output,'sochi.out');
rewrite(output);
s:=0;
read(n,d);
for i:=1 to n do
begin
read(c);
if c>d then
begin
k:=k+1;
a[k]:=c-d;
end;
end;
sort(a,k);
s:=0;
res:=2;
for i:=1 to k do
begin
if (a[i]>=d)and(res<>0) then
begin
s:=s+a[i];
res:=res-1;
end else if res=0 then
s:=s+a[i]-d;
end;
writeln(s);


end.
 