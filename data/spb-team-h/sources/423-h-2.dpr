program Names;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
a,b,c:array[1..1000] of string;
i,j,n:longint;
m,g,e,k:string;

begin
  assign(input,'names.in');
  assign(output,'names.out');
  reset(input);
  rewrite(output);
  for i:=1 to n do
  for j:=1 to n do
  if (a[i]=a[j]) or (a[i]=b[j]) or (b[i]=b[j]) or (b[i]=a[j]) then
  begin
  readln (n);
  k:=a[i];
  a[i]:=c[i];
  c[i]:=b[i];
  b[i]:=k;
  end;
  for i:=1 to n do
  for j:=1 to n do
  if(a[i]>a[j]) then
  begin
  m:=a[i]; a[i]:=a[j]; a[j]:=m;
  g:=b[i]; b[i]:=b[j]; b[j]:=g;
  e:=c[i]; c[i]:=c[j]; c[j]:=e;
  end;
  for i:=1 to n do
  writeln (a[i], ' ', b[i], ' ', c[i]);
  close(input);
  close(output);
end.
