program problemB;

//type //TField = array [1..1000, 1..1000] of boolean; 
type TLengths = array [1..1000] of int64;

var i, o : text;
    //a : TField;
    len : TLengths;
    n, j, k : int64;

begin
     assign(i,'chess.in');
     assign(o,'chess.out');
     reset(i);
     rewrite(o);
          k:=0;
          readln(i,n);
          for j:=1 to n do
          begin
               read(i, len[j]);
          end;
     close(i);
          for j:=1 to n do
          begin
               if (len[j]) >= j then inc(k)
                                else break;
          end;
          writeln(o,k);
          for j:=1 to k do
          begin
               write(o, j);
               write(o, ' ');
               writeln(o, j);
          end;
     close(o);
end.