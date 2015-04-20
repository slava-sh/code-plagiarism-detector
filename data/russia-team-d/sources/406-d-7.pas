uses math;
var
  l,r,d,n,minA,ans,mid,k,i,sum,delta : longint;
  a : array [0..200000] of longint;
begin
  assign(input,'fence.in'); reset(input);
  assign(output,'fence.out'); rewrite(output);
  minA:=maxlongint;
  readln(n,k);
  for i:=1 to n do
  begin
    read(a[i]);
    sum:=sum+a[i];
    if a[i]<minA then minA:=a[i];
  end;
  ans:=0;
  l:=1; r:=minA;
  while (l<r) do
  begin
    mid:=(l+r) shr 1;
    if (k-(mid*n))>=0 then
    begin
      ans:=max(ans,mid);
      l:=mid+1;
    end else r:=mid;
  end;
  for delta:=0 to 100000 do
    if (k-delta>=1) and ((k-((k-delta)*n))>=0) and (k-delta<=minA) then
      ans:=max(ans,k-delta);
  writeln(ans);
  close(input);
  close(output);
end.