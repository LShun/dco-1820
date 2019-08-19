# DBMS T9 - Normalization

## Q1

### 0NF (Unnormalized)

Note, need to draw in table form for diagram, just divide the column

INVOICE(<u>INV_NUM</u>, <u>PROD_NUM</u>, SALE_DATE, PROD_LABEL, VEND_CODE, VEND_NAME, QUANT_SOLD, PROD_PRICE)



### 1NF (Removed Repeating Group)

INVOICE(<u>INV_NUM</u>, SALE_DATE, QUANT_SOLD, <u>PROD_NUM*</u> )

PROD(<u>PROD_NUM</u>, PROD_LABEL, PROD_PRICE, VEND_CODE, VEND_NAME)

#### Problem 1 Solution







### 2NF (Removed Partial Dependency)

INVOICE(<u>INV_NUM</u>, SALE_DATE)

PROD_SOLD(<u>PROD_NUM*</u>, <u>INV_NUM</u>*, QUANT_SOLD)

PROD(<u>PROD_NUM</u>, PROD_LABEL, PROD_PRICE, VEND_CODE, VEND_NAME)



### 3NF (Removed Transitive Dependency)

INVOICE(<u>INV_NUM</u>, SALE_DATE)

PROD_SOLD(<u>PROD_NUM*</u>, <u>INV_NUM</u>*, QUANT_SOLD)

PROD(<u>PROD_NUM</u>, PROD_LABEL, PROD_PRICE, VEND_CODE*)

VENDOR(<u>VEND_CODE</u>, VEND_NAME)



## Q4. Dream Sdn Bhd TourPackages

**Normalize**

**0NF** (Unnormalized)

**TourPackages**(<u>PackageCode</u>, PackageDesc, Price, TourGuide, T_GuideContact, <u>CustNo</u>, CustName, CustPhone, DepartDate)

**1NF** (Remove repeating groups)

**TourPackages**(<u>PackageCode</u>, PackageDesc, Price, TourGuide, T_GuideContact, DepartDate, <u>CustNo*</u>, )

**Customer**(<u>CustNo</u>, CustName, CustPhone)

**2NF** (Remove partial dependency)

**TourPackages**(<u>PackageCode</u>, PackageDesc, Price, TourGuide, T_GuideContact, <u>CustNo*</u>)

**Customer**(<u>CustNo</u>, CustName, CustPhone, DepartDate)

**3NF** (Remove transitive dependency)