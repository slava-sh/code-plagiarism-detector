{$r-,q-,t-,s-,i-,o+}
{$m 50000000}
uses math;
var
  found,n,m,i,x,y,z,e,totalAns,ansFirst,ansSecond,iteration,remembered : longint;
  a,mark,next,last,finish,cost : array [0..50000] of longint;
  procedure put(x,y,z : longint);
  begin
    inc(e);
    next[e]:=last[x];
    last[x]:=e;
    finish[e]:=y;
    cost[e]:=z;
  end;
  procedure dfs(x : longint; carry : int64);
  var p : longint;
  begin
    if (a[x]=2) and (carry<found) then
    begin
      found:=carry;
      remembered:=x;
    end;
    if (mark[x]<=carry) then exit;
    mark[x]:=carry;
    p:=last[x];
    while (p>0) do
    begin
      dfs(finish[p],carry+cost[p]);
      p:=next[p];
    end;
  end;
begin
  assign(input,'secure.in'); reset(input);
  assign(output,'secure.out'); rewrite(output);
  totalAns:=maxlongint;
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do mark[i]:=maxlongint;
  for i:=1 to m do
  begin
    readln(x,y,z);
    put(x,y,z);
    put(y,x,z);
  end;
  iteration:=0;
  for i:=1 to n do
    if (a[i]=1) then
    begin
      inc(iteration);
      found:=maxlongint;
      dfs(i,0);
      if (found<totalAns) then
      begin
        totalAns:=found;
        ansFirst:=i;
        ansSecond:=remembered;
      end;
    end;
  if totalAns=maxlongint then writeln(-1) else
  writeln(ansFirst,' ',ansSecond,' ',totalAns);
  close(input);
  close(output);
end.