var
  n,h,x,m,i,k:integer;
  q,p:boolean;
  f:array [1..200000]of integer;
begin
  assign(input, 'seq.in');
  assign(output, 'seq.out');
  read(input,n);
  read(input,h);
  p:=false;
  m:=(h+1)*(h div 2) + (h div 2 + 1)*(h mod 2);
  x:=0;
  for i:=1 to n do
  read(input,f[i]);
  for i:=1 to n-h+1 do
  begin
    q:=true;
    k:=1;
    if f[i]<=1 then
    while (k<=h) and q do
    begin
      if(f[k+i-1]<=k) then
        x:=x+k-f[k+i-1]
       else
        q:=false;
      k:=k+1;
    end;
  if (x<m) and q then
  begin
    m:=x;
    p:=true;
  end;
  x:=0;
  end;
  if p then
  write(output,m)
  else
  write(output,'-1')
end.