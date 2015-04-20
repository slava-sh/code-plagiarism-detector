var
  n,m,ans : longint;
  procedure swap(var a,b : longint);
  var c : longint;
  begin
    c:=a; a:=b; b:=c;
  end;
  function count(n : longint) : longint;
  var res,cur : longint;
  begin
    res:=trunc((n+1)/4);
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
