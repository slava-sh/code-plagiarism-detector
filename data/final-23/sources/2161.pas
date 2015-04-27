const
  filename='signchange';

type
  int=integer;
  pnode=^tnode;
  tnode=record
    l,r:pnode;
    num,x,y:int;
    sum:int;
  end;

var
  n,m,i,x,y,c:int;
  root,root2:pnode;

function calculate(t:pnode):int;
begin
  if t=nil then
    calculate:=0
  else
    calculate:=t.num;
end;

procedure calc(t:pnode);
begin
  if t<>nil then
    t.num:=calculate(t.l)+calculate(t.r)+1;
end;

function sum(t:pnode):int;
begin
  if t=nil then
    result:=0
  else
    result:=t.sum;
end;

procedure setsum(t:pnode);
begin
  if t<>nil then
    t.sum:=t.x+sum(t.l)+sum(t.r);
end;

procedure split(t:pnode;k:int;var l,r:pnode);
var
  q:int;
begin
  if t=nil then begin
    l:=nil;
    r:=nil
  end else begin
    q:=calculate(t.l);
    if k<=q then begin
      split(t.l,k,l,t.l);
      r:=t;
    end else begin
      split(t.r,k-q-1,t.r,r);
      l:=t;
    end;
  end;
  calc(l);
  calc(r);
  setsum(l);
  setsum(r);
end;

function merge(l,r:pnode):pnode;
begin
  if l=nil then
    merge:=r
  else
    if r=nil then
      merge:=l
    else
      if l.y>r.y then begin
        l.r:=merge(l.r,r);
        merge:=l;
        calc(l);
        setsum(l);
      end else begin
        r.l:=merge(l,r.l);
        merge:=r;
        calc(r);
        setsum(r);
      end;
end;

procedure add(var t:pnode;x,y:int);
var
  tmp:pnode;
begin
  new(tmp);
  tmp.l:=nil;
  tmp.r:=nil;
  tmp.x:=x;
  tmp.y:=y;
  tmp.num:=1;
  tmp.sum:=x;
  t:=merge(t,tmp);
end;

{procedure printtree(t:pnode;k:integer);
begin
  if t=nil then
    exit;
  printtree(t.l,k+1);
  writeln('':k*3,'(x: ',t.x,', num: ',t.num,', sum: ',t.sum,')');
  printtree(t.r,k+1);
end;}

procedure getsum(i,j:int);
var
  a,b,c,d:pnode;
  x,y,i1:int;
  s:int;
begin
  a:=nil;
  b:=nil;
  c:=nil;
  d:=nil;
  i1:=i;
  x:=i;
  y:=j;
  if not odd(x) then
    inc(x);
  if not odd(y) then
    dec(y);
  if x<=y then begin
    split(root,(y+1) div 2,root,b);
    split(root,(x+1) div 2-1,root,a);
  end;
  if odd(i) then
    inc(i);
  if odd(j) then
    dec(j);
  if i<=j then begin
    split(root2,j div 2,root2,d);
    split(root2,i div 2-1,root2,c);
  end;
  s:=0;
  if a<>nil then
    if odd(i1) then
      inc(s,a.sum)
    else
      dec(s,a.sum);
  if c<>nil then
    if odd(i1) then
      dec(s,c.sum)
    else
      inc(s,c.sum);
  writeln(s);
  root:=merge(root,a);
  root:=merge(root,b);
  root2:=merge(root2,c);
  root2:=merge(root2,d);
end;

procedure change(i,j:int);
var
  a,b:pnode;
begin
  if odd(i) then begin
    a:=nil;
    b:=nil;
    split(root,(i+1) div 2,root,b);
    split(root,(i+1) div 2-1,root,a);
    a.x:=j;
    setsum(a);
    root:=merge(root,a);
    root:=merge(root,b);
  end else begin
    a:=nil;
    b:=nil;
    split(root2,i div 2,root2,b);
    split(root2,i div 2-1,root2,a);
    a.x:=j;
    setsum(a);
    root2:=merge(root2,a);
    root2:=merge(root2,b);
  end;
end;

begin
  reset(input,filename+'.in');
  rewrite(output,filename+'.out');
  randomize;
  root:=nil;
  root2:=nil;
  readln(n);
  for i:=1 to n do begin
    read(x);
    if odd(i) then
      add(root,x,random(2000000000))
    else
      add(root2,x,random(2000000000))
  end;
  readln;
  readln(m);
  for i:=1 to m do begin
    readln(c,x,y);
    case c of
      0:
        change(x,y);
      1:
        getsum(x,y);
    end;
  end;
  close(input);
  close(output);
end.