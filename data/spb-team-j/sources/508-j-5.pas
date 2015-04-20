var a:array [1..200000] of longint;
  i,j,minsum,u,sum,n,h:int64;
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
   u:=1;
   for j:=1 to h do 
      begin
      if a[j+i-1]>j then 
         begin 
         sum:=0;
         u:=0;  
         break; 
         end   
                    else sum:=sum+j-a[j+i-1];
       
      end;
   if u=1 then if minsum>sum then if sum=0 then 
                                           begin
                                           minsum:=sum;
                                           break;
                                           end
                                           else minsum:=sum;   
   sum:=0;
   u:=0;
   end;
if minsum<>40000000001 then writeln(minsum)
                       else writeln(-1);
close(input);
close(output);
end.