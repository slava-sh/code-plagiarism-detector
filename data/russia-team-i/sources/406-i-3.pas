var
  n,d,x,i,s,k : longint;
begin
  assign(input,'sochi.in');reset(input);
  assign(output,'sochi.out');rewrite(output);
  readln(n,d);
  s:=0; k:=0;
  for i:=1 to n do
  begin
    read(x);
    if x>2*d then
    begin
      inc(k);
      s:=s+x;
    end;
  end;
  dec(k);
  writeln(s-(2*d*k));
  close(input);
  close(output);
end.