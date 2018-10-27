					DECLARE
					  MARK NUMBER;
					BEGIN
						MARK:=&MARK;
						IF(MARK>=90) THEN
						 DBMS_OUTPUT.PUT_LINE('GRADE OF '|| MARK||' IS O ');
						ELSIF(MARK>=80) THEN
							DBMS_OUTPUT.PUT_LINE('GRADE OF '|| MARK||' IS A ');
						ELSIF(MARK>=70) THEN
							DBMS_OUTPUT.PUT_LINE('GRADE OF '|| MARK||' IS B+ ');
						ELSE
							 DBMS_OUTPUT.PUT_LINE('GRADE OF '|| MARK||' IS F ');
						END IF;
					END;
					/