{$r-,s-,q-,i-,o+}
{$M 14000000}
var
  g,num,next,cost,h1,h2,del,path,col,pred:array [0..500000] of longint;
  v,n,tt,ko,i,j,v1,v2,x,y,qans,ans:longint;
  function max(a,b:longint):longint; begin if a>b then max:=a else max:=b; end;
  function min(a,b:longint):longint; begin if a<b then min:=a else min:=b; end;

  procedure dfs1(v,p:longint);
    var
      j:longint;
    begin
      j:=g[v];
      while (j>0) do
        begin
          if p<>num[j]
            then begin
                   h2[num[j]]:=h2[v]+1;
                   pred[num[j]]:=v;
                   dfs1(num[j],v);
                 end;
          j:=next[j];
        end;
    end;

  procedure dfs2(v,p:longint);
    var
      j:longint;
    begin
      qans:=max(qans,h2[v]);
      j:=g[v];
      while (j>0) do
        begin
          if (num[j]<>path[ko]) and (num[j]<>p)
            then dfs2(num[j],v);
          j:=next[j];
        end;
    end;

  procedure dfs3(v,p:longint);
    var
      j:longint;
    begin
      del[v]:=1;
      j:=g[v];
      while (j>0) do
        begin
          if (col[num[j]]<>1) and (num[j]<>p)
            then begin
                   dfs3(num[j],v);
                   del[v]:=max(del[v],del[num[j]]+1);
                 end;
          j:=next[j];
        end;
    end;

  procedure dfs4(v,p:longint);
    var
      j:longint;
    begin
      j:=g[v];
      while (j>0) do
        begin
          if p<>num[j]
            then begin
                   h1[num[j]]:=h1[v]+1;
                   dfs4(num[j],v);
                 end;
          j:=next[j];
        end;
    end;

begin
  assign(input,'dwarfs.in'); reset(input);
  assign(output,'dwarfs.out'); rewrite(output);
  readln(n); tt:=0;
  for i:=1 to n-1 do
    begin
      read(x,y);
      inc(tt); num[tt]:=y; next[tt]:=g[x]; g[x]:=tt;
      inc(tt); num[tt]:=x; next[tt]:=g[y]; g[y]:=tt;
    end;
  readln(v1,v2);
  for i:=1 to n do h2[i]:=1;
  dfs1(v2,-1);
  for i:=1 to n do path[i]:=0;
  for i:=1 to n do col[i]:=0;
  v:=v1; ko:=0;
  while (true) do
    begin
      if v=v2 then break;
      inc(ko); path[ko]:=v;
      v:=pred[v];
    end;
  for i:=1 to ko do col[path[i]]:=1;
  qans:=1;
  dfs2(v2,-1);
  for i:=1 to n do del[i]:=0;
  for i:=1 to ko do dfs3(path[i],-1);
  for i:=1 to n do h1[i]:=1;
  dfs4(v1,-1);
  ans:=0;
  for i:=ko downto 1 do
    begin
      ans:=max(ans,min(qans,h1[path[i]]+del[path[i]]-1));
      j:=g[path[i]];
      while (j>0) do
        begin
          if (col[num[j]]=0)
            then qans:=max(qans,h2[path[i]]+del[num[j]]);
          j:=next[j];
        end;
    end;
  writeln(ans);
  close(input);
  close(output);
end.
