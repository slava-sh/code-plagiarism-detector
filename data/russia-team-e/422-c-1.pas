uses
  math;
const
  ll=200000;
type
  edges=record
    t,n:longint;
  end;
var
  ee:array[1..2*ll] of edges;
  start,a,d1,d2,big:array[1..ll] of longint;
  used:array[1..ll] of boolean;
  size,cnt,i,n,x1,x2,x,y,ans:longint;
  good:boolean;

procedure add(x,y:longint);
begin
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].n:=start[x];
  start[x]:=cnt;
end;

function find(x:longint):longint;
var
  e,res:longint;
begin
  used[x]:=true;
  e:=start[x];
  res:=0;
  while (e<>0) do
  begin
    if (not used[ee[e].t]) then res:=max(res,find(ee[e].t));
    e:=ee[e].n;
  end;
  exit(res+1);
end;

function find(x,prev:longint):boolean;
var
  now:boolean;
  e:longint;
begin
  inc(size);
  a[size]:=x;
  if (x=x2) then exit(true);
  e:=start[x];
  while (e<>0) do
  begin
    if (ee[e].t<>prev) then
    begin
      now:=find(ee[e].t,x);
      if (now) then exit(true);
    end;
    e:=ee[e].n;
  end;
  dec(size);
  find:=false;
end;

begin
  assign(input,'dwarfs.in');
  reset(input);
  assign(output,'dwarfs.out');
  rewrite(output);
  readln(n);
  cnt:=0;
  for i:=1 to n-1 do
  begin
    readln(x,y);
    add(x,y);
    add(y,x);
  end;
  readln(x1,x2);
  fillchar(used,sizeof(used),false);
  size:=0;
  good:=find(x1,-1);
  for i:=1 to size do used[a[i]]:=true;
  for i:=1 to size do big[a[i]]:=find(a[i])-1;
  for i:=1 to size-1 do
  begin
    d1[a[i]]:=big[a[i]]+i;
    if (i<>1) then d1[a[i]]:=max(d1[a[i-1]],d1[a[i]]);
  end;
  for i:=size downto 2 do 
  begin
    d2[a[i]]:=big[a[i]]+(size-i+1);
    if (i<>size) then d2[a[i]]:=max(d2[a[i+1]],d2[a[i]]);
  end;
  ans:=0;
  for i:=1 to size-1 do ans:=max(ans,min(d1[a[i]],d2[a[i+1]]));
  writeln(ans);
  close(input);
  close(output);
end.
