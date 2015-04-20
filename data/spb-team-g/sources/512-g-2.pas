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
  for j:=n-1 downto 1 do begin
                     b[j]:=a[n]-a[j];
                     sum:=sum+b[j];
                   end;
 if sum<>0 then begin
 i:=n+1;
 sum1:=0;
 while (sum1<sum) and (i>0) do begin
                    dec(i);
                    sum1:=a[i]+sum1;
                    sum:=0;
                     for j:=i-2 downto 1 do begin
                                      b[j]:=a[i-1]-a[j];
                                      sum:=sum+b[j];
                                     
                                     end;
                                     
                   end;
 write(n-i+1);
               end
           else write(0);
 close(input);
 close(output);  
end.

