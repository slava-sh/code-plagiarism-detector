program problemC;

type arr1 = array [1..1000,1..2] of int64;
     arr2 = array [1..1000] of int64;

var i, o : text;
    bought, k, j, pay, n : int64;
    input : arr1;
    buy : arr2;

begin
     assign(i,'conquest.in');
     assign(o,'conquest.out');
     reset(i);
     rewrite(o);
          readln(i, n);
          for j:=1 to n do
          begin
               readln(i, input[j, 1], input[j, 2]);
          end;
     close(i);
          bought:=0;
          for j:=n downto 1 do
          begin
               buy[j]:=input[j,1];
               for k:=1 to n do
               begin
                    if k<j then buy[j]:=buy[j]-input[k,1];
                    if k>j then buy[j]:=buy[j]-buy[k];
               end;
               if buy[j]<0 then buy[j]:=0;
               bought:=bought+buy[j];
          end;
          for j:=1 to n do
          begin
               if (input[j,1]-buy[j])>bought then begin
                                                       buy[j]:=buy[j]+ceil((bought+input[j,1]-buy[j])/2);
                                                       bought:=bought+buy[j];
                                                  end;
          end;
          pay:=0;
          for j:=1 to n do pay:=pay+(buy[j]*input[j,2]);
          writeln(o, pay);
     close(o);
end.