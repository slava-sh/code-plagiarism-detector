program problemF;

var
     i, o: text;
     a, b, NOD, NOK, c, d, j, k, del: int64;
     f: boolean;

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
     f:=false;
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
     if del=1 then begin write(o,a,' ',b); close(i); close(o); halt; end;
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
          f:= true;
         end;
      end;
     if c>d then
     begin
      NOD:=c;
      c:=d;
      d:=NOD;
     end;
     if f then write(o,c,' ',d)
               else write(o,a,' ',b);
     close(i);
     close(o);
end.