var
   i,j,n,m,k,s,t,min,max1,max2,tot,sum,kk:longint;
   ans:array[1..100000,1..3]of longint;
   stack:array[1..100000,1..2]of longint;
   a:array[1..100000]of longint;
   b:array[1..3,1..3]of longint;
procedure aaa(s,t:longint);
var
  i,j,k,p:longint;
begin
   if s<t then
   begin
      i:=s;j:=t;p:=(s+t)shr 1;
      k:=a[p];a[p]:=a[s];
      repeat
         while (i<j)and(a[j]>k) do dec(j);
         if i<j then begin a[i]:=a[j];inc(i); end;
         while (i<j)and(a[i]<k) do inc(i);
         if i<J then begin a[j]:=a[i];dec(j); end;
      until i=j;
      a[i]:=k;aaa(s,i-1);aaa(i+1,t);
   end;
end;
procedure add(p,k:longint);
var
  i,j:longint;
begin
   inc(s);i:=s shr 1;j:=s;
   while i>0 do
      if stack[i,2]<k then
      begin
         stack[j,1]:=stack[i,1];
         stack[j,2]:=stack[i,2];
         j:=i;i:=i shr 1;
      end
      else break;
   stack[j,1]:=p;stack[j,2]:=k;
end;
procedure delete;
var
   i,j,p,k:longint;
begin
   p:=stack[s,1];k:=stack[s,2];
   dec(s);
   j:=1;i:=2;
   while i<=s do
   begin
      if (i<s)and(stack[i+1,2]>stack[i,2]) then inc(i);
      if stack[i,2]>k then
      begin
         stack[j,1]:=stack[i,1];
         stack[j,2]:=stack[i,2];
         j:=i;i:=i shl 1;
      end
      else break;
   end;
   stack[j,1]:=p;stack[j,2]:=k;
end;
begin
   readln(n);
   for i:=1 to n do
      read(a[i]);
   aaa(1,n);
   tot:=1;
   for i:=2 to n do
      if a[i]=a[i-1] then inc(tot)
      else begin
              add(a[i-1],tot);
              tot:=1;
           end;
   add(a[n],tot);
   sum:=0;
   while s>=3 do
   begin
      inc(sum);
      ans[sum,1]:=stack[1,1];
      b[1,1]:=stack[1,1];
      b[1,2]:=stack[1,2];
      delete;
      ans[sum,2]:=stack[1,1];
      b[2,1]:=stack[1,1];
      b[2,2]:=stack[1,2];
      delete;
      ans[sum,3]:=stack[1,1];
      b[3,1]:=stack[1,1];
      b[3,2]:=stack[1,2];
      delete;
      for i:=1 to 3 do
        if b[i,2]>1 then add(b[i,1],b[i,2]-1);
   end;
   writeln(sum);
   for i:=1 to sum do
   begin
      for j:=1 to 2 do
        for k:=j+1 to 3 do
          if ans[i,j]<ans[i,k] then
          begin
             kk:=ans[i,j];
             ans[i,j]:=ans[i,k];
             ans[i,k]:=kk;
          end;
      writeln(ans[i,1],' ',ans[i,2],' ',ans[i,3]);
   end;
end.