var
n,i,j,s: longint;
a: array[1..1000] of longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do begin
    read(a[i]);
  end;
  for i:=1 to n do begin
    j:=i;
    if j<=a[i] then inc(s);
  end;
  writeln(s);
  for i:=1 to s do begin
    writeln(i,' ',i);
  end;
  close(input);
  close(output);
end.  
