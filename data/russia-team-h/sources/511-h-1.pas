{$r-,s-,q-,i-,o+}
const
  inf=10000000000;
var
  h:array[0..500000] of record x,y:longint; z:int64; end;
  c,pp,num,next,cost,g:array [0..400000] of longint;
  d:array [0..200000] of int64;
  n,m,tt,i,j,kv:longint;
  ans,ansl,ansr,x,y,z:int64;


  procedure put(x,y:longint;z:int64);
    var
      v,vv:longint;
    begin
      inc(kv); h[kv].x:=x; h[kv].y:=y; h[kv].z:=z;
      v:=kv;
      while (v shr 1>0) do
        begin
          vv:=v shr 1;
          if h[v].z>=h[vv].z then break;
          h[0]:=h[v]; h[v]:=h[vv]; h[vv]:=h[0];
          v:=vv;
        end;
    end;

  procedure del;
    var
      v,vv:longint;
    begin
      h[1]:=h[kv]; dec(kv);
      v:=1;
      while (v shl 1<=kv) do
        begin
          vv:=v shl 1;
          if (vv<kv) and (h[vv].z>h[vv+1].z) then vv:=vv+1;
          if h[v].z<=h[vv].z then break;
          h[0]:=h[v]; h[v]:=h[vv]; h[vv]:=h[0];
          v:=vv;
        end;
    end;

begin
  assign(input,'secure.in'); reset(input);
  assign(output,'secure.out'); rewrite(output);
  read(n,m); tt:=0;
  for i:=1 to n do read(c[i]);
  for i:=1 to n do g[i]:=0;
  for i:=1 to m do
    begin
      read(x,y,z);
      inc(tt); num[tt]:=y; next[tt]:=g[x]; g[x]:=tt; cost[tt]:=z;
      inc(tt); num[tt]:=x; next[tt]:=g[y]; g[y]:=tt; cost[tt]:=z;
    end;
  for i:=1 to n do d[i]:=inf;
  kv:=0;
  for i:=1 to n do
    begin
      if c[i]<>1 then continue;
      put(i,i,0);
      d[i]:=0; pp[i]:=i;
    end;
  while (kv>0) do
    begin
      x:=h[1].x; y:=h[1].y; z:=h[1].z;
      del;
      if d[x]<z then continue;
      j:=g[x];
      while (j>0) do
        begin
          if (d[num[j]]>z+cost[j])
            then begin
                   d[num[j]]:=z+cost[j];
                   put(num[j],y,z+cost[j]);
                   pp[num[j]]:=y;
                 end;
          j:=next[j];
      end;
    end;
  ans:=inf; ansl:=-1; ansr:=-1;
  for i:=1 to n do
    if c[i]=2
      then begin
             if d[i]=inf then continue;
             if ans>d[i]
               then begin
                      ans:=d[i];
                      ansl:=pp[i]; ansr:=i;
                    end;
           end;
  if ans=inf
    then writeln(-1)
    else writeln(ansl,' ',ansr,' ',ans);
  close(input);
  close(output);
end.