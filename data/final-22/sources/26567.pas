program Problem_4_F_alpha;

{$APPTYPE CONSOLE,Q-,R-,O-}

const int=12;

type weight=record
        v,e:longint;
     end;

var i,n,m,x,y,z:longint;
    w:array[0..500000]of longint;
    q:array[1..4,-1..500000]of longint;
    g:array[0..500000]of array of weight;

procedure bfs;
var u,n,i,j,e,l:longint;
begin
   for j:=1 to 4 do
    //  while q[j,0]>0 do
      if q[j,0]>0 then
         begin
            u:=q[j,q[j,-1]];
            e:=w[q[j,q[j,-1]]];
            inc(q[j,-1]);
            dec(q[j,0]);
            n:=high(g[u]);
            for i:=0 to n do
               begin
                  if w[g[u][i].v]>e+g[u][i].e
                     then begin
                             l:=trunc(int/g[u][i].e);
                             inc(q[l,0]);
                             q[l,q[l,0]+q[l,-1]-1]:=g[u][i].v;
                             w[g[u][i].v]:=e+g[u][i].e;
                          end;
               end;
         end;
end;

begin
   assign(input,'graph.in');
   assign(output,'graph.out');
   read(n,m);
   for i:=1 to n do
      w[i]:=maxlongint;
   for i:=1 to m do
      begin
         read(x,y,z);
         setlength(g[x],length(g[x])+1);
         setlength(g[y],length(g[y])+1);
         g[x][high(g[x])].v:=y;
         g[x][high(g[x])].e:=trunc(int/z);
         g[y][high(g[y])].v:=x;
         g[y][high(g[y])].e:=trunc(int/z);
      end;
   q[1,1]:=1;
   q[1,0]:=1;
   q[1,-1]:=1;
   q[2,-1]:=1;
   q[3,-1]:=1;
   q[4,-1]:=1;
   w[1]:=0;
   repeat
      bfs;
   until (q[1,0]=0)and(q[2,0]=0)and(q[3,0]=0)and(q[4,0]=0);   
   for i:=2 to n do
      writeln(w[i]/12:0:17);
   close(input);
   close(output);
end.
