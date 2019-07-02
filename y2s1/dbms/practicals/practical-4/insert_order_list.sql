-- Documentation

/*
Sample from ORACLE Sql*Plus reference:
ACCEPT pswd CHAR PROMPT 'Password: ' HIDE
ACCEPT salary NUMBER FORMAT '999.99' DEFAULT '000.0' -
PROMPT 'Enter weekly salary: '
ACCEPT hired DATE FORMAT 'dd/mm/yyyy' DEFAULT '01/01/2003'-
PROMPT 'Enter date hired: '
ACCEPT lastname CHAR FORMAT 'A20' -
PROMPT 'Enter employee lastname: '
*/

-- script to insert a record into the ORDER_LIST table
/* the customer table structure as a reference
Name     Null?    Type
-------- -------- -----------
ORDER_NO NOT NULL NUMBER(7)
MENU_ID  NOT NULL VARCHAR2(5)
QUANTITY          NUMBER(2)
PRICE             NUMBER(6,2)

*/

-- ENDOF documentation

-- STARTOF program


-- Change default date format to Malaysian date
ALTER SESSION SET NLS_DATE_FORMAT = 'DD/MM/YYYY';

cl scr;
PROMPT 'Data entry for ORDER_LIST table'
PROMPT
PROMPT

-- obtain input information
ACCEPT  v_ORDER_NO     num  FORMAT  '9999999'       PROMPT  'Enter ORDER_NO: ';
ACCEPT  v_MENU_ID      char FORMAT  'A5'            PROMPT  'Enter MENU_ID:  ';
ACCEPT  v_QUANTITY     num  FORMAT  '99'            PROMPT  'Enter QUANTITY: ';
ACCEPT  v_PRICE        num  FORMAT  '999999.99'     PROMPT  'Enter PRICE:    ';

-- insert into table
INSERT INTO ORDER_LIST VALUES
(&v_ORDER_NO, '&v_MENU_ID', &v_QUANTITY, &v_PRICE);

-- Change default date format back to original Oracle format
ALTER SESSION SET NLS_DATE_FORMAT = 'DD-MON-YYYY';


-- ENDOF program

