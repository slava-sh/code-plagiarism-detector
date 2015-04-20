
type mas1=array[1..1000] of longint;
     mas2=array[1..100] of string;
     mas3=array[1..100] of mas2;

     procedure ddd(var num:string; i:longint);
         begin
            if i=7 then num:=num[1]+num[2]+num[3]+'-'+num[4]+num[5]+'-'+num[6]+num[7];
            if i=6 then num:=num[1]+num[2]+'-'+num[3]+num[4]+'-'+num[5]+num[6];
            if i=5 then num:=num[1]+num[2]+num[3]+'-'+num[4]+num[5];
            if i=4 then num:=num[1]+num[2]+'-'+num[3]+num[4];
            if i=3 then num:=num;
            end;

     function main1(num:string; k:mas1; cd:mas2; n:longint; s:mas3):string;
     var i,t,j:longint; main:string;
         begin
           main:='';
           for i:= 1  to n do
               if pos(cd[i],num)=1 then
                begin
                  main:=main+'+'+cd[i]+'(';
                  t:=i;
                  num:=copy(num,length(cd[i])+1,11-length(cd[i]));
                  break;
                end;
           if main<>'' then
              for j:= 1 to k[t] do
              begin
                if pos(s[t,j],num)=1 then
                 begin
                   main:=main+s[t,j]+')';
                   num:=copy(num,length(s[t,j])+1,length(num)-length(s[t,j]));
                   if num[1]<>'0' then
                    begin
                   ddd(num,length(num));
                   main:=main+num;
                   end
                   else main:='Incorrect';
                   break;
                    end;
              end

             else main:='Incorrect';
             main1:=main;
end;


var c,k:mas1;
    n,m,i,j:longint;
    cd,num:mas2;
    s:mas3;

begin
  assign(input,'numbers.in');
  assign(output,'numbers.out');
  reset(input);
  rewrite(output);

  readln(n);
  for i:=1 to n do
   begin
     readln(c[i],k[i]);
     for j:=1 to k[i] do
       readln(s[i,j]);
   end;
  for i:=1 to n do
   str(c[i],cd[i]);
  readln(m);
  for i:=1 to m do
   begin
  readln(num[i]);
  writeln(main1(num[i],k,cd,n,s));
  end;

end.
