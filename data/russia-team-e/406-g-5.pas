var
  n,m,ans : longint;
  procedure swap(var a,b : longint);
  begin
    a:=a xor b;
    b:=a xor b;
    a:=a xor b;
  end;
  function count(n : longint) : longint;
  var res,cur : longint;
  begin
    cur:=3;
    res:=0;
    while (cur<=n) do
    begin
      inc(res);
      cur:=cur+4;
    end;
    exit(res);
  end;
begin
  assign(input,'prizes.in'); reset(input);
  assign(output,'prizes.out'); rewrite(output);
  readln(n,m);
  if n>m then swap(n,m);
  if (n=1) then ans:=count(m) else ans:=count(n);
  writeln(ans);
  close(input);
  close(output);
end.