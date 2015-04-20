program qq;

var
  f,f1 : text;
  n, a, i, count: integer;

begin
  assign(f, 'chess.in');
  assign(f1, 'chess.out');
  reset(f);
  rewrite(f1);
  readln(f,n);
  for i:=1 to n do begin
  read(f,a);
  if a<i then begin count:=i-1; break; end;
  end;
  writeln(f1,count);
  for i:=1 to count do begin
  writeln(f1,i,' ',i)
  end;
  close(f);
  close(f1);
end.