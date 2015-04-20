program d;

{$APPTYPE CONSOLE}

uses
  SysUtils;

 var
 n,k,i,result,min:longint;
 s:int64;
 a:array [1..10005] of longint;

begin
  reset(input,'fence.in');
  rewrite(output,'fence.out');
   read(n,k);
   for i := 1 to n do
   begin
    read(a[i]);
    s:=s+a[i];
    end;
   min:=a[1];
   for i := 2 to n do
    if a[i]<=min then min:=a[i];
    if s<k then write(min)
    else
    begin
    result:=trunc((k-min)/(n-1));
    write(result);
    end;
end.
 