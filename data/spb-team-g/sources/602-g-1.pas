program rook_fill;
var
  f1, f2: text;
  ves: array[1..10000] of cardinal;
  n,nc, sum: cardinal;
begin
  assign(f1, 'merlin.in');
  assign(f2, 'merlin.out');
  reset(f1);
  readln(f1,n);
  sum:=0;
  for nc:=1 to n do begin
    read(f1,ves[n]);
    sum+=ves[n];
  end;
  close(f1);
  rewrite(f2);
  write(f2,n-(sum div n));
  close(f2);
end.