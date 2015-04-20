var a,b:array[1..100000] of longint;
    n,i,j,sum,sum1:longint;

procedure qsort(l, r: longint);
var
  x, y, i, j: longint;
begin
  i := l; j := r; x := a[random(r - l + 1) + l];
  repeat
    while x > a[i] do inc(i);
    while x < a[j] do dec(j);
    if i <= j then
    y := a[i]; a[i] := a[j]; a[j] := y; inc(i); dec(j);
  until i >= j;
  if l < j then qsort(l, j);
  if i < r then qsort(i, r);
end;
begin
assign(input, 'merlin.in');
assign(output, 'merlin.out');
reset(input);
rewrite(output);
 read(n);
 for i:=1 to n do read(a[i]);
 qsort(1,n);
 sum:=0;
 for i:=2 to n do begin
                   b[i]:=a[i]-a[1];
                   sum:=sum+b[i];
                  end;
 i:=n+1;
 sum1:=0;
 while sum1<sum do begin
                    dec(i);
                    sum1:=a[i]+sum1;
                    sum:=sum-b[i];
                   end;
 write(n-i+1);

 close(input);
 close(output);
end.

