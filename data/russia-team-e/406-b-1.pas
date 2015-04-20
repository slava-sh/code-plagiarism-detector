uses math;
var
  ans : int64;
  RR,LL,n,d,i,l,r,mid,cur,delta : longint;
  a : array [0..400000] of longint;
begin
  assign(input,'che.in'); reset(input);
  assign(output,'che.out'); rewrite(output);
  ans:=0;
  readln(n,d);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
  begin
    RR:=-maxlongint;
    LL:=maxlongint;
    if abs(a[i]-a[n])>d then RR:=n else RR:=maxlongint;
    l:=i+1; r:=n;
    while (l<r) do
    begin
      mid:=(l+r) shr 1;
      if abs(a[i]-a[mid])>d then
      begin
        LL:=min(LL,mid);
        r:=mid;
      end else l:=mid+1;
    end;
    for delta:=0 to 4 do
      if 1+delta>=i+1 then
        if abs(a[i]-a[1+delta])>d then
        LL:=min(LL,1+delta);
    if (LL<maxlongint) and (RR<maxlongint) and (LL>-maxlongint) and (RR>-maxlongint) then ans:=ans+(RR-LL+1);
  end;
  writeln(ans);
  close(input);
  close(output);
end.