var
  a:array[1..200000] of longint;
  n,d,i,ans,prev,j:longint;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=a[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (a[i]<d) do inc(i);
    while (a[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

begin
  assign(input,'sochi.in');
  reset(input);
  assign(output,'sochi.out');
  rewrite(output);
  readln(n,d);
  for i:=1 to n do read(a[i]);
  randomize;
  sort(1,n);
  ans:=a[n];
  prev:=maxlongint;
  for i:=n-1 downto 1 do
  begin
    if (a[i]<d) then begin j:=i; break; end;
    if (prev<2*d) then begin j:=i; break; end;
    if (ans+a[i]-2*d>=ans) then
    begin
      ans:=ans+a[i]-2*d;
      prev:=a[i]-d;
    end;
  end;
  prev:=a[n]-d;
  for i:=j downto 1 do
  begin
    if (a[i]<d) then break;
    if (prev<2*d) then break;
    if (ans+a[i]-2*d>=ans) then 
    begin
      ans:=ans+a[i]-2*d;
      prev:=a[i]-d;
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
