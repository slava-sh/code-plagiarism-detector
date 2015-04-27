program graph;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

type versh=record
    tochka,ves,sled,num:integer;
  end;
    t2=record
      stoim,put,pe:integer;
    end;
const
   MODU = 13;
   MAXN = 500000;
   MAXE = 800000;
var
  flag:boolean;
  otv:extended;
  x,y,j,lp,dist,n,m,i,k,kolvo,z,ans,v,l,r:integer;
  rp:array[0..MODU - 1] of integer;
  och:array[0..MAXN,0..MODU - 1] of integer;
  rasst,use,a:array[0..MAXN] of integer;
  p:array[0..2 * MAXE] of versh;

procedure proc(x,y,z:integer);
  begin
    inc(j);
    p[j].tochka:=y;
    p[j].ves:=z;
    p[j].sled:=a[x];
    a[x]:=j;
  end;


begin
  assign(input,'graph.in');
  assign(output,'graph.out');
  reset(input);
  rewrite(output);
    read(n,m);
    for i:=1 to m do
      begin
        read(x,y,z);
        if z=2 then z:=6 else
        if z=1 then z:=12 else
        if z=3 then z:=4 else
        if z=4 then z:=3;
        proc(x,y,z);
        proc(y,x,z);
      end;



      fillchar(use,sizeof(use),0);
      for i:=1 to n do
        rasst[i]:=1000000;

      rasst[1]:=0;
      j:=0;
      x:=0;
      dist:=0;
      k:=0;
      lp := 0;
      for i:=0 to modu-1 do
        rp[i]:=1;
  flag:=false;


  v:=1;
 while not flag do
   begin
    use[v]:=1;
    j:=a[v];
    while p[j].tochka<>0 do
      begin
        if (use[p[j].tochka]=0) and (rasst[v]+p[j].ves<rasst[p[j].tochka]) then
          begin
            och[rp[(x+p[j].ves) mod MODU],(x+p[j].ves) mod MODU]:=p[j].tochka;
            inc(rp[(x+p[j].ves) mod MODU]);
            rasst[p[j].tochka]:=rasst[v]+p[j].ves;
          end;
         j:=p[j].sled;
       end;
    inc(lp);
    if lp=rp[x] then
      begin
        rp[x]:=1;
        x := (x + 1) mod modu;
        lp:=1;
        r:=0;
        while rp[x]=1 do
        begin
            inc(r);
            x:=(x+1) mod modu;
            if r=modu then flag:=true;
            if flag= true then break;
         end;
      end;
    v:=och[lp,x];
end;






  for i:=2 to n do
    begin
      otv:=rasst[i]/12;
      writeln(otv);
    end;


  close(input);
  close(output);
end.

