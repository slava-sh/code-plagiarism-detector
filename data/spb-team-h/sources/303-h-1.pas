var a:array[1..1000,1..3] of string;
    b:array[1..1000,1..3] of boolean;
    n,i,j,l:longint;
    ch:char;
    k:byte;
    s:string;
procedure change(i,j:longint);
var c:array[1..3]of string;
begin
 c[1]:=a[i,1];
 c[2]:=a[i,2];
 c[3]:=a[i,3];
 a[i,1]:=a[j,1];
 a[i,2]:=a[j,2];
 a[i,3]:=a[j,3];
 a[j,1]:=c[1];
 a[j,2]:=c[2];
 a[j,3]:=c[3];
end;
procedure qsort(l,r:longint);
var sr:longint;i,j:longint;
begin
 sr:=(r+l) div 2;
 j:=r;
 i:=l;
 while i<j do
 begin
  while a[i,1]<a[sr,1] do inc(i);
  while a[j,1]>a[sr,1] do dec(j);
  change(i,j);
 end;
 if (abs(r-l)>1) then begin qsort(sr,r); qsort(l,sr); end;
end;
begin
   assign(input,'names.in');
   assign(output,'names.out');
   reset(input);
   rewrite(output);
   readln(n);
   for i:=1 to n do 
   begin
    readln(a[i,3]);
    for k:=1 to 2 do
    begin
     j:=pos(' ',a[i,3]);
     a[i,k]:=copy(a[i,3],1,j-1);
     delete(a[i,3],1,j);
    end;
    for j:=1 to i-1 do
    begin
      for k:=1 to 3 do
         for l:=1 to 3 do if a[i,k]=a[j,l] then 
         begin
          b[i,k]:=true;
          b[j,l]:=true;
         end;
    end;
   end;
   for i:=1 to n do begin
                       if b[i,3]= false then begin
                                             s:=a[i,3];
                                             a[i,3]:=a[i,2];
                                             a[i,2]:=a[i,1];
                                             a[i,1]:=s;
                                             end;
                                             
                    end;
   qsort(1,n);
   for i:=1 to n do begin
                       write(a[i,1],' ',a[i,2],' ',a[i,3]);
                       writeln;
                    end;
   close(input);
   close(output);
end.