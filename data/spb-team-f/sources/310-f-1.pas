program problemF;

var
     i, o: text;
     a, b, NOD, NOK, c, d, j, k, del: int64;

Function GetNOD(a,b: integer): integer;
var c: integer;
begin
 if a>b then 
  begin
   c:=a;
   a:=b;
   b:=c;
  end;
  repeat
  c:= a mod b;
  a:=b;
  b:=c;
 until c=0;
 result:=a;
end;


begin
     assign(i, 'gcm.in');
     assign(o, 'gcm.out');
     reset(i);
     rewrite(o);
     read(i, a);
     read(i, b);
     if a>b then 
     begin
      NOD:=a;
      a:=b;
      b:=NOD;
     end;
     del:=b-a;
     NOD:=GetNOD(a,b);
     NOK:=(a div NOD)*b;
     for j:=a+1 to b-1 do
      for k:=j to b-1 do
      begin
       if GetNOD(j,k)=NOD then
        if ((j div GetNOD(j,k))*k)=NOK then
         if abs(k-j)<del then
         begin
          c:=k;
          d:=j;
         end;
      end;
     if c>d then
     begin
      NOD:=c;
      c:=d;
      d:=NOD;
     end;
     write(o,c,' ',d);
     close(i);
     close(o);
end.