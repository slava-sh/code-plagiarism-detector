const
  maxn=3000;
  maxk=3000;
var
 dyn:array[0..maxn,0..maxk] of int64;
 pb,a,b:int64;
 n,m,c,d:int64;
 i,j:longint;

 function min(a,b:int64):int64;
 begin
   min:=a;
   If ((a>b) and (b>0)) or (a<0) then min:=b;
 end;

begin
 read(n,m,c,d);
 For i:=1 to m do
 begin
   dyn[0,i]:=-1;
 end;
 pb:=0;
 For i:=1 to n do
 begin
   read(a,b);
   For j:=1 to m do
   begin
    dyn[i,j]:=min(dyn[i-1,j-1]+(b-a)*d,dyn[i-1,j]+(b-pb)*d);
   end;
   dyn[i,0]:=dyn[i,m]+c;
   pb:=b;
 end;
 j:=high(int64);
 For i:=1 to m do
 begin
   j:=min(j,dyn[n,i]);
 end;
 writeln(j);
 readln;
 readln;
end.
