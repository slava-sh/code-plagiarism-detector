program p_1;
var
v:array[1..1000,1..3] of longint;
m, n, i, j, ych, h :longint;
     begin
     assign (input, 'dunes.in');
     assign (output, 'dunes.out');
     reset (input);
     rewrite (output);
     read (n);
     read  (m);
     for i:=1 to n do
     begin
        for j:=1 to 3 do
        begin
                read(v[i,j]);
        end;
        end;
     for i:=1 to m do
     begin
        readln (ych);
        h:=0;
        for j:=1 to n do
        begin
                if (ych>=v[j,1]) and (ych<=v[j,2]) and ((ych-v[j,1]) mod 2 =0) then
                h:=h+v[j,3];
                if (ych>=v[j,1]) and (ych<=v[j,2]) and ((ych-v[j,1]) mod 2 =1) then
                h:=h-v[j, 3];
                end;
        writeln (h);
        end;
        close (input);
        close (output);
     end.

