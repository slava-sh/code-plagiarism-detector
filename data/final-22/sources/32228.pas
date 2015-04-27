program bb;
{$APPTYPE CONSOLE}
type node = record
  w,cst:integer;
end;
var a:array[0..500000]of array of node;
t:array[0..500000]of integer;
cst,u,v:array[0..800000]of integer;
curdist:array[0..500000]of integer;
lw,hgh:array[0..12]of integer;
q:array[0..12,0..500000]of integer;
stp:boolean;
CNST:integer;
i,n,m,j,dist,v1,ww1,tek,restn,realdist,way:integer;
begin
CNST:=13;
reset(input,'graph.in');
rewrite(output,'graph.out');
read(n,m);
for i:=1 to m do
  begin
    read(u[i],v[i],cst[i]);
    if cst[i]=1 then cst[i]:=12 else
    if cst[i]=2 then cst[i]:=6 else
    if cst[i]=3 then cst[i]:=4 else
      cst[i]:=3;
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
    a[u[i],t[u[i]]].cst:=cst[i];
    a[v[i],t[v[i]]].cst:=cst[i];
    inc(t[u[i]]);
    inc(t[v[i]]);
  end;
fillchar(t,sizeof(t),0);
for i:=2 to n do
    curdist[i]:=maxint;
dist:=0;
realdist:=0;
q[0,1]:=1;
lw[0]:=1;
hgh[0]:=1;
while not stp do
  begin
     while lw[dist]<=hgh[dist]do
       begin
         v1:=q[dist mod CNST,lw[dist mod CNST]];
         if t[v1]=0 then
           begin
             for j:=0 to length(a[v1])-1 do
               if t[a[v1,j].w]=0 then
                 begin
                   way:=a[v1,j].cst;
                   if curdist[a[v1,j].w]>realdist+way then
                     begin
                       curdist[a[v1,j].w]:=realdist + way;
                       ww1:=curdist[a[v1,j].w] mod CNST;
                       inc(hgh[ww1]);
                       q[ww1,hgh[ww1]]:=a[v1,j].w;
                       if lw[ww1]=0 then inc(lw[ww1]);
                     end;

                 end;
           end;
         inc(lw[dist]);
         t[v1]:=1;
       end;
     stp:=true;
     for i:=1 to n do
       if t[i]=0 then begin  stp:=false;break;end;
     stp:=true;
     for i:=0 to 12 do
       if hgh[i]>0 then begin  stp:=false;break;end;
     lw[dist]:=0;
     hgh[dist]:=0;
     inc(dist);
     dist:=dist mod CNST;
     inc(realdist);
  end;
for i:=2 to n do
  writeln(curdist[i]/12:0:10);


end.
 
