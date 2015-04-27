uses       math;
var        n,res,count,i:longint;
           a:array[0..100001] of longint;
           kq:array[1..3,1..100001] of longint;
procedure  qs(l,h:longint);
var        i,j,tmp,m:longint;
begin
           if l>=h then exit;
           i:=l;j:=h;
           tmp:=a[i+random(j-i+1)];
           repeat
               while a[i]<tmp do inc(i);
               while a[j]>tmp do dec(j);
               if i<=j then
               begin
                    m:=a[i];a[i]:=a[j];a[j]:=m;
                    inc(i);dec(j);
               end;
           until i>j;
           qs(l,j);qs(i,h);
end;
function   find(d:longint):boolean;
var        i,res,count:longint;
begin
           res:=0;
           count:=1;
           for i:=2 to n do
           if a[i]<>a[i-1] then
             begin
                  res:=res+min(count,d);
                  count:=1;
             end else inc(count);
           res:=res+min(count,d);
           exit(res div d>=3);
end;
procedure  xuat;
var        i,t,k,j:longint;
begin
           kq[1,1]:=a[1];
           count:=1;
           t:=1;k:=1;
           for i:=2 to n do
           if a[i]<>a[i-1] then
             begin
                 inc(k);
                 if k>res then
                   begin
                         inc(t);
                         if t>3 then break;
                         k:=1;
                   end;
                 kq[t,k]:=a[i];
                 count:=1;
             end
             else
             begin
                 inc(count);
                 if count<=res then
                   begin
                         inc(k);
                         if k>res then
                         begin
                              inc(t);
                              if t>3 then break;
                              k:=1;
                         end;
                         kq[t,k]:=a[i];
                   end;
             end;
           for i:=1 to res do
           begin
           for j:=3 downto 1 do write(kq[j,i],' ');
           writeln;
           end;
end;
procedure  process;
var        d,c,mid:longint;
begin
           d:=1;
           c:=n;
           res:=0;
           while d<=c do
           begin
                 mid:=(d+c) div 2;
                 if find(mid) then
                   begin
                         reS:=mid;
                         d:=mid+1;
                   end else c:=mid-1;
           end;
           writeln(res);
           if res>0 then xuat;
end;
begin
           readln(n);
           for i:=1 to n do read(a[i]);
           qs(1,n);
           process;
end.
