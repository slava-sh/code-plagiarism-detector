const
  l=5000;
var
  g:array[1..l,1..l] of longint;
  d,path,kind:array[1..l] of longint;
  used:array[1..l] of boolean;
  ans,x,y,z,n,m,i:longint;

procedure deikstra;
var
  i,j,nom,min:longint;
begin
  for i:=1 to n do
  begin
    used[i]:=false;
    d[i]:=maxlongint;
  end;
  for i:=1 to n do if (kind[i]=1) then begin d[i]:=0; path[i]:=i; end;
  for i:=1 to n do
  begin
    min:=maxlongint;
    nom:=0;
    for j:=1 to n do if (not used[j]) and (d[j]<min) then 
    begin
      min:=d[j];
      nom:=j;
    end;
    if (min=maxlongint) then exit;
    used[nom]:=true;
    for j:=1 to n do
    begin
      if (g[nom,j]=0) then continue;
      if (d[j]>d[nom]+g[nom,j]) then
      begin
        d[j]:=d[nom]+g[nom,j];
        path[j]:=path[nom];
      end;
    end;
  end;
end;

begin
  assign(input,'secure.in');
  reset(input);
  assign(output,'secure.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do read(kind[i]);
  readln;
  for i:=1 to m do
  begin
    readln(x,y,z);
    if (g[x,y]=0) or (g[x,y]>z) then 
    begin
      g[x,y]:=z;
      g[y,x]:=z;
    end;
  end;
  deikstra;
  ans:=maxlongint;
  x:=0;
  y:=0;
  for i:=1 to n do
  begin
    if (kind[i]<>2) then continue;
    if (d[i]<ans) then
    begin
      ans:=d[i];
      x:=path[i];
      y:=i;
    end;
  end; 
  if (ans=maxlongint) then writeln(-1) else writeln(x,' ',y,' ',ans);
  close(input);
  close(output);
end.