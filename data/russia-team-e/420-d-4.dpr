program d;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type mas=array [1..100005] of longint;
 var
 n,k,i,j, x:longint;
 s:int64;
 p :boolean;
 a,b:mas;

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

function findmin(a:mas):longint;
var i, min:longint;
begin
  min:=1;
  for i:=1 to n - 1 do
    if a[i]<a[min] then min:=i;
  findmin:=min;
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
        for i:=2 to n do
          b[i-1]:=abs(a[i]-a[i-1]);
        b[n]:=k-a[n];


        while b[n]>0 do
        begin
          inc(b[findmin(b)]);
          dec(b[n]);
          end;
           write(b[findmin(b)]);
      end;

end.
