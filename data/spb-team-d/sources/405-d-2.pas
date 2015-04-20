var
  a,b,c,m,n,i:int64;
  ans: array [1..2,1..500000000] of shortint;
begin
  assign(input, 'dunes.in');
  assign(output, 'dunes.out');
  read(input,n);
  readln(input,m);
  while m>0 do
  begin
   m:=m-1;
   while(n>0) do
   begin
   n:=n-1;
    read(input, a);
    read(input, b);
    readln(input, c);
    if((a<=500000000)and(b<=500000000))then 
    begin
    i:=a;
    while i<=b do
     begin
      ans[1,i]:=ans[1,i]+c;
      i:=i+2;
     end;
     i:=a;
    while i+1<=b do
     begin
      ans[1,i+1]:=ans[1,i+1]-c;
      i:=i+2;
     end;
     end;
     if(((a>500000000)and(b>500000000)))then 
    begin
    i:=a-500000000;
    while i<=b do
     begin
      ans[2,i]:=ans[2,i]+c;
      i:=i+2;
     end;
     i:=a-500000000;
    while i+1<=b do
     begin
      ans[2,i+1]:=ans[2,i+1]-c;
      i:=i+2;
     end;
     end;
     if((a<=500000000)and(b>=500000000))then
    begin
    i:=a-500000000;
    while i<=500000000 do
     begin
      ans[1,i]:=ans[1,i]+c;
      i:=i+2;
     end;
     i:=a-500000000;
    while i+1<=500000000 do
     begin
      ans[1,i+1]:=ans[1,i+1]-c;
      i:=i+2;
     end;
     i:=500000000;
    while i<=b do
     begin
      ans[2,i]:=ans[2,i]+c;
      i:=i+2;
     end;
     i:=500000000;
    while i+1<=b do
     begin
      ans[2,i+1]:=ans[2,i+1]-c;
      i:=i+2;
     end;
     end;
   end;
   readln(input, a);
   if (a<=500000000)then writeln(output,ans[1,a])
   else writeln(output,ans[2,a-500000000]);
  end;
  close(input);
  close(output);
end.