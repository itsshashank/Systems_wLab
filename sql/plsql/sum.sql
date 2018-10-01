DECLARE
    n NUMber ;
    s number := 0;
BEGIN
dbms_output.put_line('Prgram started.' );
n := &n;
FOR a IN 1 .. n
LOOP
s := s+ a;
END LOOP;
dbms_output.put_line('sum=' || s);
dbms_output.put_line('Program completed.'); 
END;
/