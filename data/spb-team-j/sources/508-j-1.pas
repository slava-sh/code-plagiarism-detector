var a:array [1..200000] of longint;
  i,j,minsum,u,sum,n,l,h:int64;
begin
assign(input,'seq.in');
assign(output,'seq.out');
reset(input);
rewrite(output);
read(n,h);
For i:=1 to n do read(a[i]);
sum:=0;
minsum:=40000000001;
For i:=1 to n-h+1 do
   begin  
   for j:=1 to h do 
      begin
      if a[j+i-1]>j then break;
      if j=h then 
         begin
         For l:=1 to h do sum:=sum+l-a[l+i-1];
         u:=1;
         end;
      end;
   if u =1 then if minsum>sum then minsum:=sum;
   sum:=0;
   u:=0;
   end;
if minsum<>40000000001 then writeln(minsum)
                       else writeln(-1);
close(input);
close(output);
end.