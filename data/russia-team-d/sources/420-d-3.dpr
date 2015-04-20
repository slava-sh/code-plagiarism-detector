program d;

{$APPTYPE CONSOLE}

uses
  SysUtils;

 var
 n,k,i,j, x:longint;
 s:int64;
 p :boolean;
 a:array [1..100005] of longint;

procedure swap(var a, b :longint);
var
x :longint;
begin
 x := a;
 a := b;
 b := x;
end;

procedure qs(l, r :longint);
var
    x :longint;
begin
    x := a[(l + r) div 2];
    i := l; j := r;
    while (i <= j) do
    begin
      while a[i]<x do inc(i);
      while a[j]>x do dec(j);
      if (i<=j) then begin
                     swap(a[i],a[j]);
                     inc(i);
                     dec(j);
                     end;
    end;
    if i<r then qs(i,r);
    if j>l then qs(l,j);
end;

begin
  reset(input,'fence.in');
  rewrite(output,'fence.out');
  read(n, k);
  for i := 1 to n do
      begin
          read(a[i]);
          s := s + a[i];
      end;
  qs(1, n);
  if (s < k) or (n = 1) then
      write(a[1])
  else
      begin
        x := k div 4;
        while x > 1 do
            begin
                p :=true;
                for i := 2 to n - 1 do
                    if not(a[i] - a[i - 1] >= x) then
                    p := false;
                if not(a[n] - a[n - 1] + a[1] - x >= x)  then
                    p :=false;
                    if p then
                    begin
                     write(x);
                     halt;
                     end
                    else
                        dec(x);
            end;
      end;
end.
