var
 a:array[0..150] of string[5];
 b:array[0..150,0..150] of string[5];
 c:array[0..150] of longint;
 n,i,j,k,l,m,q,u,p:longint;
 s,sl,sk,sp:string[15];
procedure er;
begin
writeln('Incorrect');
end;
begin
  Assign(input,'numbers.in');
  Assign(output,'numbers.out');
  ReWrite(output);
  ReSet(input);
  readln(n);
  for i:=1 to n do
   begin
   readln(q,c[i]);
   str(q,sl);
   a[i]:=sl;
   for j:=1 to c[i] do
    readln(b[i][j]);
   end;
  readln(m);
  for u:=1 to m do
   begin
   readln(sl); sp:=sl;
   s:=copy(sl,1,5);
   l:=0;
   for i:=1 to n do
    if pos(a[i],s)=1 then begin
                          if (L=1) then break;
                          p:=length(a[i]);
                          sl:=sp;
                          delete(sl,1,p);
                          sk:=copy(sl,1,5);
                          for j:=1 to c[i] do
                           if pos(b[i][j],sk)=1 then begin
                                                    delete(sl,1,length(b[i][j]));
                                                    p:=length(sl);
                                                    if (sl[1]='0') then break;
                                                    if p=3 then begin
                                                                l:=1;
                                                                writeln('+',a[i],'(',b[i][j],')',sl);
                                                                end;
                                                    if p=4 then begin
                                                                 l:=1;
                                                                writeln('+',a[i],'(',b[i][j],')',copy(sl,1,2),'-',copy(sl,3,2));
                                                                end;
                                                    if p=5 then begin
                                                                 l:=1;
                                                                writeln('+',a[i],'(',b[i][j],')',copy(sl,1,3),'-',copy(sl,4,2));
                                                                end;
                                                    if p=6 then begin
                                                                  l:=1;
                                                                writeln('+',a[i],'(',b[i][j],')',copy(sl,1,2),'-',copy(sl,3,2),'-',copy(sl,5,2));
                                                                end;
                                                    if p=7 then begin
                                                                       l:=1;
                                                                writeln('+',a[i],'(',b[i][j],')',copy(sl,1,3),'-',copy(sl,4,2),'-',copy(sl,6,2));
                                                                end;
                                                    end;

                          end;
    if (l=0) then er;
   end;
end.
