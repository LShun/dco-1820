/*
-- Documentation

---- food_order TABLE format

Name            Null?    Type
--------------- -------- ------------
ORDER_NO        NOT NULL NUMBER(7)
ORDER_DATE               DATE
CUST_NO                  NUMBER(7)
STAFF_NO                 NUMBER(4)
TOTAL_ITEMS              NUMBER(2)
FOOD_AMOUNT              NUMBER(7,2)
GST                      NUMBER(6,2)
SERVICE_CHARGE           NUMBER(6,2)

CREATE TABLE "FOOD_ORDER" 
   (	"ORDER_NO" NUMBER(7,0) NOT NULL ENABLE, 
	"ORDER_DATE" DATE, 
	"CUST_NO" NUMBER(7,0), 
	"STAFF_NO" NUMBER(4,0), 
	"TOTAL_ITEMS" NUMBER(2,0), 
	"FOOD_AMOUNT" NUMBER(7,2), 
	"GST" NUMBER(6,2), 
	"SERVICE_CHARGE" NUMBER(6,2), 
	 PRIMARY KEY ("ORDER_NO")

---- Syntaxes:

ACC[EPT] user_variable [NUM[BER]|CHAR|DATE] 
       [FOR[MAT] format_specification] 
       [DEF[AULT] default_value] 
       [PROMPT prompt_text|NOPR[OMPT]] 
       [HIDE]
       
PRO[MPT] text_to_be_displayed

-- ENDOF Documentation
*/

-- Script

ALTER SESSION SET NLS_DATE_FORMAT = 'DD/MM/YYYY';

cl scr
PROMPT 'Data entry for FOOD_ORDER table'
PROMPT
PROMPT

ACC var_ORDER_NO            NUM    FORMAT  '9999999'        PROMPT  'Enter the ORDER_NO: ';
ACC var_ORDER_DATE          DATE   FORMAT  'DD/MM/YYYY'     PROMPT  'Enter the ORDER_DATE (DD/MM/YYYY): ';
ACC var_CUST_NO             NUM    FORMAT  '9999999'        PROMPT  'Enter the CUST_NO: ';
ACC var_STAFF_NO            NUM    FORMAT  '9999'           PROMPT  'Enter the STAFF_NO: ';
ACC var_TOTAL_ITEMS         NUM    FORMAT  '99'             PROMPT  'Enter the TOTAL_ITEMS: ';
ACC var_FOOD_AMOUNT         NUM    FORMAT  '9999999.99'     PROMPT  'Enter the FOOD_AMOUNT: ';
ACC var_GST                 NUM    FORMAT  '999999.99'      PROMPT  'Enter the GST: ';
ACC var_SERVICE_CHARGE      NUM    FORMAT  '999999.99'      PROMPT  'Enter the SERVICE_CHARGE: ';

INSERT INTO food_order VALUES
(&var_ORDER_NO, '&var_ORDER_DATE', &var_CUST_NO, 
 &var_STAFF_NO, &var_TOTAL_ITEMS, &var_FOOD_AMOUNT, 
 &var_GST, &var_SERVICE_CHARGE);

-- COMMIT;

-- ENDOF script