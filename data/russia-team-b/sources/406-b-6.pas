uses math;
var
  ans : int64;
  i,delta : longint;
  RR,LL,n,d,l,r,mid,cur : int64;
  a : array [0..400000] of int64;
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
    if abs(a[i]-a[n])>d then RR:=n else continue;
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
    for delta:=0 to 300 do
      if i+1+delta<=n then
        if abs(a[i]-a[i+1+delta])>d then
        LL:=min(LL,i+1+delta);
    LL:=min(LL,n);
    ans:=ans+RR-LL+1;
  end;
  writeln(ans);
  close(input);
  close(output);
end.