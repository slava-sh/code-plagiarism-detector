Uses math;
Var j,top,i,n,k,i1,j1,ii,kol:longint;
a,c,pred,z,m:array [1..1000000] of longint;
zzz,g,heap:array [1..30000000] of longint;
used1,used:array [1..5000] of boolean;
zuk,gde,d:longint;
procedure add(i,j,zz:longint);
begin
  inc(kol);
  m[kol]:=j;
  c[kol]:=zz;
  pred[kol]:=z[i];
  z[i]:=kol;
end;
procedure update(i:longint);
Var b:longint;
begin
  if i=1
  then exit;
  if heap[i div 2]>heap[i]
  then begin
        b:=heap[i div 2];
        heap[i div 2]:=heap[i];
        heap[i]:=b;
        b:=g[i div 2]; g[i div 2]:=g[i]; g[i]:=b;
        b:=zzz[i div 2]; zzz[i div 2]:=zzz[i]; zzz[i]:=b;
        update(i div 2)
       end;
end;
procedure spusk(i:longint);
Var b:longint;
begin
  if i*2>top
  then exit;
  if i*2+1<=top
  then begin
        if min(heap[i*2],heap[i*2+1])>heap[i]
        then exit;
        if heap[i*2]<heap[i*2+1]
        then begin
              b:=heap[i]; heap[i]:=heap[i*2]; heap[i*2]:=b;
              b:=g[i]; g[i]:=g[i*2]; g[i*2]:=b;
              b:=zzz[i]; zzz[i]:=zzz[i*2]; zzz[i*2]:=b;
              spusk(i*2);
             end
        else begin
              b:=heap[i]; heap[i]:=heap[i*2+1]; heap[i*2+1]:=b;
              b:=g[i]; g[i]:=g[i*2+1]; g[i*2+1]:=b;
              b:=zzz[i]; zzz[i]:=zzz[i*2+1]; zzz[i*2+1]:=b;
              spusk(i*2+1);
             end;
       end
  else begin
        if heap[i]>heap[i*2]
        then begin
              b:=heap[i]; heap[i]:=heap[i*2]; heap[i*2]:=b;
              b:=g[i]; g[i]:=g[i*2]; g[i*2]:=b;
              b:=zzz[i]; zzz[i]:=zzz[i*2]; zzz[i*2]:=b;
              spusk(i*2);
             end;
       end;
end;
begin
  Assign(input,'secure.in'); reset(input);
  Assign(output,'secure.out'); rewrite(output);
  read(n,k);
  for i:=1 to n do
  read(a[i]);
  kol:=0;
  for i:=1 to k do
  begin
    read(i1,j1,ii);
    add(i1,j1,ii);
    add(j1,i1,ii);
  end;
  top:=0;
  for i:=n downto 1 do
  if a[i]=1
  then begin
        inc(top);
        heap[top]:=0;
        g[top]:=i;
        zzz[top]:=i;
        used[i]:=true;
        update(top);
       end;
  while top<>0 do
  begin
          used[g[1]]:=true;
          if a[g[1]]=2
          then begin
                  writeln(zzz[1],' ',g[1],' ',heap[1]);
                   halt(0)
               end;
          d:=heap[1];
          gde:=g[1];
          zuk:=zzz[1];
          g[1]:=g[top];
          heap[1]:=heap[top];
          zzz[1]:=zzz[top];
          dec(top);
          if top<>0
          then spusk(1);
          if used1[gde]
          then continue;
          used1[gde]:=true;
          j:=z[gde];
          while j<>0 do
          begin
            if used[m[j]]=false
            then begin
                  inc(top);
                  heap[top]:=d+c[j];
                  g[top]:=m[j];
                  zzz[top]:=zuk;
                  update(top);
                 end;
            j:=pred[j];
          end;

  end;
  writeln(-1)
end.
 
