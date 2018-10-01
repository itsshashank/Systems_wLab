DECLARE
    f NUMber := &f;
    s number := &s;
BEGIN
dbms_output.put('-');
FOR a IN f .. s
LOOP
dbms_output.put('-' || a || '-');
END LOOP;
dbms_output.put('-');
dbms_output.new_line;
END;
/