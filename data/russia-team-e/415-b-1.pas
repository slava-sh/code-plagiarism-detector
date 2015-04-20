var a:array[0..300000]of longint;
    i,j,k,n,r1,l,r,c:longint;ko,o,p:int64;
begin
assign(input,'che.in'); reset(input);
assign(output,'che.out'); rewrite(output);
readln(n,r1);
for i:=1 to n do read(a[i]);
ko:=0; p:=n;
for i:=1 to n-1 do begin
    a[i-1]:=a[i];
    l:=i; r:=n; c:=(l+r)div 2;
    k:=a[i]+r1;
    o:=n+1;j:=0;
    while l<=r do begin
          if (a[c]>k)and(a[c-1]<=k)then begin o:=c;break;end;
          if a[c]<=k then l:=c+1;
          if a[c]>k then r:=c-1;
          if (l=r)and(j=1)then break;
          if (l=r)and(j=0) then j:=1;
          c:=(l+r)div 2;
          end;
    ko:=ko+(p-o+1);
   end;
writeln(ko);
close(input);
close(output);
end.