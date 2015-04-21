const
  mm = 200000;
  mn = 100000;
type
  pointer = ^tree;

  tree = record
   ind:longint;
   left:pointer;
   right:pointer;
  end;

  mass = array[1..2*mm] of longint;

var
  graph:mass;
  last:array[1..mn] of longint;
  ans:array[1..mn] of longint;
  prev:mass;
  time:mass;
  used:mass;
  hot:mass;
  root:pointer;
  q,n,m,d,i,j,k:longint;
  u,v,t:longint;


  function min(a,b:longint):longint;
  begin
   min:=a;
   If a>b then min:=b;
  end;

  procedure refresh(pos:longint;var root:pointer;l,r:longint);
  begin
   If root<>nil then
   begin
    If (l<r) Then
    begin
     If pos<=l+(r-l) div 2 then
     begin
      refresh(pos,root^.left,l,l+(r-l) div 2);
     end
     else
     begin
      refresh(pos,root^.right,l+1+(r-l) div 2,r);
     end;
     If time[root^.left^.ind]<time[root^.right^.ind] then
     begin
      root^.ind:=root^.left^.ind;
     end
     else
     begin
      root^.ind:=root^.right^.ind;
     end;
    end;
   end;
  end;

  procedure build(var root:pointer;l,r:longint);
  begin
   new(root);
   root^.left:=nil;
   root^.right:=nil;
   If r>l Then
   begin
    build(root^.left,l,l+(r-l) div 2);
    build(root^.right,l+1+(r-l) div 2,r);
    If time[root^.left^.ind]<time[root^.right^.ind] then
    begin
     root^.ind:=root^.left^.ind;
    end
    else
    begin
     root^.ind:=root^.right^.ind;
    end;
   end
   else
   begin
    If l=r Then
    begin
     root^.ind:=l;
    end;
   end;
  end;


begin
 read(n,m,d);
 For i:=1 to m do
 begin
  read(u,v,t);
  graph[i]:=v;
  hot[i]:=t;
  graph[i+m]:=u;
  hot[i+m]:=t;
  prev[i]:=last[u];
  prev[i+m]:=last[v];
  last[u]:=i;
  last[v]:=i+m;
 end;
 For i:=1 to 2*m do
 begin
  time[i]:=high(longint);
 end;
 read(q);
 For t:=1 to q do
 begin
  For i:=1 to n do
  begin
   ans[i]:=high(longint);
  end;
  read(u,v);
  i:=last[u];
  While i<>0 do
  begin
   time[i]:=0;
   ans[graph[i]]:=1;
   i:=prev[i];
  end;
  build(root,1,2*m);
  For i:=1 to 2*m do
  begin
   k:=root^.ind;
   j:=last[graph[k]];
   While j<>0 do
   begin
    If (abs(hot[j]-hot[k])<=d) and (used[j]<t) Then
    begin
     time[j]:=min(time[j],time[k]+1);
     If ans[graph[j]]>time[j]+1 Then ans[graph[j]]:=time[j]+1;
     refresh(j,root,1,2*m);
    end;
    j:=prev[j];
   end;
   time[k]:=high(longint);
   used[k]:=t;
   refresh(k,root,1,2*m);
  end;
  If ans[v]=high(longint) then writeln(-1) else writeln(ans[v]);
 end;
 readln;
 readln;
end.
