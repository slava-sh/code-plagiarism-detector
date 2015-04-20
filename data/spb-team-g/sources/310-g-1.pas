program  problemG;

type TArr = array [1..100000] of int64;

var i, o : text;
    n, j, curmaxunbroken, brokennum, brokensum : int64;
    b, cb, toBrake : TArr;

function FindMost(a : tarr) : int64;
var i, j, most : int64;
begin
     most:=0;
     for i:=1 to n do
     begin
          if a[i]>most then begin
                                 most:=a[i];
                                 j:=i;
                            end;
     end;
     FindMost:=j;
end;

function Excist(a : tarr; k : int64) : boolean;
var i : int64;
begin
     for i:=1 to n do
     begin
          if a[i]=k then begin
                              Excist:=true;
                              exit;
                         end;
     end;
     Excist:=false;
end;

function equals(a : tarr) : boolean;
var b : boolean;
    i : int64;
begin
     b:=true;
     for i:=2 to n do
     begin
          if a[i-1]<>a[i] then begin
                                       b:=false;
                                       break;
                                  end;
     end;
     equals:=b;
end;

begin
     assign(i,'merlin.in');
     assign(o,'merlin.out');
     reset(i);
     rewrite(o);
          readln(i, n);
          for j:=1 to n do
          begin
               read(i, b[j]);
          end;
     close(i);
          if equals(b) then writeln(o,0)
                       else begin
                                 for brokennum:=1 to n-1 do
                                 begin
                                      cb:=b;
                                      brokenSum:=0;
                                      for j:=1 to brokennum do
                                      begin
                                           toBrake[j]:=FindMost(cb);
                                           brokenSum:=brokenSum+FindMost(cb);
                                           cb[FindMost(cb)]:=0;
                                      end;
                                      curMaxUnBroken:=cb[FindMost(cb)];
                                      for j:=1 to n-brokenNum do
                                      begin
                                           brokenSum:=brokenSum-curMaxUnBroken+cb[j];
                                           if excist(toBrake,j) then brokenSum:=brokenSum+curMaxUnBroken;
                                      end;
                                      if brokenSum>=0 then begin
                                                                writeln(o,brokenNum);
                                                                break;
                                                           end;
                                 end;
                            end;
     close(o);
end.