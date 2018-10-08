SET SERVEROUTPUT ON;

DECLARE
d_current_date DATE;
BEGIN
d_current_date := SYSDATE;
DBMS_OUTPUT.put_line ('The Date today is: ' || d_current_date);
END;
/