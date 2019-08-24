/*
-- Documentation

---- menu TABLE format

Name            Null?    Type
--------------- -------- ------------
MENU_ID         NOT NULL VARCHAR2(5)
DESCRIPTION     NOT NULL VARCHAR2(30)
PRICE                    NUMBER(6,2)
DATE_INTRODUCED          DATE
CAT_ID                   VARCHAR2(5)
REMARKS                  VARCHAR2(50)



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
PROMPT 'Data entry for MENU table'
PROMPT
PROMPT

ACC var_mid         CHAR    FORMAT  'A5'            PROMPT  'Enter the menu ID: ';
ACC var_desc        CHAR    FORMAT  'A30'           PROMPT  'Enter the menu description: ';
ACC var_price       NUM     FORMAT  '999999.99'     PROMPT  'Enter the price (in ringgit, exclude RM sign): ';
ACC var_introdate   DATE    FORMAT  'DD/MM/YYYY'    PROMPT  'Enter the introduction date (DD/MM/YYYY): ';
ACC var_cat_id      CHAR    FORMAT  'A5'            PROMPT  'Enter the category id: ';
ACC var_remarks     CHAR    FORMAT  'A50'           PROMPT  'Enter the remarks: ';

INSERT INTO menu VALUES
('&var_mid', '&var_desc', &var_price, '&var_introdate', '&var_cat_id', '&var_remarks');

-- COMMIT;

-- ENDOF script