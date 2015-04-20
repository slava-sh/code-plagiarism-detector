var
  pos,n,r,i:longint;
  a:array [0..330000] of longint;
  ans:int64;
begin
  assign(input,'che.in'); reset(input);
  assign(output,'che.out'); rewrite(output);
  readln(n,r);
  for i:=1 to n do read(a[i]);
  ans:=0;
  pos:=1;
  for i:=1 to n do
    begin
      if pos<i then pos:=i;
      while (pos+1<=n) and (a[pos]-a[i]<=r) do inc(pos);
      if a[pos]-a[i]>r then ans:=ans+(n-pos+1);
    end;
  writeln(ans);
  close(input);
  close(output);
end.