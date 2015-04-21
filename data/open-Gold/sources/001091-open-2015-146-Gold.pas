const
  maxn=3000;
  maxk=3000;
var
 dyn:array[0..maxn,0..maxk] of int64;
 pb,a,b:longint;
 n,m,c,d:longint;
 i,j:longint;

 function min(a,b:int64):int64;
 begin
   min:=a;
   If a>b then min:=b;
 end;

begin
 read(n,m,c,d);
   i:=1;
   read(a,b);
   For j:=1 to m-1 do
   begin
    dyn[i,j]:=min(dyn[i-1,j]+(b-a)*d,dyn[i-1,j-1]+(b-a)*d);
   end;
   dyn[i,0]:=min(dyn[i-1,0]+(b-a)*d,dyn[i-1,m-1]+c+(b-a)*d);
   pb:=b;
 For i:=2 to n do
 begin
   read(a,b);
   For j:=1 to m-1 do
   begin
    dyn[i,j]:=min(dyn[i-1,j]+(b-pb)*d,dyn[i-1,j-1]+(b-a)*d);
   end;
   dyn[i,0]:=min(dyn[i-1,0]+(b-pb)*d,dyn[i-1,m-1]+c+(b-a)*d);
   pb:=b;
 end;
 j:=high(longint);
 For i:=0 to m-1 do
 begin
   j:=min(j,dyn[n,i]);
 end;
 writeln(j);
 readln;
 readln;
end.
