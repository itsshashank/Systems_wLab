DECLARE
    f NUMber := &f;
    s number := &s;
BEGIN
dbms_output.put_line('Prgram started.' );
FOR a IN f .. s
LOOP
dbms_output.put_line(a);
END LOOP;
dbms_output.put_line('Program completed.'); 
END;
/