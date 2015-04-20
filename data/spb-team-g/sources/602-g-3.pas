program blah;
var
  f1, f2: text;
  ves: array[1..10000] of cardinal;
  n,nc, sum, i,j : cardinal;
  blah: boolean;
begin
  blah:=true;
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
  for i:=1 to n-1 do begin
    for j:=i+1 to n do begin
      blah:=(ves[i]<>ves[j]);
    end;
  end;
  if not blah then write(f2,0)
  else write(f2,round(n-sum/n));
  close(f2);
end.