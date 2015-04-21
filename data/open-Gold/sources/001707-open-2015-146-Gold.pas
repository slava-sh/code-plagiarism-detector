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
 For i:=1 to m do
 begin
   dyn[0,i]:=high(longint);
 end;
 For i:=1 to n do
 begin
   dyn[i,0]:=high(longint);
 end;
 pb:=0;
 For i:=1 to n do
 begin
   read(a,b);
   For j:=2 to m do
   begin
    dyn[i,j]:=min(dyn[i-1,j-1]+(b-a)*d,dyn[i-1,j]+(b-pb)*d);
   end;
   dyn[i,1]:=min(dyn[i-1,1]+(b-pb)*d,dyn[i-1,0]+(b-a)*d);
   dyn[i,0]:=dyn[i,m]+c;
   pb:=b;
 end;
 j:=high(longint);
 For i:=0 to m do
 begin
   j:=min(j,dyn[n,i]);
 end;
 writeln(j);
 readln;
 readln;
end.
