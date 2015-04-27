var n, m, x    :int64;
    i, j       :longint;
    v, next, w :array[0..1600001] of longint;
    d          :array[0..12, -1..500001] of longint;
    b          :boolean;
    head, dis  :array[-1..500001] of longint;

begin
  assign(input, 'graph.in'); reset(input);
  assign(output, 'graph.out'); rewrite(output);
  read(n, m);

    for i:= 1 to m do
    begin
      read(x, v[i], w[i]);
      next[i]:= head[x];
      head[x]:= i;
      v[i+m]:= x;
      next[i + m]:= head[ v[i] ];
      head[ v[i] ]:= i+m;


      if w[i] = 1 then
        begin
        w[i]:= 12;
        w[i + m]:= 12;
        end

      else

      if w[i] = 2 then
        begin
        w[i]:= 6;
        w[i+m]:= 6;
        end

      else

      if w[i] = 3 then
        begin
        w[i]:= 4;
        w[i+m]:= 4;
        end

      else

      if w[i] = 4 then
        begin
        w[i]:= 3;
        w[i+m]:= 3;
        end;


    end;

  dis[1]:= 0;

    for i:= 2 to n do
    dis[i]:= maxlongint;

  fillchar(d, sizeof(d), 0);
  d[0, 0]:= 1;
  d[0, 1]:= 1;

    repeat

        for i:= 0 to 12 do
        begin

          while d[i, -1] < d[i, 0] do
          begin
            inc(d[i, -1]);
            j:= head[  d[ i, d[i, -1] ]  ];

              while j>0 do
              begin

                if dis[ v[j] ] > dis[  d[ i, d[i, -1] ]  ] + w[j] then
                   begin
                     dis[ v[j] ]:= dis[  d[ i, d[i, -1] ]  ] + w[j];
                     inc(d[(dis[ v[j] ]) mod 13, 0]);
                     d[ (dis[ v[j] ] mod 13), d[(dis[ v[j] ]) mod 13, 0] ]:=v[j];
                   end;

                j:= next[j];
              end;

          end;

        end;

      b:= true;

        for i:= 0 to 12 do
          if d[i, -1] < d[i, 0] then
            begin
              b:= false;
              break;
            end;


    until b;

    for i:= 2 to n do
    writeln(dis[i]/12 : 0 : 8);

  close(input);
  close(output);
end.
