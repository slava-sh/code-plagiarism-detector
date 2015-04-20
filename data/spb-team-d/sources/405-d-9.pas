var
  a,b,c,m,n,i:integer;
  ans: array [1..100000000] of integer;
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
    i:=a;
    while i<=b do
     begin
      ans[i]:=ans[i]+c;
      i:=i+2;
     end;
     i:=a;
    while i+1<=b do
     begin
      ans[i+1]:=ans[i+1]-c;
      i:=i+2;
     end;
   end;
   readln(input, a);
   writeln(output,ans[a]);
  end;
  close(input);
  close(output);
end.