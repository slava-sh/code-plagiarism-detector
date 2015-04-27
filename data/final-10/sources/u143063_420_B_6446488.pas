var sum,w,n,m,i,tmp:longint;
  ch:array[0..1000000]of char;
  bk:char;
  ans,f,c:array[0..1000000]of boolean;
  a,z:array[0..1000000]of longint;
begin
  readln(n,m);
  for i:=1 to m do
  begin
  read(ch[i]);
  read(bk);
  readln(a[i]);
  end;



  for i:=1 to m do
  begin
  c[a[i]]:=true;
  if (ch[i]='-')and(f[a[i]]=false) then
  begin
  f[a[i]]:=true;inc(sum);
  end
  else
  if (ch[i]='+') then
  f[a[i]]:=true;
  end;


  tmp:=0;
  for i:=1 to m do
  if ch[i]='+' then
  begin
  if (sum=0) then
  begin
  if (tmp<>0)and(tmp<>a[i]) then begin ans[tmp]:=true;ans[a[i]]:=true;end;tmp:=a[i];
  end
  else
  ans[a[i]]:=true;
  inc(sum);
  end
  else
  begin
  if (sum=1) then
  begin
  if (tmp<>0)and(tmp<>a[i]) then begin ans[tmp]:=true;ans[a[i]]:=true;end;tmp:=a[i];
  end
  else
  ans[a[i]]:=true;
  dec(sum);
  end;

  for i:=1 to n do
  if not ans[i] then
  begin
  inc(w);
  z[w]:=i;
  end;
  writeln(w);
  if w<>0 then
  begin
  for i:=1 to w-1 do
  write(z[i],' ');
  writeln(z[w]);
  end;
end.
