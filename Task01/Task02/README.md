## TASK 2 – Choose the Data Types

### 1. Data Types and Their Uses

- `unsigned short`: Used to store meter readings from 0 to 65535.
- `int`: Used to store electricity units consumed.
- `long`: Used to store the electricity bill in paise.
- `long long`: Used to store the total bills of a large number of households.
- `float` and `double`: Used for decimal calculations, but not preferred for storing money because rounding errors can occur.

### 2. Size and Range

The size of a data type can be checked using `sizeof()` in C.

The limits of integer types can be checked using `limits.h`, and floating-point limits can be checked using `float.h`.

### 3. Why Store Money in Paise?

Money should be stored as integer paise instead of floating-point rupees. This avoids rounding errors during billing.

For example:
- ₹50.00 = 5000 paise
- ₹162.50 = 16250 paise

### 4. Meter Rollover

A 16-bit unsigned meter register can store values from 0 to 65535. After 65535, it rolls over to 0.

For example, if the previous reading is 65400 and the current reading is 120, the consumption is 256 units.
### 5. Float Rounding Example for 4,000 Bills

Floating-point numbers cannot represent every decimal value exactly. Therefore, small rounding errors may occur when many bills are added.

For example, suppose 4,000 bills each contain ₹0.10.

Expected total:

4000 × ₹0.10 = ₹400.00

If the bills are stored and added using floating-point arithmetic, the calculated total may differ slightly from ₹400.00 because of representation and rounding errors.

If the same amount is stored as integer paise, each bill is 10 paise.

4000 × 10 = 40000 paise = ₹400.00

Integer paise gives the exact result for this calculation, provided the integer type does not overflow.
### 7. Alternative Concept: Double Rupees vs Integer Paise

An alternative method is to store money as `double` in rupees instead of storing it as `long` in paise.

**Method 1: Double rupees**

The bill is calculated and stored using decimal rupee values. Since floating-point numbers cannot represent every decimal value exactly, small rounding errors may occur. Rounding should be applied when converting the calculated bill into paise or displaying the final amount, according to the billing rules.

**Method 2: Integer paise**

The bill is stored as an integer number of paise. For example, ₹162.50 is stored as 16250 paise. Addition and subtraction remain exact as long as the integer type does not overflow.

**Time Complexity**

Both methods require O(1) time for each addition. Therefore, adding n bills takes O(n) time in either method.

**Space Complexity**

A `double` typically occupies 8 bytes, while a `long` occupies 4 or 8 bytes depending on the system. The actual sizes can be checked using `sizeof()`.

**Rounding Error Comparison**

When many floating-point values are added, small representation errors can accumulate. The total error depends on the values and the order of calculations; it is not necessarily the same for every set of bills.

Integer paise avoids floating-point representation errors during addition, provided the integer total remains within its permitted range.

**Conclusion**

Integer paise is the preferred method for this billing program because it supports exact monetary arithmetic for amounts expressed in whole paise. `double` may be useful for other calculations, but it requires careful handling of rounding when calculating monetary amounts.


