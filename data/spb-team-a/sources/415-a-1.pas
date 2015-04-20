var
t,i: longint;
a: array[1..10000] of longint;
begin
  assign(input,'abcd.in');
  assign(output,'abcd.out');
  reset(input);
  rewrite(output);
  
  read(t);
  for i:=1 to t do begin
    read(a[i]);
  end;
  for i:=1 to t do begin
    if (sqr(a[i] div 100) + sqr(a[i] mod 100)) mod 7 = 1 then writeln('YES')
    else writeln('NO');
  end;
  
  close(input);
  close(output);
end.  