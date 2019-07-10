set linesize 120
set pagesize 30

column cust_name format A15
column description format A25 truncate

TTITLE CENTER 'Customer Analysis for ' _DATE RIGHT 'Page:' FORMAT 999 SQL.PNO SKIP

BREAK ON CUST_NO ON CUST_NAME SKIP 1
COMPUTE SUM LABEL TOTAL OF SUB_TOTAL ON CUST_NO SKIP 1

SELECT      C.cust_no, C.cust_name,
            F.order_no, F.order_date,
            M.description, L.quantity, L.price,
            (L.quantity*L.price) as Sub_Total
FROM        customer C, food_order F, order_list L, menu M
WHERE       C.cust_no = F.cust_no AND
            F.order_no = L.order_no AND
            L.menu_id = M.menu_id
ORDER BY    1, 3;


