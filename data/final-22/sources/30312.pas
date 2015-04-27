program bb;
{$APPTYPE CONSOLE}
type node = record
  w,cost:integer;
end;
var a:array[0..500000]of array of node;
t:array[0..500000]of integer;
cost,u,v:array[0..800000]of integer;
curdist:array[0..500000]of integer;
low,high:array[0..12]of integer;
q:array[0..12,0..500000]of integer;
stop:boolean;
i,n,m,j,dist,v1,w1,tek,restn,distreal,way:integer;
begin
reset(input,'graph.in');
rewrite(output,'graph.out');
read(n,m);
for i:=1 to m do
  begin
    read(u[i],v[i],cost[i]);
    if cost[i]=1 then cost[i]:=12 else
    if cost[i]=2 then cost[i]:=6 else
    if cost[i]=3 then cost[i]:=4 else
      cost[i]:=3;
    inc(t[u[i]]);
    inc(t[v[i]]);
  end;
for i:=1 to n do
  setlength(a[i],t[i]);
fillchar(t,sizeof(t),0);
for i:=1 to m do
  begin
    a[u[i],t[u[i]]].w:=v[i];
    a[v[i],t[v[i]]].w:=u[i];
    a[u[i],t[u[i]]].cost:=cost[i];
    a[v[i],t[v[i]]].cost:=cost[i];
    inc(t[u[i]]);
    inc(t[v[i]]);
  end;
fillchar(t,sizeof(t),0);
for i:=2 to n do
    curdist[i]:=maxint;
dist:=0;
distreal:=0;
q[0,1]:=1;
low[0]:=1;
high[0]:=1;
while not stop do
  begin
     while low[dist]<=high[dist]do
       begin
         v1:=q[dist mod 13,low[dist mod 13]];
         if t[v1]=0 then
           begin
             for j:=0 to length(a[v1])-1 do
               if t[a[v1,j].w]=0 then
                 begin
                   way:=a[v1,j].cost;
                   if curdist[a[v1,j].w]>distreal+way then
                     begin
                       curdist[a[v1,j].w]:=distreal + way;
                       w1:=curdist[a[v1,j].w] mod 13;
                       inc(high[w1]);
                       q[w1,high[w1]]:=a[v1,j].w;
                       if low[w1]=0 then inc(low[w1]);
                     end;

                 end;
           end;
         inc(low[dist]);
         t[v1]:=1;
       end;
     stop:=true;
     for i:=1 to n do
       if t[i]=0 then begin  stop:=false;break;end;
     stop:=true;
     for i:=0 to 12 do
       if high[i]>0 then begin  stop:=false;break;end;
     low[dist]:=0;
     high[dist]:=0;
     inc(dist);
     dist:=dist mod 13;
     inc(distreal);
  end;
for i:=2 to n do
  writeln(curdist[i]/12:0:10);


end.
 