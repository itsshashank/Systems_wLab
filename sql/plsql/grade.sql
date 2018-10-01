DECLARE
mark NUMBER := &mark;
BEGIN
IF( mark >= 70) THEN 
dbms_output.put_line('Grade A');
ELSIF(mark >= 40 AND mark < 70) THEN
dbms_output.put_line('Grade B'); 
ELSIF(mark >=35 AND mark < 40) THEN
dbms_output.put_line('Grade C');
else 
dbms_output.put_line('Grade F');
END IF;
END;
/