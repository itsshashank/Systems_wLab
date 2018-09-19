declare
    n number;
    sum number:=0;
    i number;
 
begin
    n:=&n;
 
    for i in 1..n
    loop
        sum:=sum+i;
    end loop;
 
    dbms_output.put_line('sum='||sum);
end;
/