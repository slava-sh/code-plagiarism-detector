{$R-}{$Q-}
Uses math;
Var kol,i,n,i1,j1,rez:longint;
rr,dp,m,pred,z:Array [0..10000000] of longint;
ss:array [0..10000000] of boolean;
procedure add(i,j:longint);
begin
  inc(kol);
  m[kol]:=j;
  pred[kol]:=z[i];
  z[i]:=kol;
end;
procedure dfs(v,p:longint);
Var i:longint;
begin
  if v=j1
  then ss[v]:=true;
  dp[v]:=1;
  i:=z[v];
  while i<>0 do
  begin
    if m[i]<>p
    then begin
          dfs(m[i],v);
          dp[v]:=max(dp[v],dp[m[i]]+1);
          ss[v]:=ss[v] or ss[m[i]];
         end;
    i:=pred[i];
  end;  
end;
procedure dfs2(v,p,zz:longint);
Var i:longint;
begin
  if v=i1
  then exit;
  i:=z[v];
  rr[v]:=zz;
  while i<>0 do
  begin
    if ss[m[i]]=false
    then begin rr[v]:=max(rr[v],zz+dp[m[i]]); i:=pred[i]; continue; end;
    if m[i]=p
    then begin rr[v]:=max(rr[v],rr[m[i]]); i:=pred[i]; continue; end;
    dfs2(m[i],v,zz+1);    
    i:=pred[i];
  end;
end;
procedure dfs3(v,p,zz:longint);
Var zzz,i:longint;
begin
  if v=j1
  then exit;
  zzz:=zz;
  i:=z[v];
  while i<>0 do
  begin
    if (m[i]<>p)and(not ss[m[i]])
    then zzz:=max(zzz,zz+dp[m[i]]);
    i:=pred[i];
  end;
  i:=z[v];
  while i<>0 do
  begin
    if (m[i]<>p)and(ss[m[i]])
    then rez:=max(rez,min(zzz,rr[m[i]]));
    i:=pred[i];
  end;
  i:=z[v];
  while i<>0 do
  begin
    if (m[i]<>p)and(ss[m[i]])
    then dfs3(m[i],v,zz+1);
    i:=pred[i];
  end;
end;
begin
  Assign(input,'dwarfs.in'); reset(input);
  Assign(output,'dwarfs.out'); rewrite(output);
//  reset(input,'input.txt'); rewrite(output,'output.txt');
  read(n);
  kol:=0;
  for i:=1 to n-1 do
  begin
    read(i1,j1);
    add(i1,j1);
    add(j1,i1);
  end;
  read(i1,j1);
  dfs(i1,-1);
  dfs2(j1,-1,1);
  rez:=1;
  dfs3(i1,-1,1);
  writeln(rez)
end.
 
